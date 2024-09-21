// 作者：Jackeyri
// 日期：2023-02-26
// 描述：该文件主要是实现读取文件、初始化 Huffman 树、创建 Huffman 树、Huffman 编码、压缩文件、解压缩文件以及菜单工具栏

#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Huffman.h"

/*********************************
函数描述：读取文件并将读取的内容插入到 Huffman 树中
函数名：readFile
返回值：fileSize long型，代表文件长度
参数描述：ifp FILE*型，用来读取文件
*********************************/
long readFile(FILE *ifp) {
    fseek(ifp, 0, SEEK_END);             // 将文件指针移到文件末尾
    long fileSize = ftell(ifp);          // 获取文件长度
    fseek(ifp, 0, SEEK_SET);             // 将文件指针移到文件开头
    unsigned char c;                     // 用于保存读取的字节
    while (fread(&c, 1, 1, ifp) == 1) {  // 读取一个字节并插入到 Huffman 树中
        ++HuffTree[c].count;
    }
    return fileSize;  // 返回文件长度
}

/*********************************
函数描述：初始化 Huffman 树
函数名：initTree
返回值：无返回值
参数描述：无参数
*********************************/
void initTree() {
    for (int i = 0; i < 512; ++i) {
        if (HuffTree[i].count != 0) {           // 前面读取文件是已把 256 种元素出现的频率计算
            HuffTree[i].b = (unsigned char) i;  // 如果有权值，设置叶子结点的字节（符）
        } else {
            HuffTree[i].b = 0;  // 如果没有权值，表示该字符没有在图片中使用
        }
        HuffTree[i].parent = -1;                 // 所有结点的父结点都不存在
        HuffTree[i].lch = HuffTree[i].rch = -1;  // 所有结点的左右的孩子都不存在
    }
}

/*********************************
函数描述：比较函数，用于 qsort 函数
函数名：cmp1
返回值：int型，代表比较的结果
参数描述：a const void*型，用来保存第一个结点的地址
          b const void*型，用来保存第二个结点的地址
*********************************/
int cmp1(const void *a, const void *b) {
    const struct HuffNode *p1 = (const struct HuffNode *) a;
    const struct HuffNode *p2 = (const struct HuffNode *) b;
    return p2->count - p1->count;
}

/*********************************
函数描述：比较函数，用于 qsort 函数
函数名：cmp2
返回值：int型，代表比较的结果
参数描述：a const void*型，用来保存第一个结点的地址
          b const void*型，用来保存第二个结点的地址
*********************************/
int cmp2(const void *a, const void *b) {
    const struct HuffNode *node_a = (const struct HuffNode *) a;
    const struct HuffNode *node_b = (const struct HuffNode *) b;
    return strlen(node_a->bits) - strlen(node_b->bits);
}

/*********************************
函数描述：获取叶子结点的个数
函数名：getLeafNum
返回值：int型，代表叶子结点的个数
参数描述：无参数
*********************************/
int getLeafNum() {
    qsort(HuffTree, 256, sizeof(struct HuffNode), cmp1);  // 对叶子结点按权值从大到小排序
    for (int i = 0; i < 256; i++) {
        if (HuffTree[i].count == 0) {  // 如果该结点的权值为 0，说明后面的结点都没有权值，返回叶子结点的个数
            return i;
        }
    }
    return 256;  // 如果没有返回，说明叶子结点的个数为 256
}

/*********************************
函数描述：找到权值最小的结点
函数名：findMin
返回值：通过指针传参，无返回值
参数描述：n int型，代表 Huffman 树中结点的个数
          pt1 int*型，用来保存权值最小的结点的下标
          min int*型，用来保存权值最小的结点的权值
*********************************/
void findMin(int n, int *pt1, int *min) {
    *min = 0x7FFFFFFF;
    for (int i = 0; i < n; ++i) {
        if (HuffTree[i].parent != -1) {  // 如果该结点已经有父结点，跳过
            continue;
        }
        if (*min > HuffTree[i].count) {  // 如果该结点的权值小于 min，更新 min
            *pt1 = i;
            *min = HuffTree[i].count;
            continue;
        }
    }
}

