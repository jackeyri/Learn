#include "graph.cpp"  // ����ͼ�Ĵ洢�ṹ

int visited[MAXV];  // ȫ������

/**
 * ���ͼG�дӶ���u��v�����м�·���������ڽ�����洢��
 * @param G
 * @param u
 * @param v
 * @param path
 * @param d ����ʱ��ʼֵΪ-1
 */
void SimplePathAll_1(AdjGraph *G, int u, int v, int path[], int d) {
    ArcNode *p;
    int w;
    path[++d] = u;  // ·������d��1������ǰ������ӵ�·����
    visited[u] = 1;
    if (u == v && d > 0) {  // �ҵ��յ�
        for (int i = 0; i <= d; ++i)
            printf("%3d", path[i]);
        printf("\n");
    }
    p = G->adjlist[u].firstarc;  // pָ�򶥵�u�ĵ�һ�����ڵ�
    while (p != nullptr) {
        w = p->adjvex;        // wΪu�����ڵ���
        if (visited[w] == 0)  // ���ö���δ��Ƿ��ʣ���ݹ����֮
            SimplePathAll_1(G, w, v, path, d);
        p = p->nextarc;  // ��u����һ�����ڵ�
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
    CreateAdj(G, A, n, e);  // ������ͼ��ʾ���ڽӱ�
    printf("ͼG���ڽӱ�\n");
    DispAdj(G);
    printf("��1���Ӷ���%d��%d������·����\n", u, v);
    for (int i = 0; i < n; ++i)
        visited[i] = 0;
    SimplePathAll_1(G, u, v, path, -1);
    DestroyAdj(G);
    return 1;
}