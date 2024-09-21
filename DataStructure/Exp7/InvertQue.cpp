// ��Ŀ���������һ���㷨����һ�����ζ��У�����Ϊ n��Ԫ���±�� 0 �� n-1����Ԫ�ص��á�
// ��ʾ��������ʱջ��ɡ�
// ʹ��һ����ʱ st���Ƚ� qu ����������Ԫ�س��Ӳ������ջ st��ֱ�����п�Ϊֹ��
// Ȼ���ʼ������ qu��������գ����ٽ�ջ st ������Ԫ�ز�������� qu���������ջ st��
// ��Ӧ���㷨���£�
#include "sqqueue.h"
#include "sqstack.h"
void Reverse(SqQueue*& qu) {
    ElemType e;
    SqStack* st;
    InitStack(st);
    while (!QueueEmpty(qu)) {
        deQueue(qu, e);
        Push(st, e);
    }
    while (!StackEmpty(st)) {
        Pop(st, e);
        enQueue(qu, e);
    }
    DestroyStack(st);
}
int main() {
    ElemType *a, e;
    SqQueue* sq;    // ����ѭ������ָ�����sq
    InitQueue(sq);  // ��ʼ��sq;
    int n;
    printf("�����������Ԫ�صĸ�����");
    scanf("%d", &n);
    a = (char*)malloc(n * sizeof(char));  // ��̬��������ռ䣬���ڴӼ��̽�������
    for (int i = 0; i < n; ++i) {
        printf("�������%d���ַ�", i + 1);
        scanf("%c", a[i]);
        if (enQueue(sq, a[i]))  // ���������������
            printf("%c�����\n");
        else
            printf("����������\n");
    }
    Reverse(sq);  // ����
    printf("\n���ú�Ķ��������ǣ�\n");
    while (deQueue(sq, e))  // ���γ��Ӵ�ӡ����֤���ò�������ȷ��
        printf("%c\t", &e);
    DestroyQueue(sq);  // ����st����
    free(a);           // ��̬�ͷ�����ռ�
    return 1;
}