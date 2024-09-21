#include <bits/stdc++.h>
using namespace std;
typedef struct Node {  // ������Ͷ���
    int data;
    struct Node* next;
} LinkNode;
void CreatLink(LinkNode*& List, int n) {  // ����ֵΪ1~n��n�����Ĳ���ͷ����ѭ��������
    if (n < 1) {
        printf("�ջ�������ʧ�ܣ�");
        return;
    }
    LinkNode *r, *s;  // rָ��β��㣬S��������ָ��
    List = (LinkNode*)malloc(sizeof(LinkNode));
    List->data = 1;
    List->next = List;
    r = List;
    for (int i = 2; i <= n; ++i) {  // β�巨���������µ�n-1�����
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = i;
        s->next = List;
        r->next = s;
        r = s;
    }
}
void PrintLink(LinkNode*& List) {  // ��ӡѭ���б�
    LinkNode* current = List;
    if (List == NULL)
        return;
    do {
        cout << current->data << "\t";
        current = current->next;
    } while (current != List);
    printf("\n");
}
void JosephRing(LinkNode*& List, int n, int m) {  // �ò���ͷ����ѭ�����������Լɪ��
    CreatLink(List, n);
    PrintLink(List);
    int number;         // number����ͳ�Ƴ�����������
    Node *current, *s;  // current��ǰ���ʽ���α꣬s���Ӻ�ɾ�����ĸ���ָ��
    s = current = List;
    while (s->next != List)  // ʹ��sָ��β��㣬Ϊɾ����׼��
        s = s->next;
    number = 0;
    // ģ�ⱨ������
    number = 0;
    while (number < n) {  // ��Ȧ��������n������������
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
void JosephRing(int* List, int n, int m) {  // ���������Լɪ��
    List = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)  // ��ʼ�������˾���Ȧ�ڣ���ֵ=1;
        List[i] = 1;
    int number = 0;       // �Ѿ���Ȧ����ͳ��
    int current = n - 1;  // current�����α꣬��ʼ��ָ�����һ����
    int count = 0;
    while (number < n) {  // ��Ȧ��������n
        // ģ�ⱨ��
        while (count < m) {
            current = (current + 1) % n;  // current�α���ǰ����֤��������ѭ��
            if (List[current] == 1)       // ��currentλ���ϵ���δ��Ȧ������뱨��
                ++count;
        }
        List[current] = 0;            // currentλ���ϵ����Ǳ�����m���ˣ���Ȧ����0
        printf("%d\t", current + 1);  // ����Ǳ���˵ı�����1
        ++number;
        count = 0;  // ׼����һ�ֵı���
    }
    free(List);
    return;
}
int main() {
    int n, m;  // count���ڱ���������number���ڳ�����������
    LinkNode* JosephLink;
    printf("����������n�ͱ�������m��\n");
    scanf("%d%d", &n, &m);

    /* ����ͷ����ѭ��������洢��Լɪ��������� */
    clock_t b, e;
    b = clock();
    JosephRing(JosephLink, n, m);
    e = clock();
    printf("\nʹ��ѭ��������洢ʱִ��ʱ�䣺%ld\n", e - b);

    /* ����洢��Լɪ��������� */
    int* p = NULL;
    b = clock();
    JosephRing(p, n, m);
    e = clock();
    printf("\nʹ������洢ʱִ��ʱ�䣺%ld\n", e - b);

    return 0;
}