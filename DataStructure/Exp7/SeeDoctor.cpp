// ��д���˿���ģ�����
// ���ò���ͷ�ڵ�ĵ�����
#include <malloc.h>
#include <stdio.h>
typedef struct qnode {
    int data;                    // ������
    struct qnode* next;          // ��һ���ڵ�ָ��
} QNode;                         // ���ӽڵ�����
void DestroyQueue(QNode*& qu) {  // �ͷ�����
    QNode* p;
    // pre = qu;
    if (qu != NULL) {  // �����Ӳ���
        p = qu->next;
        while (p != NULL) {  // �ͷŶ����������ݽڵ�
            free(qu);
            qu = p;
            p = p->next;
        }
        free(qu);
    }
}
bool exist(QNode* qu, int no) {  // �������Ƿ���no�����ŵĲ���
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
void SeeDoctor() {  // ģ�ⲡ�˿����Ĺ���
    int select, no;
    bool flag = true;
    QNode *front, *rear, *p;
    front = rear = NULL;  // �����նӣ�����ͷ�ڵ�
    while (flag) {        // ѭ��ִ��
        printf("\n>>> 1���Ŷ�   2������   3���鿴�Ŷ�   4�������Ŷӣ��������ξ���   5���°�\n>>>��ѡ��");
        scanf("%d", &select);
        switch (select) {
            case 1:  // 1���Ŷ�
                printf("\n  ���벡���ţ�");
                while (true) {
                    scanf("%d", &no);
                    if (exist(front, no))
                        printf("\n-------->����Ĳ������ظ����������룺");
                    else
                        break;
                }
                p = (QNode*)malloc(sizeof(QNode));  // �����Ӵ���
                p->data = no;
                p->next = NULL;
                if (rear == NULL)  // ��һ�������Ŷ�
                    front = rear = p;
                else {
                    rear->next = p;
                    rear = p;  // ��p�ڵ����
                }
                break;

            case 2:                 // 2������
                if (front == NULL)  // �ӿ�
                    printf("\n-------->û���ŶӵĲ��ˣ�\n");
                else {  // �Ӳ���
                    p = front;
                    printf("\n-------->����%d����\n", p->data);
                    if (rear == p)  // ֻ��һ�������Ŷӵ����
                        front = rear = NULL;
                    else
                        front = p->next;
                    free(p);
                }
                break;

            case 3:                 // �鿴����
                if (front == NULL)  // �ӿ�
                    printf("\n-------->û���ŶӵĲ���");
                else {
                    p = front;
                    printf("\n-------->�ŶӲ��ˣ�");
                    while (p != NULL) {
                        printf("%d ", p->data);
                        p = p->next;
                    }
                    printf("\n");
                }
                break;

            case 4:                 // �����Ŷ�
                if (front == NULL)  // �ӿ�
                    printf("\n-------->û�����еĲ��ˣ�\n");
                else {
                    p = front;
                    printf("\n-------->���˰�����˳����");
                    while (p != NULL) {
                        printf("%d ", p->data);
                        p = p->next;
                    }
                    printf("\n");
                }
                DestroyQueue(front);  // �ͷ�����
                flag = false;         // �˳�
                break;

            case 5:                 // �°�
                if (front != NULL)  // �Ӳ���
                    printf("\n-------->���ŶӵĲ��������ҽ��\n");
                flag = false;         // �˳�
                DestroyQueue(front);  // �ͷ�����
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