#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct HuffNode {     // 哈夫曼树的结点结构
    unsigned char byte;  // 结点数据
    long long count;    // 权值
    int parent;          // 双亲结点下标
    int leftChild;       // 左孩子下标
    int rightChild;      // 右孩子下标
    char code[256];      // 哈夫曼编码
};

HuffNode huffmanTree[511];  // 哈夫曼树
long long file_length;         // 源文件长度
int bytes_count;  // 频度值大于0的字节的长度（即：哈夫曼树叶子节点个数）
char fileName[128];  // 源文件名称

/**
 * 初始化哈夫曼树和哈夫曼编码的存储结构
 * 利用weights数组初始化哈夫曼树数组，返回频度值大于0的字节数
 */
void initHuffManTree() {
    for (int i = 0; i < 511; i++) {
        huffmanTree[i].count = 0;
        huffmanTree[i].byte = i;
        huffmanTree[i].parent = -1;
        huffmanTree[i].leftChild = -1;
        huffmanTree[i].rightChild = -1;
        huffmanTree[i].code[0] = '\0';
    }
}

/**
 * 统计源文件的字节频度与频度值大于0的字节数bytes_count
 */
void Statistics() {
    printf("请输入源文件名称：");
    scanf("%s", fileName);
    FILE *ifp = fopen(fileName, "rb");  // "rb"是指：打开一个二进制文件，只允许读
    if (ifp == nullptr) {  // 判断文件是否存在
        printf("%s不存在或被占用！\r\n", fileName);
        exit(4);
    }

    unsigned char c;       // 接收读取的每个字节
    file_length = 0;       // 保存文件的字节数，初始为0
    fread(&c, 1, 1, ifp);  // 从文件中读取一个字节到c
    while (!feof(ifp)) {   // 文件没结束
        huffmanTree[c].count++;
        file_length++;         // 字符出现原文件长度+1
        fread(&c, 1, 1, ifp);  // 从文件中读取一个字节到c
    }
    fclose(ifp);

    /**
     * 统计权值大于0的结点个数
     */
    bytes_count = 0;
    for (int i = 0; i < 256; i++) {
        if (huffmanTree[i].count > 0)
            bytes_count++;
    }
}

/**
 * 两个元素的比较
 * @param a
 * @param b
 */
bool compare(HuffNode a, HuffNode b) {
    return a.count > b.count;  // 降序
}

/**
 * 排序
 * @param HT
 * @param i
 */
void sortWeights(HuffNode HT[], int i = 256) {
    sort(HT, HT + i, compare);
}

void creatHuffManTree() {
    int min1, min2;  // weight值最小的两个子树的根结点位置
    int current = bytes_count;  // 何必树的根结点存储位置
    for (int i = 1; i < bytes_count; i++) {  // 经过bytes_count - 1次树的合并
        /**
         * 找出min1和min2
         */
        min1 = current - 1;
        for (int j = current - 1; j >= 0; j--) {
            if (huffmanTree[j].parent == -1 &&
                huffmanTree[j].count <= huffmanTree[min1].count)
                min1 = j;
        }
        min2 = -1;
        for (int j = current - 1; j >= 0; j--) {
            if (min2 == -1) {  // min2未初始化
                if (huffmanTree[j].parent == -1 &&
                    j != min1)  // 初始化min2，避开min1
                    min2 = j;
            } else {  // min2已经初始化
                if (j != min1 && huffmanTree[j].parent == -1 &&
                    huffmanTree[j].count <= huffmanTree[min2].count)
                    min2 = j;
            }
        }

        /**
         * 把min1和min2两个位置上的子树进行合并
         */
        huffmanTree[current].count =
                huffmanTree[min1].count + huffmanTree[min2].count;
        huffmanTree[current].leftChild = min1;
        huffmanTree[current].rightChild = min2;
        huffmanTree[min1].parent = current;
        huffmanTree[min2].parent = current;
        current++;
    }
}

/**
 * 采用“左对齐 + 长度”存储编码
 */
void creatHuffManCode() {
    int root = bytes_count * 2 - 2;
    huffmanTree[root].code[0] = '\0';
    for (int i = root - 1; i >= 0; i--) {
        strcpy(huffmanTree[i].code, huffmanTree[huffmanTree[i].parent].code);
        if (huffmanTree[huffmanTree[i].parent].rightChild ==
            i)  // 若第i个结点，是其双亲的右孩子结点，则在双亲的编码后再接上'i'
            strcat(huffmanTree[i].code, "1");
        else  // 若第i个结点，是其双亲的左孩子结点，则在双亲的编码后再接上'0'
            strcat(huffmanTree[i].code, "0");
        strlen(huffmanTree[i].code);
    }
}

/**
 * 打印输出哈夫曼树及哈夫曼编码
 * 打印哈夫曼树存储结构中0~n-1号结点
 * @param bytes_counts
 */
void printTree(int bytes_counts) {
    printf("哈夫曼树的存储结构如下所示：\n");
    printf("i\tchar\tbyte\tweight\tlChild\trChild\tparent\tcode\n");
    int i;
    for (i = 0; i < bytes_counts; i++) {
        printf("%d\t%c\t%d\t%lld\t%d\t%d\t%d\t%s\n", i,
               (char) huffmanTree[i].byte, (int) huffmanTree[i].byte,
               huffmanTree[i].count, huffmanTree[i].leftChild,
               huffmanTree[i].rightChild, huffmanTree[i].parent,
               huffmanTree[i].code);
    }
    for (i = bytes_counts; i < 2 * bytes_counts - 1; i++) {
        printf("%d\t---\t---\t%lld\t%d\t%d\t%d\t%s\n", i, huffmanTree[i].count,
               huffmanTree[i].leftChild, huffmanTree[i].rightChild,
               huffmanTree[i].parent, huffmanTree[i].code);
    }
}

int main() {
    setbuf(stdout, nullptr);
    initHuffManTree();
    Statistics();  // 统计个字节出现的次数
    sortWeights(huffmanTree, 256);
    creatHuffManTree();
    creatHuffManCode();
    printTree(bytes_count);
    return 0;
}