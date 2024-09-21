#include <cstdio>

#define MaxSize 100     // 定义最大哈希表长度
#define NullKey (-1)    // 定义空关键字值
typedef int KeyType;    // 关键字类型
typedef char InfoType;  // 其他时间类型
typedef struct {
    KeyType key;    // 其他字域
    InfoType data;  // 其他数据域
    int count;      // 探测次数域
} HashTable;        // 哈希表元素类型

/**
 * 将关键字为k的记录插入到哈希表中
 * @param ha
 * @param n 记录个数
 * @param m 哈希表空间长度
 * @param p 哈希函数中的p
 * @param k
 */
void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k) {
    int i;
    int adr;
    adr = k % p;
    if (ha[adr].key == NullKey) {  // x[j]可以直接放在哈希表中
        ha[adr].key = k;
        ha[adr].count = 1;
    } else {    // 发生冲突时采用线性探测法解决冲突
        i = 1;  // i记录x[j]发生冲突的次树
        do {
            adr = (adr + 1) % m;
            ++i;
        } while (ha[adr].key != NullKey);
        ha[adr].key = k;
        ha[adr].count = i;
    }
    ++n;
}

/**
 * 创建哈希表
 * @param ha
 * @param x
 * @param n
 * @param m
 * @param p
 */
void CreateHT(HashTable ha[], KeyType x[], int n, int m, int p) {
    int n1 = 0;
    for (int i = 0; i < m; ++i) {  // 哈希表置初值
        ha[i].key = NullKey;
        ha[i].count = 0;
    }
    for (int i = 0; i < n; ++i) {
        InsertHT(ha, n1, m, p, x[i]);
    }
}

/**
 * 在哈希表中查找关键字k
 * @param ha
 * @param m
 * @param p
 * @param k
 * @return
 */
int SearchHT(HashTable ha[], int m, int p, KeyType k) {
    int i = 0, adr;
    adr = k % p;
    while (ha[adr].key != NullKey && ha[adr].key != k && i < m) {
        ++i;  // 采用线性探测法找下一个地址
        adr = (adr + 1) % m;
    }
    if (ha[adr].key == k) {  // 查找成功
        return adr;
    } else {  // 查找失败
        return -1;
    }
}

/**
 * 删除哈希表中关键字k
 * @param ha
 * @param m
 * @param p
 * @param n
 * @param k
 * @return
 */
int DeleteHT(HashTable ha[], int m, int p, int &n, int k) {
    int adr;
    adr = SearchHT(ha, m, p, k);
    if (adr != -1) {  // 在哈希表中找到该关键字
        ha[adr].key = NullKey;
        --n;  // 哈希表长度减1
        return 1;
    } else {  // 在哈希表中未找到该关键字
        return 0;
    }
}

/**
 * 输出哈希表
 * @param ha
 * @param n
 * @param m
 */
void DisplayHT(HashTable ha[], int n, int m) {
    float avg = 0;
    printf("    哈希表地址：\t");
    for (int i = 0; i < m; ++i) {
        printf("%d\t", i);
    }
    printf("\n");
    printf("    哈希表关键字：\t");
    for (int i = 0; i < m; ++i) {
        if (ha[i].key == NullKey) {
            printf("\t");
        } else {
            printf("%d\t", ha[i].key);
        }
    }
    printf("\n");
    printf("    探测次数：\t");
    for (int i = 0; i < m; ++i) {
        if (ha[i].key == NullKey) {
            printf("\t");
        } else {
            printf("%d\t", ha[i].count);
        }
    }
    printf("\n");
    for (int i = 0; i < m; ++i) {
        if (ha[i].key != NullKey) {
            avg += (float) ha[i].count;
        }
    }
    avg /= (float) n;
    printf("    平均查找长度ASL(%d)=%g\n", n, avg);
}

int main() {
    int x[] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
    int n = 11, m = 13, p = 13, i, k = 29;
    HashTable ha[MaxSize];
    printf("（1）创建哈希表\n");
    CreateHT(ha, x, n, m, p);
    printf("（2）输出哈希表：\n");
    DisplayHT(ha, n, m);
    printf("（3）查找关键字为%d的记录位置\n", k);
    i = SearchHT(ha, m, p, k);
    if (i != -1) {
        printf("    ha[%d].key=%d\n", i, k);
    } else {
        printf("    提示：未找到%d\n", k);
    }
    // k = 77;
    // printf("（4）删除关键字%d\n", k);
    // DeleteHT(ha, m, p, n, k);
    // printf("（5）删除后的哈希表\n");
    // DisplayHT(ha, n, m);
    // printf("（6）查找关键字为%d的记录位置\n", k);
    // i = SearchHT(ha, m, p, k);
    // if (i != -1) {
    //     printf("    ha[%d].key=%d\n", i, k);
    // } else {
    //     printf("    提示：未找到%d\n", k);
    // }
    // printf("（7）插入关键字%d\n", k);
    // InsertHT(ha, n, m, p, k);
    // printf("（8）插入后的哈希表\n");
    // DisplayHT(ha, n, m);
    return 1;
}