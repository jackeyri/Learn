#include "graph_all.h"  // ����ͼ�Ĵ洢�ṹ�����������㷨

#define MaxSize 100
typedef struct {
    int u;  // �ߵ���ʼ����
    int v;  // �ߵ���ֹ����
    int w;  // �ߵ�Ȩֵ
} Edge;

/**
 * ����ֱ�Ӳ������򷽷���E[0..n-1]��w��������
 * @param E
 * @param n
 */
void InsertSort(Edge E[], int n) {
    int j;
    Edge temp;
    for (int i = 1; i < n; ++i) {
        temp = E[i];
        j = i - 1;  // ����������������E[0..i-1]����E[i]�Ĳ���λ��
        while (j >= 0 && temp.w < E[j].w) {
            E[j + 1] = E[j];  // ���ؼ��ʴ���E[i].w�ļ�¼����
            --j;
        }
        E[j + 1] = temp;  // ��j + 1������E[i]
    }
}

/**
 * ���ÿ�³˹�����㷨���ͼg����С�������������ڽӾ���洢��
 * @param g
 */
void Kruskal(MatGraph g) {
    int i, j, u1, v1, sn1, sn2, k;
    int vset[MAXV];
    Edge E[MaxSize];           // ������б�
    k = 0;                     // E������±��0��ʼ��
    for (i = 0; i < g.n; ++i)  // ��g�����ı߼�E
        for (j = 0; j <= i; ++j)
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                ++k;
            }
    InsertSort(E, g.e);  // ����ֱ�Ӳ��������E���鰴Ȩֵ��������
    for (i = 0; i < g.n; ++i)  // ��ʼ����������
        vset[i] = i;
    k = 1;  // k��ʾ��ǰ�����������ĵڼ����ߣ���ֵΪ1
    j = 0;  // E�бߵ��±꣬��ֵΪ0
    while (k < g.n) {  // ���ɵ�����С��nʱѭ��
        u1 = E[j].u;
        v1 = E[j].v;  // ȡһ���ߵ�ͷβ����
        sn1 = vset[u1];
        sn2 = vset[v1];  // �ֱ�õ��������������ļ��ϱ��
        if (sn1 != sn2) {  // ���������ڲ�ͬ�ļ��ϣ��ñ�����С��������һ����
            printf("(%d, %d)��%d\n", u1, v1, E[j].w);
            ++k;                           // ���ɱ�����1
            for (int i = 0; i < g.n; ++i)  // ��������ͳһ���
                if (vset[i] == sn2)        // ���ϱ��Ϊsn2�ĸ�Ϊsn1
                    vset[i] = sn1;
        }
        ++j;  // ɨ����һ����
    }
}

int main() {
    int u = 3;
    MatGraph g;
    int A[MAXV][MAXV] = {{0, 5,     8,   7, INF, 3},
                         {5, 0,     4, INF, INF, INF},
                         {8, 4,     0,   5, INF, 9},
                         {7,   INF, 5,   0, 5,   6},
                         {INF, INF, INF, 5, 0,   1},
                         {3,   INF, 9,   6, 1,   0}};
    int n = 6, e = 10;
    CreateMat(g, A, n, e);  // ����ͼG���ڽӾ���
    printf("ͼG���ڽӾ���\n");
    DispMat(g);
    printf("��³˹�����㷨�������\n");
    Kruskal(g);
    return 1;
}