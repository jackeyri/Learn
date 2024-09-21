#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

struct HuffNode {     // ���������Ľ��ṹ
    unsigned char byte;  // �������
    long long count;    // Ȩֵ
    int parent;          // ˫�׽���±�
    int leftChild;       // �����±�
    int rightChild;      // �Һ����±�
    char code[256];      // ����������
};

HuffNode huffmanTree[511];  // ��������
long long file_length;         // Դ�ļ�����
int bytes_count;  // Ƶ��ֵ����0���ֽڵĳ��ȣ�������������Ҷ�ӽڵ������
char fileName[128];  // Դ�ļ�����

/**
 * ��ʼ�����������͹���������Ĵ洢�ṹ
 * ����weights�����ʼ�������������飬����Ƶ��ֵ����0���ֽ���
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
 * ͳ��Դ�ļ����ֽ�Ƶ����Ƶ��ֵ����0���ֽ���bytes_count
 */
void Statistics() {
    printf("������Դ�ļ����ƣ�");
    scanf("%s", fileName);
    FILE *ifp = fopen(fileName, "rb");  // "rb"��ָ����һ���������ļ���ֻ�����
    if (ifp == nullptr) {  // �ж��ļ��Ƿ����
        printf("%s�����ڻ�ռ�ã�\r\n", fileName);
        exit(4);
    }

    unsigned char c;       // ���ն�ȡ��ÿ���ֽ�
    file_length = 0;       // �����ļ����ֽ�������ʼΪ0
    fread(&c, 1, 1, ifp);  // ���ļ��ж�ȡһ���ֽڵ�c
    while (!feof(ifp)) {   // �ļ�û����
        huffmanTree[c].count++;
        file_length++;         // �ַ�����ԭ�ļ�����+1
        fread(&c, 1, 1, ifp);  // ���ļ��ж�ȡһ���ֽڵ�c
    }
    fclose(ifp);

    /**
     * ͳ��Ȩֵ����0�Ľ�����
     */
    bytes_count = 0;
    for (int i = 0; i < 256; i++) {
        if (huffmanTree[i].count > 0)
            bytes_count++;
    }
}

/**
 * ����Ԫ�صıȽ�
 * @param a
 * @param b
 */
bool compare(HuffNode a, HuffNode b) {
    return a.count > b.count;  // ����
}

/**
 * ����
 * @param HT
 * @param i
 */
void sortWeights(HuffNode HT[], int i = 256) {
    sort(HT, HT + i, compare);
}

void creatHuffManTree() {
    int min1, min2;  // weightֵ��С�����������ĸ����λ��
    int current = bytes_count;  // �α����ĸ����洢λ��
    for (int i = 1; i < bytes_count; i++) {  // ����bytes_count - 1�����ĺϲ�
        /**
         * �ҳ�min1��min2
         */
        min1 = current - 1;
        for (int j = current - 1; j >= 0; j--) {
            if (huffmanTree[j].parent == -1 &&
                huffmanTree[j].count <= huffmanTree[min1].count)
                min1 = j;
        }
        min2 = -1;
        for (int j = current - 1; j >= 0; j--) {
            if (min2 == -1) {  // min2δ��ʼ��
                if (huffmanTree[j].parent == -1 &&
                    j != min1)  // ��ʼ��min2���ܿ�min1
                    min2 = j;
            } else {  // min2�Ѿ���ʼ��
                if (j != min1 && huffmanTree[j].parent == -1 &&
                    huffmanTree[j].count <= huffmanTree[min2].count)
                    min2 = j;
            }
        }

        /**
         * ��min1��min2����λ���ϵ��������кϲ�
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
 * ���á������ + ���ȡ��洢����
 */
void creatHuffManCode() {
    int root = bytes_count * 2 - 2;
    huffmanTree[root].code[0] = '\0';
    for (int i = root - 1; i >= 0; i--) {
        strcpy(huffmanTree[i].code, huffmanTree[huffmanTree[i].parent].code);
        if (huffmanTree[huffmanTree[i].parent].rightChild ==
            i)  // ����i����㣬����˫�׵��Һ��ӽ�㣬����˫�׵ı�����ٽ���'i'
            strcat(huffmanTree[i].code, "1");
        else  // ����i����㣬����˫�׵����ӽ�㣬����˫�׵ı�����ٽ���'0'
            strcat(huffmanTree[i].code, "0");
        strlen(huffmanTree[i].code);
    }
}

/**
 * ��ӡ�����������������������
 * ��ӡ���������洢�ṹ��0~n-1�Ž��
 * @param bytes_counts
 */
void printTree(int bytes_counts) {
    printf("���������Ĵ洢�ṹ������ʾ��\n");
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
    Statistics();  // ͳ�Ƹ��ֽڳ��ֵĴ���
    sortWeights(huffmanTree, 256);
    creatHuffManTree();
    creatHuffManCode();
    printTree(bytes_count);
    return 0;
}