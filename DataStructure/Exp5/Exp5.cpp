#include <bits/stdc++.h>
using namespace std;
typedef struct Node {  // 结点类型定义
    int data;
    struct Node* next;
} LinkNode;
void CreatLink(LinkNode*& List, int n) {  // 创建值为1~n的n个结点的不带头结点的循环单链表
    if (n < 1) {
        printf("空环，创建失败！");
        return;
    }
    LinkNode *r, *s;  // r指向尾结点，S辅导插入指针
    List = (LinkNode*)malloc(sizeof(LinkNode));
    List->data = 1;
    List->next = List;
    r = List;
    for (int i = 2; i <= n; ++i) {  // 尾插法，插入余下的n-1个结点
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = i;
        s->next = List;
        r->next = s;
        r = s;
    }
}
void PrintLink(LinkNode*& List) {  // 打印循环列表
    LinkNode* current = List;
    if (List == NULL)
        return;
    do {
        cout << current->data << "\t";
        current = current->next;
    } while (current != List);
    printf("\n");
}
void JosephRing(LinkNode*& List, int n, int m) {  // 用不带头结点的循环单链表求解约瑟夫环
    CreatLink(List, n);
    PrintLink(List);
    int number;         // number用于统计出列人数计数
    Node *current, *s;  // current当前访问结点游标，s增加和删除结点的辅助指针
    s = current = List;
    while (s->next != List)  // 使得s指向尾结点，为删除做准备
        s = s->next;
    number = 0;
    // 模拟报数过程
    number = 0;
    while (number < n) {  // 出圈人数不到n个，继续报数
        for (int i = 1; i < m; ++i) {
            s = current;
            current = current->next;
        }
        s->next = current->next;
        cout << current->data << "\t";
        free(current);
        current = s->next;
        ++number;
    }
}
void JosephRing(int* List, int n, int m) {  // 用数组求解约瑟夫环
    List = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)  // 初始化所有人均在圈内，即值=1;
        List[i] = 1;
    int number = 0;       // 已经出圈人数统计
    int current = n - 1;  // current数组游标，初始化指向最后一个人
    int count = 0;
    while (number < n) {  // 出圈人数少于n
        // 模拟报数
        while (count < m) {
            current = (current + 1) % n;  // current游标向前，保证在数组内循环
            if (List[current] == 1)       // 若current位置上的人未出圈，则计入报数
                ++count;
        }
        List[current] = 0;            // current位置上的人是报数到m的人，出圈，置0
        printf("%d\t", current + 1);  // 数组角标和人的编号相差1
        ++number;
        count = 0;  // 准备下一轮的报数
    }
    free(List);
    return;
}
int main() {
    int n, m;  // count用于报数计数，number用于出列人数计数
    LinkNode* JosephLink;
    printf("输入总人数n和报数规律m：\n");
    scanf("%d%d", &n, &m);

    /* 不带头结点的循环单链表存储的约瑟夫环问题求解 */
    clock_t b, e;
    b = clock();
    JosephRing(JosephLink, n, m);
    e = clock();
    printf("\n使用循环单链表存储时执行时间：%ld\n", e - b);

    /* 数组存储的约瑟夫环问题求解 */
    int* p = NULL;
    b = clock();
    JosephRing(p, n, m);
    e = clock();
    printf("\n使用数组存储时执行时间：%ld\n", e - b);

    return 0;
}