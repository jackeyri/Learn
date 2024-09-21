#include <bits/stdc++.h>
using namespace std;
typedef char ElemType;

typedef struct {
    ElemType data[50];  // ˳���Ԫ��
    int length;         // ˳���ĳ���
} SqList;

void CreateList(SqList*& L, ElemType a[], int n) {  // ���彨��˳���
    L = (SqList*)malloc(sizeof(SqList));
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
}

void InitList(SqList*& L) {               // ��ʼ�����Ա�
    L = (SqList*)malloc(sizeof(SqList));  // ���������Ա�Ŀռ�
    L->length = 0;
}

void DestroyList(SqList*& L) {  // �������Ա�
    free(L);
}

bool ListEmpty(SqList* L) {  // �����Ա��Ƿ�Ϊ�ձ�
    return L->length == 0;
}

int ListLength(SqList* L) {  //  �����Ա�ĳ���
    return L->length;
}

void DispList(SqList* L) {  // ������Ա�
    for (int i = 0; i < L->length; ++i)
        printf(" %c" + !i, L->data[i]);
    printf("\n");
}

bool GetElem(SqList* L, int i, ElemType& e) {  // �����Ա��е�i��Ԫ��ֵ
    if (i < 1 || i > L->length)
        return false;
    e = L->data[i - 1];
    return true;
}

int LocateElem(SqList* L, ElemType e) {  // ���ҵ�һ��ֵ��Ϊe��Ԫ�����
    int i = 0;
    while (i < L->length && L->data[i] != e)
        i++;
    return i >= L->length ? 0 : i + 1;
}

bool ListInsert(SqList*& L, int i, ElemType e) {  // �����i��Ԫ��
    if (i < 1 || i > L->length + 1)
        return false;
    --i;                                 // ��˳���λ��ת��Ϊelem�±�
    for (int j = L->length; j > i; --j)  // ��data[i]������Ԫ�غ���һ��λ��
        L->data[j] = L->data[j - 1];
    L->data[i] = e;
    ++L->length;  // ˳�������1
    return true;
}

bool ListDelete(SqList*& L, int i, ElemType& e) {  // ɾ����i��Ԫ��
    if (i < 1 || i > L->length)
        return false;
    e = L->data[--i];                        // ��˳���λ��ת��Ϊelem�±�
    for (int j = i; j < L->length - 1; ++j)  // ��data[i]֮���Ԫ��ǰ��һ��λ��
        L->data[j] = L->data[j + 1];
    --L->length;  // ˳����ȼ�1
    return true;
}

int main() {
    SqList* L;
    ElemType e;

    /* ��ʼ��˳���L */
    printf("��ʼ��˳���L\n");
    InitList(L);

    /* ���β���a,b,c,d,eԪ�� */
    printf("���β���a,b,c,d,eԪ��\n");
    ListInsert(L, 1, 'a');
    ListInsert(L, 2, 'b');
    ListInsert(L, 3, 'c');
    ListInsert(L, 4, 'd');
    ListInsert(L, 5, 'e');

    /* ���˳���L */
    printf("���˳���L��");
    DispList(L);

    /* ���˳���L���� */
    printf("˳���L����:%d\n", ListLength(L));

    /* �ж�˳���L�Ƿ�Ϊ�� */
    printf("˳���LΪ%s\n", (ListEmpty(L) ? "��" : "�ǿ�"));

    /* ���˳���L�ĵ�3��Ԫ�� */
    GetElem(L, 3, e);
    printf("˳���L�ĵ�3��Ԫ��:%c\n", e);

    /* ����Ԫ��a��λ�� */
    printf("Ԫ��a��λ��:%d\n", LocateElem(L, 'a'));

    /* �ڵ�4��Ԫ��λ���ϲ���fԪ�� */
    printf("�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
    ListInsert(L, 4, 'f');

    /* ���˳���L */
    printf("���˳���L��");
    DispList(L);

    /* ɾ��˳���L�ĵ�3��Ԫ�� */
    printf("ɾ��˳���L�ĵ�3��Ԫ��\n");
    ListDelete(L, 3, e);

    /* ���˳���L */
    printf("���˳���L��");
    DispList(L);

    /* �ͷ�˳���L */
    printf("�ͷ�˳���L\n");
    DestroyList(L);

    return 0;
}