/*********************************
函数描述：创建 Huffman 树
函数名：createTree
返回值：无返回值
参数描述：n int型，代表 Huffman 树中结点的个数
          m int型，代表 Huffman 树中叶子结点的个数
*********************************/
void createTree(int n, int m) {
    for (int i = n; i < m; ++i) {  // 从第 n 个结点开始，创建 Huffman 树
        int pt1, pt2, min1, min2;  // pt1, pt2 用来保存权值最小的两个结点的下标
        findMin(i, &pt1, &min1);   // 找到权值最小的结点
        HuffTree[i].count = min1;  // 设置权值
        HuffTree[pt1].parent = i;  // 设置父结点
        HuffTree[i].lch = pt1;     // 设置左孩子
        findMin(i, &pt2, &min2);   // 找到权值次小的结点
        HuffTree[i].count += min2;
        HuffTree[pt2].parent = i;
        HuffTree[i].rch = pt2;
    }
}

/*********************************
函数描述：Huffman 编码
函数名：encode
返回值：无返回值
参数描述：n int型，代表 Huffman 树中叶子结点的个数
*********************************/
void encode(int n) {
    int i, j, f, lch, rch, parent;
    for (i = 0; i < n; ++i) {
        f = i;
        HuffTree[i].bits[0] = 0;
        parent = HuffTree[f].parent;
        lch = HuffTree[parent].lch;  // 获取左右子结点和父结点
        rch = HuffTree[parent].rch;
        while (parent != -1) {
            if (lch == f) {  // 判断当前结点与父结点的关系
                j = strlen(HuffTree[i].bits);
                memmove(HuffTree[i].bits + 1, HuffTree[i].bits, j + 1);
                HuffTree[i].bits[0] = '0';
            } else if (rch == f) {  // 置右分支编码为 '1'
                j = strlen(HuffTree[i].bits);
                memmove(HuffTree[i].bits + 1, HuffTree[i].bits, j + 1);
                HuffTree[i].bits[0] = '1';
            }
            f = parent;  // 更新结点
            parent = HuffTree[f].parent;
            lch = HuffTree[parent].lch;
            rch = HuffTree[parent].rch;
        }
    }
}

