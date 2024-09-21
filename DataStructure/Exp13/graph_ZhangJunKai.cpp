#include "graph_ZhangJunKai.h"  // ����ͼ�Ĵ洢�ṹ�����������㷨

int main() {
    MatGraph g;
    AdjGraph *G;
    int A[MAX][MAX] = {{0,   5,   INF, 7,   INF, INF},
                       {INF, 0,   4,   INF, INF, INF},
                       {8,   INF, 0,   INF, INF, 9},
                       {INF, INF, 5,   0,   INF, 6},
                       {INF, INF, INF, 5,   0,   INF},
                       {3,   INF, INF, INF, 1,   0}};
    int n = 6, e = 10;  // ͼ�е�����
    CreateMat(g, A, n, e);
    printf("��1��ͼG���ڽӾ���\n");
    DisplayMat(g);
    CreateAdj(G, A, n, e);
    printf("��2��ͼG���ڽӱ�\n");
    DisplayAdj(G);
    printf("��3������ͼG���ڽӱ�\n");
    DestroyAdj(G);
    return 1;
}