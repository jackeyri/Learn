// ˳����У����ζ��У������㷨
#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;  // ��β�Ͷ���ָ��
} SqQueue;
void InitQueue(SqQueue*& q) {  // ��ʼ������q
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}
void DestroyQueue(SqQueue*& q) {  // ���ٶ���q
    free(q);
}
bool QueueEmpty(SqQueue* q) {  // �ж϶�q�Ƿ�Ϊ��
    return q->front == q->rear;
}
bool enQueue(SqQueue*& q, ElemType e) {       // ����
    if ((q->rear + 1) % MaxSize == q->front)  // ���������
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}
bool deQueue(SqQueue*& q, ElemType& e) {  // ����
    if (q->front == q->rear)              // �ӿ������
        return false;
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}