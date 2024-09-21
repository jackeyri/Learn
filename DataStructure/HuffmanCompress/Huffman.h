// 作者：Jackeyri
// 日期：2023-02-26
// 描述：该文件主要是结构的定义及函数的声明

struct HuffNode {
    unsigned char b;  // 字节值
    long count;       // 字节出现频率（权值）
    long parent;      // 结点对应的父亲结点下标
    long lch, rch;    // 结点对应的左孩子下标、右孩子下标
    char bits[256];   // 结点对应的哈夫曼编码数组
} HuffTree[512];

long readFile(FILE* ifp);

void initTree();

int cmp1(const void* a, const void* b);

int cmp2(const void* a, const void* b);

int getLeafNum();

void findMin(int n, int* pt1, int* min);

void createTree(int n, int m);

void encode(int n);

double compress(FILE* ifp, FILE* ofp, int n, long fileSize);

bool uncompress(FILE* ifp, FILE* ofp);

int main();
