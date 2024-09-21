// 编写病人看病模拟程序
// 采用不带头节点的单链表
#include <malloc.h>
#include <stdio.h>
typedef struct qnode {
    int data;                    // 病历号
    struct qnode* next;          // 下一个节点指针
} QNode;                         // 链队节点类型
void DestroyQueue(QNode*& qu) {  // 释放链队
    QNode* p;
    // pre = qu;
    if (qu != NULL) {  // 若链队不空
        p = qu->next;
        while (p != NULL) {  // 释放队中所有数据节点
            free(qu);
            qu = p;
            p = p->next;
        }
        free(qu);
    }
}
bool exist(QNode* qu, int no) {  // 队列中是否有no病历号的病人
    bool find = false;
    QNode* p = qu;
    while (p != NULL && !find) {
        if (p->data == no)
            find = true;
        else
            p = p->next;
    }
    return find;
}
void SeeDoctor() {  // 模拟病人看病的过程
    int select, no;
    bool flag = true;
    QNode *front, *rear, *p;
    front = rear = NULL;  // 创建空队，不带头节点
    while (flag) {        // 循环执行
        printf("\n>>> 1：排队   2：就诊   3：查看排队   4：不在排队，余下依次就诊   5：下班\n>>>请选择：");
        scanf("%d", &select);
        switch (select) {
            case 1:  // 1：排队
                printf("\n  输入病历号：");
                while (true) {
                    scanf("%d", &no);
                    if (exist(front, no))
                        printf("\n-------->输入的病历号重复，重新输入：");
                    else
                        break;
                }
                p = (QNode*)malloc(sizeof(QNode));  // 创建接待你
                p->data = no;
                p->next = NULL;
                if (rear == NULL)  // 第一个病人排队
                    front = rear = p;
                else {
                    rear->next = p;
                    rear = p;  // 将p节点进队
                }
                break;

            case 2:                 // 2：就诊
                if (front == NULL)  // 队空
                    printf("\n-------->没有排队的病人！\n");
                else {  // 队不空
                    p = front;
                    printf("\n-------->病人%d就诊\n", p->data);
                    if (rear == p)  // 只有一个病人排队的情况
                        front = rear = NULL;
                    else
                        front = p->next;
                    free(p);
                }
                break;

            case 3:                 // 查看队列
                if (front == NULL)  // 队空
                    printf("\n-------->没有排队的病人");
                else {
                    p = front;
                    printf("\n-------->排队病人：");
                    while (p != NULL) {
                        printf("%d ", p->data);
                        p = p->next;
                    }
                    printf("\n");
                }
                break;

            case 4:                 // 不在排队
                if (front == NULL)  // 队空
                    printf("\n-------->没有排列的病人！\n");
                else {
                    p = front;
                    printf("\n-------->病人按以下顺序就诊：");
                    while (p != NULL) {
                        printf("%d ", p->data);
                        p = p->next;
                    }
                    printf("\n");
                }
                DestroyQueue(front);  // 释放链队
                flag = false;         // 退出
                break;

            case 5:                 // 下班
                if (front != NULL)  // 队不空
                    printf("\n-------->请排队的病人明天就医！\n");
                flag = false;         // 退出
                DestroyQueue(front);  // 释放链队
                break;

            default:
                break;
        }
    }
}
int main() {
    SeeDoctor();
    return 1;
}