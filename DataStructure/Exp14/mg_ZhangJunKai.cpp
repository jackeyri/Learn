#include <cstdio>
#include "malloc.h"

#define MaxSize 100
#define M 4
#define N 4
/**
 * �����ڽӱ�����
 */
typedef struct ANode {      // �ߵĽڵ�ṹ����
    int i, j;               // �ñߵ��յ�λ��(i, j)
    struct ANode *nextarc;  // ָ����һ���ߵ�ָ��
} ArcNode;
/**
 * �����ڽӱ�����
 */
typedef struct Vnode {  // �ڽӱ�ͷ�ڵ������
    ArcNode *firstarc;  // ָ���һ�����ڵ�
} VNode;
/**
 * �����ڽӱ�����
 */
typedef struct {
    VNode adjlist[M + 2][N + 2];  // �ڽӱ�ͷ�ڵ�����
} ALGraph;                        // ͼ���ڽӱ�����

typedef struct {
    int i;  // ��ǰ������к�
    int j;  // ��ǰ������к�
} Box;
typedef struct {
    Box data[MaxSize];
    int length;  // ·������
} PathType;      // ����·������
int visited[M + 2][N + 2] = {0};
int count = 0;

/**
 * �����Թ������Ӧ���ڽӱ�G
 * @param G
 * @param mg
 */
void CreateAdj(ALGraph *&G, int mg[][N + 2]) {
    int i1, j1, di;
    ArcNode *p;
    G = (ALGraph *) malloc(sizeof(ALGraph));
    for (auto &i: G->adjlist)  // ���ڽӱ�������ͷ�ڵ��ָ�����ó�ֵ
        for (auto &j: i)
            j.firstarc = nullptr;
    for (int i = 1; i <= M; ++i)  // ���mg��ÿ��Ԫ��
        for (int j = 1; j <= N; ++j)
            if (mg[i][j] == 0) {
                di = 0;
                while (di < 4) {
                    switch (di) {
                        case 0:
                            i1 = i - 1;
                            j1 = j;
                            break;
                        case 1:
                            i1 = i;
                            j1 = j + 1;
                            break;
                        case 2:
                            i1 = i + 1;
                            j1 = j;
                            break;
                        case 3:
                            i1 = i;
                            j1 = j - 1;
                            break;
                        default:
                            break;
                    }
                    if (mg[i1][j1] == 0) {  // (i1, j1)Ϊ���߷���
                        p = (ArcNode *) malloc(sizeof(ArcNode));  // ����һ���ڵ�*p
                        p->i = i1;
                        p->j = j1;
                        p->nextarc = G->adjlist[i][j].firstarc;  // ��*p�ڵ����������
                        G->adjlist[i][j].firstarc = p;
                    }
                    ++di;
                }
            }
}

/**
 * ����ڽӱ�G
 * @param G
 */
void DispAdj(ALGraph *G) {
    ArcNode *p;
    for (int i = 0; i < M + 2; ++i)
        for (int j = 0; j < N + 2; ++j) {
            printf("[%d, %d]��", i, j);
            p = G->adjlist[i][j].firstarc;
            while (p != nullptr) {
                printf("(%d, %d)  ", p->i, p->j);
                p = p->nextarc;
            }
            printf("\n");
        }
}

/**
 * �����ڽӱ�
 * @param G
 */
void DestroyAdj(ALGraph *&G) {
    ArcNode *pre, *p;
    for (auto &i: G->adjlist)
        for (auto &j: i) {
            pre = j.firstarc;
            if (pre != nullptr) {
                p = pre->nextarc;
                while (p != nullptr) {
                    free(pre);
                    pre = p;
                    p = p->nextarc;
                }
                free(pre);
            }
        }
    free(G);
}

/**
 * ��ͼG�в���DFS�㷨(xi, yi)��(xe, ye)������·��
 * @param G
 * @param xi
 * @param yi
 * @param xe
 * @param ye
 * @param path
 */
void FindPath(ALGraph *G, int xi, int yi, int xe, int ye, PathType path) {
    ArcNode *p;
    visited[xi][yi] = 1;  // ���ѷ��ʱ��
    path.data[path.length].i = xi;
    path.data[path.length].j = yi;
    ++path.length;
    if (xi == xe && yi == ye) {
        printf("�Թ�·��%d��", ++count);
        for (int k = 0; k < path.length; ++k)
            printf("��%d��%d��", path.data[k].i, path.data[k].j);
        printf("\n");
    }
    p = G->adjlist[xi][yi].firstarc;  // pָ�򶥵�v�ĵ�һ������
    while (p != nullptr) {
        if (visited[p->i][p->j] == 0)  // ��(p->i, p->j)����δ���ʣ��ݹ������
            FindPath(G, p->i, p->j, xe, ye, path);
        p = p->nextarc;  // pָ�򶥵�v����һ���߶���
    }
    visited[xi][yi] = 0;
}

int main() {
    ALGraph *G;
    int mg[M + 2][N + 2] = {{1, 1, 1, 1, 1, 1},
                            {1, 0, 0, 0, 1, 1},
                            {1, 0, 1, 0, 0, 1},
                            {1, 0, 0, 0, 1, 1},
                            {1, 1, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1}};  // �Թ�����
    CreateAdj(G, mg);
    printf("�Թ���Ӧ���ڽӱ�\n");
    DispAdj(G);  // ����ڽӱ�
    PathType path;
    path.length = 0;
    printf("���е��Թ�·����\n");
    FindPath(G, 1, 1, M, N, path);
    DestroyAdj(G);
    return 1;
}