/*********************************
函数描述：压缩文件
函数名：compress
返回值：double型，代表压缩率
参数描述：ifp FILE*型，代表待压缩文件的文件指针
          ofp FILE*型，代表压缩文件的文件指针
          n int型，代表 Huffman 树中叶子结点的个数
          fileSize long型，代表待压缩文件的长度
*********************************/
double compress(FILE *ifp, FILE *ofp, int n, long fileSize) {
    fseek(ifp, 0, SEEK_SET);                 // SEEK_SET 指文件头，将文件指针指向待压缩文件的开始位置
    fwrite(&fileSize, sizeof(int), 1, ofp);  // 在压缩文件头写入文件的总长度，占 4 个字节
    fseek(ofp, 8, SEEK_SET);                 // 重定位压缩文件指针，从头偏移 8 个字节，留出空间写其它信息，并为写入 Huffman 编码准备

    unsigned char c;  // 用于存储单个字符
    char buf[512];    // 定义缓冲区，保存字节的 Huffman 编码
    buf[0] = '\0';    // 初始为空字符串
    long j = 0;       // 统计缓冲区中的字符个数
    long f = 0;       // 统计字符个数，可判断文件是否读完
    long pt1 = 8;     // 统计文件的长度，Huffman 编码从第 8 个字节开始写入

    // 预先计算所有字符对应的 Huffman 编码
    char huffCodes[256][256];  // 最多有 256 种字符
    for (int i = 0; i < n; ++i) {
        strcpy(huffCodes[HuffTree[i].b], HuffTree[i].bits);
    }

    // 读取原文件
    while (!feof(ifp)) {
        // 从文件中读取一个字符，读取一个字节后，光标位置后移一个字节
        c = fgetc(ifp);
        ++f;
        // 直接取出该字符的 Huffman 编码
        strcpy(buf + strlen(buf), huffCodes[c]);

        // 若长度大于 8 ，进行拆分写入，若小于 8 ，则继续取下一个字符的 Huffman 码凑一个字节，凑满写入
        j = strlen(buf);  // 统计该字符编码的长度
        while (j >= 8) {  // 若当前编码的长度大于等于 8 ，则要进行拆分，分两个字节存，如 1100101010 拆分成 11001010，10
            c = 0;
            for (int i = 0; i < 8; ++i) {  // 把 buf 中的前 8 个字符转换成一个字节
                if (buf[i] == '1') {
                    c = (c << 1) | 1;
                } else {
                    c = c << 1;
                }
            }
            fwrite(&c, 1, 1, ofp);  // 把凑好的一个字节编码写入文件，写入文件 ofp
            ++pt1;                  // 统计压缩后文件的长度，字节数加 1
            strcpy(buf, buf + 8);   // 把 buf 后一个字节起的所有内容复制到 buf 中，即一个字节一个字节取
            j = strlen(buf);
        }
        if (f == fileSize) {  // 若原文件所有的字符取完，结束
            break;
        }
    }

    if (j > 0) {  // 若最后一个字符的 Huffman 编码不足 8 位，用 0 补齐
        strcat(buf, "00000000");
        for (int i = 0; i < 8; ++i) {
            if (buf[i] == '1') {
                c = (c << 1) | 1;
            } else {
                c = c << 1;
            }
        }
        fwrite(&c, 1, 1, ofp);  // 把最后一个字节写入文件中
        ++pt1;
    }

    fseek(ofp, 4, SEEK_SET);             // 移动文件指针位置到第 4 个字节
    fwrite(&pt1, sizeof(long), 1, ofp);  // 写入统计压缩文件的长度，4 个字节
    fseek(ofp, pt1, SEEK_SET);           // 移动文件指针到压缩后文件尾
    fwrite(&n, sizeof(long), 1, ofp);    // 写入结点数目，即总的不同字节的个数

    for (int i = 0; i < n; ++i) {
        fwrite(&(HuffTree[i].b), 1, 1, ofp);  // 写入每个结点的代表的字符
        c = strlen(HuffTree[i].bits);
        fwrite(&c, 1, 1, ofp);                  // 写入每个字符 Huffman 码的长度
        j = strlen(HuffTree[i].bits);           // 统计 Huffman 长度
        if (j % 8 != 0) {                       // 若存储的位数不是 8 的倍数，则补 0
            for (f = j % 8; f < 8; ++f) {       // 比如 9
                strcat(HuffTree[i].bits, "0");  // 011 00000     01010101 10000000
            }
        }
        /* 将 Huffman 编码字符串变成二进制数 */
        while (HuffTree[i].bits[0] != 0) {  // 检查是否到了字符串末尾
            c = 0;
            for (j = 0; j < 8; ++j) {  // 字符的有效存储不超过 8 位，则对有效位数左移实现补 0
                if (HuffTree[i].bits[j] == '1') {
                    c = (c << 1) | 1;
                } else {
                    c = c << 1;
                }
            }
            strcpy(HuffTree[i].bits, HuffTree[i].bits + 8);  // 继续转换后面的字符串
            fwrite(&c, 1, 1, ofp);
        }
    }

    long length = ftell(ofp);  // 压缩后文件的总长度
    fclose(ifp);               // 关闭文件
    fclose(ofp);
    return 1 - (double) length / (double) fileSize;  // 文件的压缩率
}

