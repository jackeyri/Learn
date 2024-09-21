#include "graph_ZhangJunKai.h"  // ����ͼ�Ĵ洢�ṹ�����������㷨

int visited[MAX];  // ȫ������

/**
 * �ݹ�������ȱ����㷨
 * @param G
 * @param v
 */
void DFS(AdjGraph *G, int v) {
    ArcNode *p;
    visited[v] = 1;              // ���ѷ��ʱ��
    printf("%3d", v);            // ��������ʶ���ı��
    p = G->adjList[v].firstArc;  // pָ�򶥵�v�ĵ�һ�����Ļ�ͷ���
    while (p != nullptr) {
        if (visited[p->adjVex] == 0)  // ��p->adjVex����δ���ʵݹ������
            DFS(G, p->adjVex);
        p = p->nextArc;  // pָ�򶥵�v����һ�����Ļ�ͷ���
    }
}

/**
 * �ǵݹ�������ȱ����㷨
 * @param G
 * @param v
 */
void DFS1(AdjGraph *G, int v) {
    ArcNode *p;
    int St[MAX];
    int top = -1, w, x;
    for (int i = 0; i < G->n; ++i)
        visited[i] = 0;  // ������ʱ�־���ó�0
    printf("%3d", v);    // ���ʶ���v
    visited[v] = 1;      // �ö���v�ѷ���
    top++;
    St[top] = v;                     // ������v��ջ
    while (top > -1) {               // ջ����ѭ��
        x = St[top];                 // ȡջ������x��Ϊ��ǰ����
        p = G->adjList[x].firstArc;  // �Ҷ���x�ĵ�һ�����ڵ�
        while (p != nullptr) {
            w = p->adjVex;          // x�����ڵ�Ϊw
            if (visited[w] == 0) {  // ������wû�з���
                printf("%3d", w);   // ���ʶ���w
                visited[w] = 1;     // �ö���w�ѷ���
                top++;              // ������w��ջ
                St[top] = w;
                break;  // �˳�ѭ�������ٴ���ջ���Ķ��㣨���ֺ���ȳ���
            }
            p = p->nextArc;  // �Ҷ���x����һ�����ڵ�
        }
        if (p == nullptr)
            top--;  // ������x��û�����ڵ㣬������ջ
    }
    printf("\n");
}

/**
 * ������ȱ����㷨
 * @param G
 * @param v
 */
void BFS(AdjGraph *G, int v) {
    ArcNode *p;
    int queue[MAX], front = 0, rear = 0;  // ���廷�ζ��в���ʼ��
    int w;
    for (int i = 0; i < G->n; ++i)
        visited[i] = 0;  // ���ʱ�־�����ʼ��
    printf("%3d", v);    // ��������ʶ���ı��
    visited[v] = 1;      // ���ѷ��ʱ�־
    rear = (rear + 1) % MAX;
    queue[rear] = v;         // v����
    while (front != rear) {  // �����в���ʱѭ��
        front = (front + 1) % MAX;
        w = queue[front];            // ���Ӳ�����w
        p = G->adjList[w].firstArc;  // �Ҷ���w�ĵ�һ�����ڵ�
        while (p != nullptr) {
            if (visited[p->adjVex] == 0) {  // �����ڵ�δ������
                printf("%3d", p->adjVex);   //�������ڵ�
                visited[p->adjVex] = 1;     // �øö����ѱ����ʵı�־
                rear = (rear + 1) % MAX;    // �ö������
                queue[rear] = p->adjVex;
            }
            p = p->nextArc;  // ����һ�����ڵ�
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
    int n = 6, e = 10;  // ͼ�е�����
    CreateAdj(G, A, n, e);
    printf("ͼG���ڽӱ�\n");
    DisplayAdj(G);
    printf("�Ӷ���0��ʼ��DFS���ݹ��㷨����\n");
    DFS(G, 0);
    printf("\n");
    printf("�Ӷ���0��ʼ��DFS���ǵݹ��㷨����\n");
    DFS1(G, 0);
    printf("�Ӷ���0��ʼ��BFS��\n");
    BFS(G, 0);
    DestroyAdj(G);
    return 1;
}