#include "graph.cpp"  // 包含图的存储结构

int visited[MAXV];  // 全局数组

/**
 * 输出图G中从顶点u到v的所有简单路径（采用邻接链表存储）
 * @param G
 * @param u
 * @param v
 * @param path
 * @param d 调用时初始值为-1
 */
void SimplePathAll_1(AdjGraph *G, int u, int v, int path[], int d) {
    ArcNode *p;
    int w;
    path[++d] = u;  // 路径长度d增1，将当前顶点添加到路径中
    visited[u] = 1;
    if (u == v && d > 0) {  // 找到终点
        for (int i = 0; i <= d; ++i)
            printf("%3d", path[i]);
        printf("\n");
    }
    p = G->adjlist[u].firstarc;  // p指向顶点u的第一个相邻点
    while (p != nullptr) {
        w = p->adjvex;        // w为u的相邻点编号
        if (visited[w] == 0)  // 若该顶点未标记访问，则递归访问之
            SimplePathAll_1(G, w, v, path, d);
        p = p->nextarc;  // 找u的下一个相邻点
    }
    visited[u] = 0;
}

int main() {
    int u = 5, v = 2;
    int path[MAXV];
    AdjGraph *G;
    int A[MAXV][MAXV] = {{0, 1, 0, 1, 0, 0},
                         {0, 0, 1, 0, 0, 0},
                         {1, 0, 0, 0, 0, 1},
                         {0, 0, 1, 0, 0, 1},
                         {0, 0, 0, 1, 0, 0},
                         {1, 1, 0, 1, 1, 0}};
    int n = 6, e = 10;
    CreateAdj(G, A, n, e);  // 建立如图所示的邻接表
    printf("图G的邻接表：\n");
    DispAdj(G);
    printf("（1）从顶点%d到%d的所有路径：\n", u, v);
    for (int i = 0; i < n; ++i)
        visited[i] = 0;
    SimplePathAll_1(G, u, v, path, -1);
    DestroyAdj(G);
    return 1;
}