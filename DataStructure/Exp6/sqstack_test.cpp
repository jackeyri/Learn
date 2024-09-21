#include "sqstack.h"  // 包含顺序栈的基本运算算法
int main() {
    ElemType e;
    SqStack* s;
    printf("顺序表s的基本运算如下：\n");
    printf("（1）初始化栈s\n");
    InitStack(s);
    printf("（2）栈为%s\n", StackEmpty(s) ? "空" : "非空");
    printf("（3）依次进栈元素a，b，c，d，e\n");
    Push(s, 'a');
    Push(s, 'b');
    Push(s, 'c');
    Push(s, 'd');
    Push(s, 'e');
    printf("（4）栈为%s\n", StackEmpty(s) ? "空" : "非空");
    printf("（5）出栈顺序：");
    while (!StackEmpty(s)) {
        Pop(s, e);
        printf("%c ", e);
    }
    printf("\n（6）栈为%s\n", StackEmpty(s) ? "空" : "非空");
    printf("（7）释放栈\n");
    DestroyStack(s);
    return 0;
}