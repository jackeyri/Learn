#include <malloc.h>
#include <cstdio>

#define MAX 100    // 最大顶点个数
#define INF 32767  // 定义∞

/**
 * 定义邻接矩阵类型
 */
typedef struct {
    int edges[MAX][MAX];  // 邻接矩阵数组
    int n;                // 顶点数
    int e;                // 边数
} MatGraph;               // 完整的图邻接矩阵类型

/**
 * 定义邻接表类型
 */
typedef struct ANode {
    int adjVex;             // 该边的邻接点编号
    struct ANode *nextArc;  // 指向下一条边的指针
    int weight;             // 该边的相关信息，如权值（用整型表示）
} ArcNode;                  // 边节点类型

/**
 * 定义邻接表类型
 */
typedef struct Vnode {
    ArcNode *firstArc;  // 指向第一条边结点
} VNode;                // 邻接表头结点类型

/**
 * 定义邻接表类型
 */
typedef struct {
    VNode adjList[MAX];  // 邻接表头节点数组
    int n;               // 图中的顶点数
    int e;               // 图中的顶点边数
} AdjGraph;              // 完整的图邻接表类型

/**
 * 创建图的邻接矩阵
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
 * 输出邻接矩阵
 * @param g
 */
void DisplayMat(MatGraph g) {
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j)
            if (g.edges[i][j] != INF)
                printf("%d\t", g.edges[i][j]);
            else
                printf("%s\t", "∞");
        printf("\n");
    }
}

/**
 * 创建图的邻接表
 * @param G
 * @param A
 * @param n
 * @param e
 */
void CreateAdj(AdjGraph *&G, int A[100][100], int n, int e) {
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    for (int i = 0; i < n; ++i)  // 给邻接表中所有头节点的指针域置初值
        G->adjList[i].firstArc = nullptr;
    for (int i = 0; i < n; ++i)  // 检查邻接矩阵中每个元素
        for (int j = n - 1; j >= 0; --j)
            if (A[i][j] != 0 && A[i][j] != INF) {         // 存在一条边
                p = (ArcNode *) malloc(sizeof(ArcNode));  // 创建一个结点p
                p->adjVex = j;
                p->weight = A[i][j];
                p->nextArc = G->adjList[i].firstArc;  // 采用头插法插入节点p
                G->adjList[i].firstArc = p;
            }
    G->n = n;
    G->e = e;
}

/**
 * 输出邻接表
 * @param G
 */
void DisplayAdj(AdjGraph *G) {
    ArcNode *p;
    for (int i = 0; i < G->n; ++i) {
        p = G->adjList[i].firstArc;
        printf("%3d：", i);
        while (p != nullptr) {
            printf("%3d[%d]→", p->adjVex, p->weight);
            p = p->nextArc;
        }
        printf("Λ\n");
    }
}

/**
 * 销毁图的邻接表
 * @param G
 */
void DestroyAdj(AdjGraph *&G) {
    ArcNode *pre, *p;
    for (int i = 0; i < G->n; ++i) {   // 扫描图的邻接表
        pre = G->adjList[i].firstArc;  // p指向第i个单链表的首节点
        if (pre != nullptr) {
            p = pre->nextArc;
            while (p != nullptr) {  // 释放第i个单链表的所有边节点
                free(pre);
                pre = p;
                p = p->nextArc;
            }
            free(pre);
        }
    }
    free(G);  // 释放头节点数组
}