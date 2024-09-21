// �õݹ��㷨����һ����ͷ���ĵ�����
// �㷨˼�룺Reverse(p, L)�Ǵ����⣬����Ϊ������pΪ�׽ڵ�ĵ��������ú�ָ��β���
// Reverse(p->next, L)��С���⣬����Ϊ������p->next��Ϊ�׽ڵ�ĵ��������ú�p->nextָ��β���
#include "linklist_ZhangJunKai.h"  // ����������Ļ��������㷨
void Reverse(LinkNode* p, LinkNode*& L) {
    if (p->next == NULL) {  // ��pΪ�׽ڵ�ָ��ĵ�����ֻ��һ���ڵ�ʱ
        L->next = p;
        return;
    }
    Reverse(p->next, L);  // ���ú��β�ڵ���p->next
    p->next->next = p;    // ���ڵ�������β�ڵ�֮��
    p->next = NULL;       // β�ڵ�next����ΪNULL
}
int main() {
    LinkNode* L;
    char a[] = "12345678";
    int n = 8;
    CreateListR(L, a, n);
    printf("L��");
    DispList(L);
    printf("����L\n");
    Reverse(L->next, L);
    printf("L��");
    DispList(L);
    DestroyList(L);
    return 1;
}