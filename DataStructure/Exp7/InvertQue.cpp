// 题目描述：设计一个算法，将一个环形队列（容量为 n，元素下标从 0 到 n-1）的元素倒置。
// 提示：借助临时栈完成。
// 使用一个临时 st，先将 qu 队列中所有元素出队并将其进栈 st，直到队列空为止。
// 然后初始化队列 qu（队列清空），再进栈 st 的所有元素并将其进队 qu，最后销毁栈 st。
// 对应的算法如下：
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
    SqQueue* sq;    // 定义循环队列指针变量sq
    InitQueue(sq);  // 初始化sq;
    int n;
    printf("请输入入队列元素的个数：");
    scanf("%d", &n);
    a = (char*)malloc(n * sizeof(char));  // 动态申请数组空间，便于从键盘接收数据
    for (int i = 0; i < n; ++i) {
        printf("请输入第%d个字符", i + 1);
        scanf("%c", a[i]);
        if (enQueue(sq, a[i]))  // 数组数据依次入队
            printf("%c已入队\n");
        else
            printf("队列已满！\n");
    }
    Reverse(sq);  // 逆置
    printf("\n逆置后的队列序列是：\n");
    while (deQueue(sq, e))  // 依次出队打印，验证逆置操作的正确性
        printf("%c\t", &e);
    DestroyQueue(sq);  // 销毁st队列
    free(a);           // 动态释放数组空间
    return 1;
}