/*********************************
函数描述：解压缩文件
函数名：uncompress
返回值：成功返回 ture，失败返回 false
参数：ifp FILE*型，代表压缩文件的文件指针
      ofp FILE*型，代表解压缩后的文件指针
*********************************/
bool uncompress(FILE *ifp, FILE *ofp) {
    char bx[255];     // 用于缓存写入文件数据
    unsigned char c;  // 用于存储单个字符
    long f;           // 用于统计字符个数
    long p;           // 用于保存结点的编码长度
    long fileLength;  // 用于存储文件大小
    int n, m;         // 用于存储结点数目

    fread(&fileLength, sizeof(long), 1, ifp);  // 读取未压缩时原文件长度
    fread(&f, sizeof(long), 1, ifp);           // 读取压缩文件的长度，位于第 4 个字节处
    fseek(ifp, f, SEEK_SET);                   // 将文件指针定位到存储结点总数的位置
    fread(&n, sizeof(long), 1, ifp);           // 读取结点数

    for (int i = 0; i < n; ++i) {
        fread(&HuffTree[i].b, 1, 1, ifp);
        fread(&c, 1, 1, ifp);
        HuffTree[i].count = (long) c;
        HuffTree[i].bits[0] = 0;

        // 只进行一次除法运算，用位运算替代取整操作
        m = (HuffTree[i].count + 7) >> 3;

        // 将常量计算移至循环外部
        const char *const zero_pad = "00000000";
        const int max_pad_length = 8;

        for (int j = 0; j < m; ++j) {
            fread(&c, 1, 1, ifp);
            f = (unsigned char) c;

            // 使用位运算实现十六进制转二进制，取代 itoa 函数
            for (int l = 7; l >= 0; --l) {
                HuffTree[i].bits[j * 8 + 7 - l] = ((f >> l) & 1) + '0';
            }

            // 在 Huffman 树结点编码补 0，取代使用 strcat 函数
            int num_pad = max_pad_length - strlen(HuffTree[i].bits + j * 8);
            if (num_pad > 0) {
                memcpy(HuffTree[i].bits + j * 8 + strlen(HuffTree[i].bits + j * 8), zero_pad, num_pad);
            }
        }
        HuffTree[i].bits[HuffTree[i].count] = 0;
    }

    // 根据 Huffman 编码的长短，对结点进行排序，编码短的在前面
    qsort(HuffTree, n, sizeof(struct HuffNode), cmp2);
    p = strlen(HuffTree[n - 1].bits);  // 编码的最大长度

    fseek(ifp, 8, SEEK_SET);  // 定位文件指针至原文件 Huffman 编码的位置
    m = 0;
    bx[0] = 0;                                // 每次处理的编码的字符串
    unsigned int bx_len = 0;                  // 记录当前 bx 的长度
    unsigned char buf[256];                   // 存储二进制字符串的缓冲区，大小为最长可能的编码长度（256位）
    int i, l;                                 // 循环计数器
    while (true) {                            // 通过 Huffman 编码的长短，依次解码，从原来的位存储还原到字节存储
        while (bx_len < p) {                  // bx 保存最长编码的 01 串，有可能是一个字符，也有可能是多个字符
            if (fread(&c, 1, 1, ifp) != 1) {  // 读取失败，可能已到达文件结尾
                break;
            }
            itoa(c, buf, 2);  // 转换成二进制 01
            l = strlen(buf);
            for (i = 8; i > l; --i) {  // 在单字节内对应位置补 0
                strcat(bx, "0");
            }
            strcat(bx, buf);
            bx_len += 8;  // 更新 bx 的长度
        }

        if (bx_len < p) {  // 如果读取失败，跳出循环
            break;
        }

        for (i = 0; i < n; ++i) {
            if (memcmp(HuffTree[i].bits, bx, HuffTree[i].count) == 0) {  // 找到编码
                break;
            }
        }
        /* 比较成功后，需继续往后判断 bx 对应的其他字符 */
        bx_len -= HuffTree[i].count;                      // 更新 bx 的长度
        memmove(bx, bx + HuffTree[i].count, bx_len + 1);  // 将 bx 的内容移动到开头，为下一次处理做准备
        c = HuffTree[i].b;                                // 得到匹配后的 Huffman 编码对应的字段
        fwrite(&c, 1, 1, ofp);                            // 将得到的字符写入目标文件
        ++m;                                              // 继续比较，统计解压缩后文件的长度
        if (m == fileLength) {
            fclose(ifp);
            fclose(ofp);
            return m == fileLength;  // 对解压缩后文件和原文件比较相同性比较进行判断(根据文件大小）
        }
    }

    fclose(ifp);
    fclose(ofp);
    return false;
}

