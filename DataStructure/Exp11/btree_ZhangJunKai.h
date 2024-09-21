// �������Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct node {
    ElemType data;        // ����Ԫ��
    struct node *lchild;  // ָ�����ӽ��
    struct node *rchild;  // ָ���Һ��ӽ��
} BTNode;

// ��������������1�����ݽ�������ȫ�������еĲ����Ŵ�����������
void CreateBTree(int No[], ElemType da[], int n, BTNode *&root) {
    BTNode *s[MaxSize];
    BTNode *q;
    int i, j;
    for (i = 1; i <= n; i++) {
        q = (BTNode *) malloc(sizeof(BTNode));  // ��̬����ռ䣬����һ�����
        q->data = da[i];
        q->lchild = NULL;
        q->rchild = NULL;
        s[No[i]] = q;
        if (No[i] == 1)
            root = q;
        else {
            j = No[i] / 2;
            if (No[i] % 2 == 0) s[j]->lchild = q;
            else s[j]->rchild = q;
        }
    }
}

// ��������������2��������ȫ��������ʽ�Ͷ��д�����������
BTNode *CreateBTree() {
    BTNode *q[MaxSize];         // ����q������Ϊ���д�Ŷ��������н�㣬MaxSizeΪ�������
    BTNode *s;                  // ���������еĽ��
    BTNode *root = NULL;        // ��������ĸ�ָ��
    int front = -1, rear = -1;  // ������е�ͷ��βָ��
    char ch;                    // ����data��ֵ
    scanf("%c", &ch);
    while (ch != '#')  // ����ֵΪ#��,�㷨����
    {
        s = NULL;
        if (ch != ',') {
            s = (BTNode *) malloc(sizeof(BTNode));  // ��̬����ռ䣬����һ�����
            s->data = ch;
            s->lchild = NULL;
            s->rchild = NULL;
        }
        rear++;
        q[rear] = s;  // �½����������
        if (rear == 0) root = s;
        else {
            if ((s != NULL) && (q[front + 1] != NULL)) {  // rear Ϊż��, sΪ˫������
                if (rear % 2 == 1) q[front + 1]->lchild = s;
                else q[front + 1]->rchild = s;  // rearΪ����,sΪ˫���Һ���
            }
            if (rear % 2 == 0) front++;  // ����
        }
        scanf("%c", &ch);
    }  // while end
    return root;
}

// ��������������3�����������������ű�ʾ����ջ������������
void CreateBTree(BTNode *&b, char *str)  // ����������
{
    BTNode *St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;  // �����Ķ�������ʼʱΪ��
    ch = str[j];
    while (ch != '\0') {  // strδɨ����ʱѭ��
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;  // Ϊ���ӽ��
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;  // Ϊ���ӽ���ҽ��
            default:
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (b == NULL)  // *pΪ�������ĸ����
                    b = p;
                else {  // �ѽ��������������
                    switch (k) {
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                    }
                }
        }
        j++;
        ch = str[j];
    }
}

// ���ٶ�������
void DestroyBTree(BTNode *&b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

// ����ֵΪx�Ľ��
BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p;
    if (b == NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else {
        p = FindNode(b->lchild, x);
        if (p != NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

// ������
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

// ���Һ���
BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

// �������b�ĸ߶�
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == NULL) return (0);  // �����ĸ߶�Ϊ0
    else {
        lchildh = BTHeight(b->lchild);  // ���������ĸ߶�Ϊlchildh
        rchildh = BTHeight(b->rchild);  // ���������ĸ߶�Ϊrchildh
        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
    }
}

// �����ű�ʾ�����������
void DispBTree(BTNode *b) {  // �����ű�ʾ�����������
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");                         // �к��ӽ��ʱ�����(
            DispBTree(b->lchild);             // �ݹ鴦��������
            if (b->rchild != NULL) printf(",");  // ���Һ��ӽ��ʱ�����,
            DispBTree(b->rchild);             // �ݹ鴦��������
            printf(")");                         // �к��ӽ��ʱ�����)
        }
    }
}

// �����ӡ�����������Ҹ���˳��nLayer��b���ڵĲ��
void PrintTree(BTNode *b, int nLayer) {
    if (b == NULL) return;
    PrintTree(b->rchild, nLayer + 1);
    for (int i = 0; i < nLayer; i++)
        printf("      ");
    printf("%c\n", b->data);
    PrintTree(b->lchild, nLayer + 1);
}

// ��������������4����չ��ǰ�����������������
void CreateBiTree(BTNode *&b) {
    char ch = getchar();
    if (ch == '.')
        b = NULL;
    else {
        b = (BTNode *) malloc(sizeof(BTNode));
        b->data = ch;
        CreateBiTree(b->lchild);
        CreateBiTree(b->rchild);
    }
}

// ��������� �ݹ� �㷨
void PreOrder(BTNode *b) {
    if (b != NULL) {
        printf("%c ", b->data);  // ���ʸ����
        PreOrder(b->lchild);         // �ݹ����������
        PreOrder(b->rchild);         // �ݹ����������
    }
}

