// ��Ŀ��������Ӽ��������ַ����� a1��a2������an�����һ���㷨ʵ�������Ĺ��ܣ�
// ��aiΪ�����ַ���ai ���ӣ��� ai ΪСд��ĸʱ��������Ԫ�س��ӣ��� ai Ϊ�����ַ�����ʾ���������
// Ҫ��ʹ�û��ζ���
#include "sqqueue.h"
void InputQue() {
    ElemType a, e;
    SqQueue* qu;  // �������ָ��
    InitQueue(qu);
    while (true) {
        printf("����a��");
        scanf("%c", &a);
        if (a >= '0' && a <= '9') {  // Ϊ�����ַ�
            if (!enQueue(qu, a))
                printf("�����������ܽ���\n");
        } else if (a >= 'a' && a <= 'z') {  // ΪСд��ĸ
            if (!deQueue(qu, e))
                printf("���пգ����ܳ���\n");
            else
                printf("����Ԫ�أ�%c\n", e);
        } else
            break;
    }
    DestroyQueue(qu);
}
int main() {
    InputQue();
    return 1;
}