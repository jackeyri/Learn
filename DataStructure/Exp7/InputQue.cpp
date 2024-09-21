// 题目描述：设从键盘输入字符序列 a1、a2、…、an。设计一个算法实现这样的功能：
// 若ai为数字字符，ai 进队，若 ai 为小写字母时，将队首元素出队，若 ai 为其他字符，表示输入结束。
// 要求使用环形队列
#include "sqqueue.h"
void InputQue() {
    ElemType a, e;
    SqQueue* qu;  // 定义队列指针
    InitQueue(qu);
    while (true) {
        printf("输入a：");
        scanf("%c", &a);
        if (a >= '0' && a <= '9') {  // 为数字字符
            if (!enQueue(qu, a))
                printf("队列满，不能进队\n");
        } else if (a >= 'a' && a <= 'z') {  // 为小写字母
            if (!deQueue(qu, e))
                printf("队列空，不能出队\n");
            else
                printf("出队元素：%c\n", e);
        } else
            break;
    }
    DestroyQueue(qu);
}
int main() {
    InputQue();
    return 1;
}