// ��������� �ǵݹ� �㷨1
void PreOrder1(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL) {
        top++;  // ���ڵ��ջ
        St[top] = b;
        while (top > -1) {  // ջ��Ϊ��ʱѭ��
            p = St[top];    // ��ջ�����ʸý��
            top--;
            printf("%c ", p->data);
            if (p->rchild != NULL) {  // ���Һ��ӣ������ջ
                top++;
                St[top] = p->rchild;
            }
            if (p->lchild != NULL) {  // �����ӣ������ջ
                top++;
                St[top] = p->lchild;
            }
        }
        printf("\n");
    }
}

// ��������� �ǵݹ� �㷨2
void PreOrder2(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;  // ��ʼ��ջ
    p = b;
    while (top > -1 || p != NULL) {
        while (p != NULL) {          // ���ʽ��p�����������½�㲢��ջ
            printf("%c ", p->data);  // ���ʽ��p
            top++;                   // ���p��ջ
            St[top] = p;
            p = p->lchild;  // �ƶ�������
        }
        // ���¿���ջ�����
        if (top > -1) {   // ��ջ����
            p = St[top];  // ��ջ���p
            top--;
            p = p->rchild;  // ת������������
        }
    }
    printf("\n");
}

// ��������� �ݹ� �㷨
void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder(b->lchild);      // �ݹ����������
        printf("%c ", b->data);  // ���ʸ����
        InOrder(b->rchild);      // �ݹ����������
    }
}

// ��������� �ǵݹ� �㷨
void InOrder1(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL) {
        p = b;
        while (top > -1 || p != NULL) {
            while (p != NULL) {  // ɨ����p���������½�㲢��ջ
                top++;
                St[top] = p;
                p = p->lchild;
            }
            if (top > -1) {
                p = St[top];  // ��ջ���p������
                top--;
                printf("%c ", p->data);
                p = p->rchild;
            }
        }
        printf("\n");
    }
}

// ��������� �ݹ� �㷨
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);    // �ݹ����������
        PostOrder(b->rchild);    // �ݹ����������
        printf("%c ", b->data);  // ���ʸ����
    }
}

// ��������� �ǵݹ� �㷨1
void PostOrder1(BTNode *b) {
    BTNode *St[MaxSize];
    BTNode *p;
    int top = -1;  // ջָ���ó�ֵ
    bool flag;
    if (b != NULL) {
        do {
            while (b != NULL) { // ��b�����������½���ջ
                top++;
                St[top] = b;
                b = b->lchild;
            }
            p = NULL;     // pָ��ǰ����ǰһ���ѷ��ʵĽ��
            flag = true;  // flagΪ���ʾ���ڴ���ջ��ָ��
            while (top != -1 && flag) {
                b = St[top];                 // ȡ����ǰ��ջ��ָ��
                if (b->rchild == p) {        // �����������ڻ��ѱ����ʣ�����֮
                    printf("%c ", b->data);  // ����b���
                    top--;
                    p = b;  // pָ���򱻷��ʵĽ��
                } else {
                    b = b->rchild;  // bָ��������
                    flag = false;   // ��ʾ��ǰ���Ǵ���ջ�����
                }
            }
        } while (top != -1);
        printf("\n");
    }
}

// ��������� �ǵݹ� �㷨2
void PostOrder2(BTNode *b) {  // ����ǵݹ�����㷨
    BTNode *p;
    BTNode *St[MaxSize];  // ����һ��˳��ջָ��st
    int top = -1;         // ջָ���ó�ʼֵ
    int flag[MaxSize];    // ��ǵڼ�������
    p = b;
    do {
        while (p != NULL) {  // ɨ����p���������½�㲢��ջ
            top++;
            St[top] = p;
            flag[top] = 1;  // ��һ������p
            p = p->lchild;  // �ƶ�������
        }
        p = St[top];                 // ȡ����ǰ��ջ�����p
        if (flag[top] == 2) {        // �ڶ�������p
            printf("%c ", p->data);  // ���ʽ��p
            top--;                   // p�����������������꣬��ջ
            p = NULL;
        } else {
            p = p->rchild;  // ת������������
            flag[top] = 2;  // �´��������ǵڶ�����
        }
    } while (top != -1);  // ջ����ѭ��
    printf("\n");
}

// ��α���
void TravLevel(BTNode *b) {
    BTNode *Qu[MaxSize];  // ���廷�ζ���
    int front, rear;      // ������׺Ͷ�βָ��
    front = rear = 0;     // �ö���Ϊ�ն�
    if (b != NULL)
        printf("%c ", b->data);
    rear++;  // ��������
    Qu[rear] = b;
    while (rear != front) {  // ���в�Ϊ��
        front = (front + 1) % MaxSize;
        b = Qu[front];            // ���ӽ��b
        if (b->lchild != NULL) {  // ������ӣ�������
            printf("%c ", b->lchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->lchild;
        }
        if (b->rchild != NULL) {  // ����Һ��ӣ�������
            printf("%c ", b->rchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->rchild;
        }
    }
    printf("\n");
}