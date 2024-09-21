#include "graph.cpp"  // 包含图的存储结构及基本运算算法

int visited[MAXV];  // 全局数组

/**
 * 输出图G中从顶点u到v的长度为1的所有简单路径（采用邻接链表存储）
 * @param G
 * @param u
 * @param v
 * @param l
 * @param path
 * @param d 到目前为止已走过的路径长度，调用时初值为-1
 */
void SimplePathAll_2(AdjGraph *G, int u, int v, int l, int path[], int d) {
    int w;
    ArcNode *p;
    visited[u] = l;
    path[++d] = u;           // 路径长度d增1，将顶点添加到路径中
    if (u == v && d == l) {  // 满足条件，输出一条路径
        for (int i = 0; i <= d; ++i)
            printf("%3d", path[i]);
        printf("\n");
    }
    p = G->adjlist[u].firstarc;  // p指向顶点u的第一个相邻点
    while (p != nullptr) {
        w = p->adjvex;        // w为顶点u的相邻点
        if (visited[w] == 0)  // 若该顶点未标记访问，则递归访问之
            SimplePathAll_2(G, w, v, l, path, d);
        p = p->nextarc;  // 找u的下一个相邻点
    }
    visited[u] = 0;  // 取消访问标记，以使该顶点可重新使用
}

/**
 * 求顶点u到顶点v（u≠v）的最短路径
 * @param G
 * @param u
 * @param v
 * @param path
 * @return 顶点u到顶点v（u≠v）的最短路径
 */
int ShortPath(AdjGraph *G, int u, int v, int path[]) {
    struct {
        int vno;     // 当前顶点编号
        int level;   // 当前顶点的层次
        int parent;  // 当前顶点的当一个节点编号
    } qu[MAXV];      // 定义顺序非循环队列
    int front = -1;
    int rear = -1;
    int k;
    int lev;
    int i;
    int j;
    ArcNode *p;
    visited[u] = 1;
    qu[++rear].vno = u;  // 顶点u已访问，将其入队
    qu[rear].level = 0;  // 根节点层次置为1
    qu[rear].parent = -1;
    while (front < rear) {    // 队列空则指向
        k = qu[++front].vno;  // 出队顶点k
        lev = qu[front].level;
        if (k == v) {   // 若顶点k为终点
            i = 0;      // 在队列中前推从一条正向路径
            j = front;  // 该路径存放在path中
            while (j != -1) {
                path[lev - i] = qu[j].vno;  // 将最短路径存入path中
                j = qu[j].parent;
                ++i;
            }
            return lev;  // 找到顶点v，返回其层次
        }
        p = G->adjlist[k].firstarc;  // p指向顶点k的第一个相邻点
        while (p != nullptr) {       // 依次搜索k的相邻点
            if (visited[p->adjvex] == 0) {  // 若未访问过
                visited[p->adjvex] = 1;
                qu[++rear].vno = p->adjvex;  // 访问过的相邻点进队
                qu[rear].level = lev + 1;
                qu[rear].parent = front;
            }
            p = p->nextarc;  // 找顶点k的下一相邻点
        }
    }
    return -1;
}

int main() {
    int u = 5;
    int v = 2;
    int l = 3;
    int n = 6;
    int e = 10;
    int path[MAXV];
    AdjGraph *G;
    int A[MAXV][MAXV] = {{0, 1, 0, 1, 0, 0},
                         {0, 0, 1, 0, 0, 0},
                         {1, 0, 0, 0, 0, 1},
                         {0, 0, 1, 0, 0, 1},
                         {0, 0, 0, 1, 0, 0},
                         {1, 1, 0, 1, 1, 0}};
    CreateAdj(G, A, n, e);  // 建立图的邻接表
    printf("图G的邻接表：\n");
    DispAdj(G);
    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    printf("（1）从顶点%d到%d的所有长度为%d路径：\n", u, v, l);
    SimplePathAll_2(G, u, v, l, path, -1);

    printf("（2）从顶点%d到%d的最短路径：\n", u, v);
    for (int i = 0; i < n; ++i)
        visited[i] = 0;
    int j = ShortPath(G, u, v, path);
    for (int i = 0; i <= j; ++i)
        printf("%3d", path[i]);
    printf("\n");
    DestroyAdj(G);
    return 1;
}