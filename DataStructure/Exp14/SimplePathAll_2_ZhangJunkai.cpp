#include "graph.cpp"  // ����ͼ�Ĵ洢�ṹ�����������㷨

int visited[MAXV];  // ȫ������

/**
 * ���ͼG�дӶ���u��v�ĳ���Ϊ1�����м�·���������ڽ�����洢��
 * @param G
 * @param u
 * @param v
 * @param l
 * @param path
 * @param d ��ĿǰΪֹ���߹���·�����ȣ�����ʱ��ֵΪ-1
 */
void SimplePathAll_2(AdjGraph *G, int u, int v, int l, int path[], int d) {
    int w;
    ArcNode *p;
    visited[u] = l;
    path[++d] = u;           // ·������d��1����������ӵ�·����
    if (u == v && d == l) {  // �������������һ��·��
        for (int i = 0; i <= d; ++i)
            printf("%3d", path[i]);
        printf("\n");
    }
    p = G->adjlist[u].firstarc;  // pָ�򶥵�u�ĵ�һ�����ڵ�
    while (p != nullptr) {
        w = p->adjvex;        // wΪ����u�����ڵ�
        if (visited[w] == 0)  // ���ö���δ��Ƿ��ʣ���ݹ����֮
            SimplePathAll_2(G, w, v, l, path, d);
        p = p->nextarc;  // ��u����һ�����ڵ�
    }
    visited[u] = 0;  // ȡ�����ʱ�ǣ���ʹ�ö��������ʹ��
}

/**
 * �󶥵�u������v��u��v�������·��
 * @param G
 * @param u
 * @param v
 * @param path
 * @return ����u������v��u��v�������·��
 */
int ShortPath(AdjGraph *G, int u, int v, int path[]) {
    struct {
        int vno;     // ��ǰ������
        int level;   // ��ǰ����Ĳ��
        int parent;  // ��ǰ����ĵ�һ���ڵ���
    } qu[MAXV];      // ����˳���ѭ������
    int front = -1;
    int rear = -1;
    int k;
    int lev;
    int i;
    int j;
    ArcNode *p;
    visited[u] = 1;
    qu[++rear].vno = u;  // ����u�ѷ��ʣ��������
    qu[rear].level = 0;  // ���ڵ�����Ϊ1
    qu[rear].parent = -1;
    while (front < rear) {    // ���п���ָ��
        k = qu[++front].vno;  // ���Ӷ���k
        lev = qu[front].level;
        if (k == v) {   // ������kΪ�յ�
            i = 0;      // �ڶ�����ǰ�ƴ�һ������·��
            j = front;  // ��·�������path��
            while (j != -1) {
                path[lev - i] = qu[j].vno;  // �����·������path��
                j = qu[j].parent;
                ++i;
            }
            return lev;  // �ҵ�����v����������
        }
        p = G->adjlist[k].firstarc;  // pָ�򶥵�k�ĵ�һ�����ڵ�
        while (p != nullptr) {       // ��������k�����ڵ�
            if (visited[p->adjvex] == 0) {  // ��δ���ʹ�
                visited[p->adjvex] = 1;
                qu[++rear].vno = p->adjvex;  // ���ʹ������ڵ����
                qu[rear].level = lev + 1;
                qu[rear].parent = front;
            }
            p = p->nextarc;  // �Ҷ���k����һ���ڵ�
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
    CreateAdj(G, A, n, e);  // ����ͼ���ڽӱ�
    printf("ͼG���ڽӱ�\n");
    DispAdj(G);
    for (int i = 0; i < n; ++i)
        visited[i] = 0;

    printf("��1���Ӷ���%d��%d�����г���Ϊ%d·����\n", u, v, l);
    SimplePathAll_2(G, u, v, l, path, -1);

    printf("��2���Ӷ���%d��%d�����·����\n", u, v);
    for (int i = 0; i < n; ++i)
        visited[i] = 0;
    int j = ShortPath(G, u, v, path);
    for (int i = 0; i <= j; ++i)
        printf("%3d", path[i]);
    printf("\n");
    DestroyAdj(G);
    return 1;
}