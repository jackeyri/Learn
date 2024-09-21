#include <cstdio>

#define MaxSize 100     // ��������ϣ����
#define NullKey (-1)    // ����չؼ���ֵ
typedef int KeyType;    // �ؼ�������
typedef char InfoType;  // ����ʱ������
typedef struct {
    KeyType key;    // ��������
    InfoType data;  // ����������
    int count;      // ̽�������
} HashTable;        // ��ϣ��Ԫ������

/**
 * ���ؼ���Ϊk�ļ�¼���뵽��ϣ����
 * @param ha
 * @param n ��¼����
 * @param m ��ϣ��ռ䳤��
 * @param p ��ϣ�����е�p
 * @param k
 */
void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k) {
    int i;
    int adr;
    adr = k % p;
    if (ha[adr].key == NullKey) {  // x[j]����ֱ�ӷ��ڹ�ϣ����
        ha[adr].key = k;
        ha[adr].count = 1;
    } else {    // ������ͻʱ��������̽�ⷨ�����ͻ
        i = 1;  // i��¼x[j]������ͻ�Ĵ���
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
 * ������ϣ��
 * @param ha
 * @param x
 * @param n
 * @param m
 * @param p
 */
void CreateHT(HashTable ha[], KeyType x[], int n, int m, int p) {
    int n1 = 0;
    for (int i = 0; i < m; ++i) {  // ��ϣ���ó�ֵ
        ha[i].key = NullKey;
        ha[i].count = 0;
    }
    for (int i = 0; i < n; ++i) {
        InsertHT(ha, n1, m, p, x[i]);
    }
}

/**
 * �ڹ�ϣ���в��ҹؼ���k
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
        ++i;  // ��������̽�ⷨ����һ����ַ
        adr = (adr + 1) % m;
    }
    if (ha[adr].key == k) {  // ���ҳɹ�
        return adr;
    } else {  // ����ʧ��
        return -1;
    }
}

/**
 * ɾ����ϣ���йؼ���k
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
    if (adr != -1) {  // �ڹ�ϣ�����ҵ��ùؼ���
        ha[adr].key = NullKey;
        --n;  // ��ϣ���ȼ�1
        return 1;
    } else {  // �ڹ�ϣ����δ�ҵ��ùؼ���
        return 0;
    }
}

/**
 * �����ϣ��
 * @param ha
 * @param n
 * @param m
 */
void DisplayHT(HashTable ha[], int n, int m) {
    float avg = 0;
    printf("    ��ϣ���ַ��\t");
    for (int i = 0; i < m; ++i) {
        printf("%d\t", i);
    }
    printf("\n");
    printf("    ��ϣ��ؼ��֣�\t");
    for (int i = 0; i < m; ++i) {
        if (ha[i].key == NullKey) {
            printf("\t");
        } else {
            printf("%d\t", ha[i].key);
        }
    }
    printf("\n");
    printf("    ̽�������\t");
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
    printf("    ƽ�����ҳ���ASL(%d)=%g\n", n, avg);
}

int main() {
    int x[] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
    int n = 11, m = 13, p = 13, i, k = 29;
    HashTable ha[MaxSize];
    printf("��1��������ϣ��\n");
    CreateHT(ha, x, n, m, p);
    printf("��2�������ϣ��\n");
    DisplayHT(ha, n, m);
    printf("��3�����ҹؼ���Ϊ%d�ļ�¼λ��\n", k);
    i = SearchHT(ha, m, p, k);
    if (i != -1) {
        printf("    ha[%d].key=%d\n", i, k);
    } else {
        printf("    ��ʾ��δ�ҵ�%d\n", k);
    }
    // k = 77;
    // printf("��4��ɾ���ؼ���%d\n", k);
    // DeleteHT(ha, m, p, n, k);
    // printf("��5��ɾ����Ĺ�ϣ��\n");
    // DisplayHT(ha, n, m);
    // printf("��6�����ҹؼ���Ϊ%d�ļ�¼λ��\n", k);
    // i = SearchHT(ha, m, p, k);
    // if (i != -1) {
    //     printf("    ha[%d].key=%d\n", i, k);
    // } else {
    //     printf("    ��ʾ��δ�ҵ�%d\n", k);
    // }
    // printf("��7������ؼ���%d\n", k);
    // InsertHT(ha, n, m, p, k);
    // printf("��8�������Ĺ�ϣ��\n");
    // DisplayHT(ha, n, m);
    return 1;
}