/*********************************
函数描述：主函数，显示菜单工具栏、对用户输入进行容错处理以及根据用户的选择执行相应的压缩或解压缩操作
函数名称：main
返回值：无返回值
参数描述：无参数
*********************************/
int main() {
    int option;
    while (true) {
        printf("\t_________________________________________________\n"
               "\n"
               "\t              * 压缩、解压缩 小工具 *\n"
               "\t_________________________________________________\n"
               "\t_________________________________________________\n"
               "\t|                                               |\n"
               "\t| 1.压缩                                        |\n"
               "\t| 2.解压缩                                      |\n"
               "\t| 0.退出                                        |\n"
               "\t|                                               |\n"
               "\t_________________________________________________\n"
               "\n"
               "\t                  说明：（1）采用 Huffman 编码\n"
               "\t                        （2）适用于字符型文本文件\n\n");

        do {  // 对用户输入进行容错处理
            printf("\n\t*请选择相应功能(0-2)：");
            option = getch();
            printf("%c\n", option);
            if (option != '0' && option != '1' && option != '2') {
                printf("\t@_@请检查您输入的数字在0~2之间！\n"
                       "\t请再输入一遍！");
            }
        } while (option != '0' && option != '1' && option != '2');

        char filename[255];  // 文件名
        FILE *ifp, *ofp;    // ifp 指向原文件，ofp 指向压缩后的文件
        if (option == '1') {
            printf("\t请您输入需要压缩的文件的路径包括扩展名：");
            gets(filename);  // 获取文件路径

            ifp = fopen(filename, "rb");  // 以二进制方式打开文件
            if (ifp == NULL) {            // 判断文件是否存在
                printf("\n\t%s不存在或被占用！\r\n", filename);
            } else {
                printf("\t在当前目录压缩，请您输入压缩后的文件名，不需要扩展名：");
                gets(filename);
                strcat(filename, ".huf");
                ofp = fopen(filename, "wb");
                if (ofp == NULL) {
                    printf("\n\t%s不存在或被占用！\r\n", filename);
                    fclose(ifp);
                } else {                 // 压缩文件
                    int n;               // n 为叶子结点个数
                    int m;               // m 为 Huffman 树结点个数
                    long fileSize;       // 文件长度
                    clock_t start, end;  // 计时器

                    printf("\n\t正在帮您压缩...");
                    start = clock();
                    fileSize = readFile(ifp);  // 统计权值
                    initTree();                // 初始化 Huffman 树
                    n = getLeafNum();          // 获取叶子结点个数
                    m = 2 * n - 1;
                    createTree(n, m);  // 创建 Huffman 树
                    encode(n);         // Huffman 编码
                    printf("\n\t压缩文件成功！\n"
                           "\t压缩率为：%f%%\n", compress(ifp, ofp, n, fileSize) * 100);
                    end = clock();
                    printf("\t压缩耗费时间：%f秒\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
                }
            }
        } else if (option == '2') {
            printf("\t请您输入需要解压缩的文件名路径，不需要后缀：");
            gets(filename);
            strcat(filename, ".huf");

            ifp = fopen(filename, "rb");
            if (ifp == NULL) {
                printf("\n\t%s不存在或被占用！\r\n", filename);
            } else {
                printf("\t将在当前目录下解压缩，请您输入解压缩后的文件名包括扩展名：");
                gets(filename);
                ofp = fopen(filename, "wb");
                if (ofp == NULL) {
                    printf("\n\t%s不存在或被占用！\r\n", filename);
                    fclose(ifp);
                } else {                 // 解压缩文件
                    clock_t start, end;  // 计时器

                    start = clock();
                    printf("\n\t正在帮您解压缩...");
                    if (uncompress(ifp, ofp)) {
                        printf("\n\t解压缩文件成功！\n"
                               "\t解压缩文件与原文件相同！\n");
                    } else {
                        printf("\n\t解压缩文件失败！\n"
                               "\t解压缩文件与原文件不同！\n");
                    }
                    end = clock();
                    printf("\t解压缩耗费时间：%f秒\n\n", ((double) (end - start)) / CLOCKS_PER_SEC);
                }
            }
        } else {
            printf("\t欢迎您再次使用本工具^_^\n");
            exit(0);  // 退出该工具
        }

        system("pause");  // 任意键继续
        system("cls");    // 清屏
    }
}
