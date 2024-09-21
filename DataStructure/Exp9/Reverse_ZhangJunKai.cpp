// 用递归算法逆置一个带头结点的单链表
// 算法思想：Reverse(p, L)是大问题，描述为逆置以p为首节点的单链表，逆置后指向尾结点
// Reverse(p->next, L)是小问题，描述为逆置以p->next，为首节点的单链表，逆置后p->next指向尾结点
#include "linklist_ZhangJunKai.h"  // 包含单链表的基本运算算法
void Reverse(LinkNode* p, LinkNode*& L) {
    if (p->next == NULL) {  // 以p为首节点指针的单链表只有一个节点时
        L->next = p;
        return;
    }
    Reverse(p->next, L);  // 逆置后的尾节点是p->next
    p->next->next = p;    // 将节点链接在尾节点之后
    p->next = NULL;       // 尾节点next域置为NULL
}
int main() {
    LinkNode* L;
    char a[] = "12345678";
    int n = 8;
    CreateListR(L, a, n);
    printf("L：");
    DispList(L);
    printf("逆置L\n");
    Reverse(L->next, L);
    printf("L：");
    DispList(L);
    DestroyList(L);
    return 1;
}