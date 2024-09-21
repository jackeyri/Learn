#include <malloc.h>
#include <cstdio>

#define MAX 100    // ��󶥵����
#define INF 32767  // �����

/**
 * �����ڽӾ�������
 */
typedef struct {
    int edges[MAX][MAX];  // �ڽӾ�������
    int n;                // ������
    int e;                // ����
} MatGraph;               // ������ͼ�ڽӾ�������

/**
 * �����ڽӱ�����
 */
typedef struct ANode {
    int adjVex;             // �ñߵ��ڽӵ���
    struct ANode *nextArc;  // ָ����һ���ߵ�ָ��
    int weight;             // �ñߵ������Ϣ����Ȩֵ�������ͱ�ʾ��
} ArcNode;                  // �߽ڵ�����

/**
 * �����ڽӱ�����
 */
typedef struct Vnode {
    ArcNode *firstArc;  // ָ���һ���߽��
} VNode;                // �ڽӱ�ͷ�������

/**
 * �����ڽӱ�����
 */
typedef struct {
    VNode adjList[MAX];  // �ڽӱ�ͷ�ڵ�����
    int n;               // ͼ�еĶ�����
    int e;               // ͼ�еĶ������
} AdjGraph;              // ������ͼ�ڽӱ�����

/**
 * ����ͼ���ڽӾ���
 * @param g
 * @param A
 * @param n
 * @param e
 */
void CreateMat(MatGraph &g, int A[100][100], int n, int e) {
    g.n = n;
    g.e = e;
    for (int i = 0; i < g.n; ++i)
        for (int j = 0; j < g.n; ++j)
            g.edges[i][j] = A[i][j];
}

/**
 * ����ڽӾ���
 * @param g
 */
void DisplayMat(MatGraph g) {
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j)
            if (g.edges[i][j] != INF)
                printf("%d\t", g.edges[i][j]);
            else
                printf("%s\t", "��");
        printf("\n");
    }
}

/**
 * ����ͼ���ڽӱ�
 * @param G
 * @param A
 * @param n
 * @param e
 */
void CreateAdj(AdjGraph *&G, int A[100][100], int n, int e) {
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    for (int i = 0; i < n; ++i)  // ���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
        G->adjList[i].firstArc = nullptr;
    for (int i = 0; i < n; ++i)  // ����ڽӾ�����ÿ��Ԫ��
        for (int j = n - 1; j >= 0; --j)
            if (A[i][j] != 0 && A[i][j] != INF) {         // ����һ����
                p = (ArcNode *) malloc(sizeof(ArcNode));  // ����һ�����p
                p->adjVex = j;
                p->weight = A[i][j];
                p->nextArc = G->adjList[i].firstArc;  // ����ͷ�巨����ڵ�p
                G->adjList[i].firstArc = p;
            }
    G->n = n;
    G->e = e;
}

/**
 * ����ڽӱ�
 * @param G
 */
void DisplayAdj(AdjGraph *G) {
    ArcNode *p;
    for (int i = 0; i < G->n; ++i) {
        p = G->adjList[i].firstArc;
        printf("%3d��", i);
        while (p != nullptr) {
            printf("%3d[%d]��", p->adjVex, p->weight);
            p = p->nextArc;
        }
        printf("��\n");
    }
}

/**
 * ����ͼ���ڽӱ�
 * @param G
 */
void DestroyAdj(AdjGraph *&G) {
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; ++i) {   // ɨ��ͼ���ڽӱ�
        pre = G->adjList[i].firstArc;  // pָ���i����������׽ڵ�
        if (pre != nullptr) {
            p = pre->nextArc;
            while (p != nullptr) {  // �ͷŵ�i������������б߽ڵ�
                free(pre);
                pre = p;
                p = p->nextArc;
            }
            free(pre);
        }
    }
    free(G);  // �ͷ�ͷ�ڵ�����
}