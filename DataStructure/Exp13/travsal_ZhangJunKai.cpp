#include "graph_ZhangJunKai.h"  // 包含图的存储结构及基本运算算法

int visited[MAX];  // 全局数组

/**
 * 递归深度优先遍历算法
 * @param G
 * @param v
 */
void DFS(AdjGraph *G, int v) {
    ArcNode *p;
    visited[v] = 1;              // 置已访问标记
    printf("%3d", v);            // 输出被访问顶点的编号
    p = G->adjList[v].firstArc;  // p指向顶点v的第一条弧的弧头结点
    while (p != nullptr) {
        if (visited[p->adjVex] == 0)  // 若p->adjVex顶点未访问递归访问它
            DFS(G, p->adjVex);
        p = p->nextArc;  // p指向顶点v的下一条弧的弧头结点
    }
}

/**
 * 非递归深度优先遍历算法
 * @param G
 * @param v
 */
void DFS1(AdjGraph *G, int v) {
    ArcNode *p;
    int St[MAX];
    int top = -1, w, x;
    for (int i = 0; i < G->n; ++i)
        visited[i] = 0;  // 顶点访问标志均置成0
    printf("%3d", v);    // 访问顶点v
    visited[v] = 1;      // 置顶点v已访问
    top++;
    St[top] = v;                     // 将顶点v进栈
    while (top > -1) {               // 栈不空循环
        x = St[top];                 // 取栈顶顶点x作为当前顶点
        p = G->adjList[x].firstArc;  // 找顶点x的第一个相邻点
        while (p != nullptr) {
            w = p->adjVex;          // x的相邻点为w
            if (visited[w] == 0) {  // 若顶点w没有访问
                printf("%3d", w);   // 访问顶点w
                visited[w] = 1;     // 置顶点w已访问
                top++;              // 将顶点w进栈
                St[top] = w;
                break;  // 退出循环，即再处理栈顶的顶点（体现后进先出）
            }
            p = p->nextArc;  // 找顶点x的下一个相邻点
        }
        if (p == nullptr)
            top--;  // 若顶点x再没有相邻点，将其退栈
    }
    printf("\n");
}

/**
 * 广度优先遍历算法
 * @param G
 * @param v
 */
void BFS(AdjGraph *G, int v) {
    ArcNode *p;
    int queue[MAX], front = 0, rear = 0;  // 定义环形队列并初始化
    int w;
    for (int i = 0; i < G->n; ++i)
        visited[i] = 0;  // 访问标志数组初始化
    printf("%3d", v);    // 输出被访问顶点的编号
    visited[v] = 1;      // 置已访问标志
    rear = (rear + 1) % MAX;
    queue[rear] = v;         // v进队
    while (front != rear) {  // 若队列不空时循环
        front = (front + 1) % MAX;
        w = queue[front];            // 出队并赋给w
        p = G->adjList[w].firstArc;  // 找顶点w的第一个相邻点
        while (p != nullptr) {
            if (visited[p->adjVex] == 0) {  // 若相邻点未被访问
                printf("%3d", p->adjVex);   //访问相邻点
                visited[p->adjVex] = 1;     // 置该顶点已被访问的标志
                rear = (rear + 1) % MAX;    // 该顶点进队
                queue[rear] = p->adjVex;
            }
            p = p->nextArc;  // 找下一个相邻点
        }
    }
    printf("\n");
}

int main() {
    AdjGraph *G;
    int A[MAX][MAX] = {{0,   5,   INF, 7,   INF, INF},
                       {INF, 0,   4,   INF, INF, INF},
                       {8,   INF, 0,   INF, INF, 9},
                       {INF, INF, 5,   0,   INF, 6},
                       {INF, INF, INF, 5,   0,   INF},
                       {3,   INF, INF, INF, 1,   0}};
    int n = 6, e = 10;  // 图中的数据
    CreateAdj(G, A, n, e);
    printf("图G的邻接表：\n");
    DisplayAdj(G);
    printf("从顶点0开始的DFS（递归算法）：\n");
    DFS(G, 0);
    printf("\n");
    printf("从顶点0开始的DFS（非递归算法）：\n");
    DFS1(G, 0);
    printf("从顶点0开始的BFS：\n");
    BFS(G, 0);
    DestroyAdj(G);
    return 1;
}