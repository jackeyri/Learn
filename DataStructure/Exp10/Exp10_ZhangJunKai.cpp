// �������Ļ��������㷨
#include <malloc.h>
#include <stdio.h>

#define MaxSize 100
typedef char ElemType;
typedef struct node {
    ElemType data;        // ����Ԫ��
    struct node *lchild;  // ָ�����ӽ��
    struct node *rchild;  // ָ���Һ��ӽ��
} BTNode;

// ����1�����ݽ�������ȫ�������еĲ����Ŵ�����������
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
            if (No[i] % 2 == 0)
                s[j]->lchild = q;
            else
                s[j]->rchild = q;
        }
    }
}

// ����2��������ȫ��������ʽ�Ͷ��д�����������
BTNode *CreateBTree() {
    BTNode *q[MaxSize];         // ����q������Ϊ���д�Ŷ��������н�㣬MaxSizeΪ�������
    BTNode *s;                  // ���������еĽ��
    BTNode *root = NULL;        // ��������ĸ�ָ��
    int front = -1, rear = -1;  // ������е�ͷ��βָ��;
    char ch;                    // ����data��ֵ
    scanf("%c", &ch);
    while (ch != '#') {  // ����ֵΪ#�ţ��㷨����
        s = NULL;
        if (ch != ',') {
            s = (BTNode *) malloc(sizeof(BTNode));  // ��̬����ռ䣬����һ�����
            s->data = ch;
            s->lchild = NULL;
            s->rchild = NULL;
        }
        rear++;
        q[rear] = s;  // �½����������
        if (rear == 0)
            root = s;
        else {
            if (s != NULL && q[front + 1] != NULL) {  // rearΪż����sΪ˫������
                if (rear % 2)
                    q[front + 1]->lchild = s;
                else
                    q[front + 1]->rchild = s;  // rear������sΪ˫���Һ���
            }
            if (rear % 2 == 0)
                front++;  // ����
        }
        scanf("%c", &ch);
    }  // while end
    return root;
}

// ����3�����������������ű�ʾ����ջ������������
void CreateBTree(BTNode *&b, char *str) {  // ����������
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
                break;  // Ϊ�Һ��ӽ��
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

// �����ű�ʾ�����������
void DispBTree(BTNode *b) {  // �����ű�ʾ�����������
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");           // �к��ӽ��ʱ�����'('
            DispBTree(b->lchild);  // �ݹ鴦��������
            if (b->rchild != NULL)
                printf(",");       // ���Һ��ӽ��ʱ�����','
            DispBTree(b->rchild);  // �ݹ鴦��������
            printf(")");           // �к��ӽ��ʱ�����')'
        }
    }
}

// ���ٶ�����
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
    if (b == NULL)
        return 0;  // �����ĸ߶�Ϊ0
    else {
        lchildh = BTHeight(b->lchild);  // �����ӵĸ߶�Ϊlchildh
        rchildh = BTHeight(b->rchild);  // ���Һ��ӵĸ߶�Ϊrchildh
        return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
    }
}

int main() {
    BTNode *root;

    /* ��������һ���� */
    /** int No[8] = {0, 1, 2, 4, 5, 10, 11, 22};
     * ElemType da[8] = {'#', 'A', 'B', 'C', 'D', 'E', 'F', 'G');
     * int n = 7;
     * CreateBTree(No, da, n, root);
     * DispBTree(root);
     * DestroyBTree(root);
     */

    /* �������������� */
    /** AB, CD....EF..........G#
     * root = CreateBTree();
     * DispBTree(root);
     * DestroyBtree(root);
     */

    /* �������������� */
    /**
     * A(B(C,D(E,F(G))))
     */
    char *str = "A(B(C,D(E,F(G))))";
    CreateBTree(root, str);

    printf("��ӡ�����������");
    DispBTree(root);
    printf("\n");

    ElemType x = 'M';
    printf("\n�ڶ������в��ң�%c\n", x);
    BTNode *p = FindNode(root, x);
    if (p != NULL)
        printf("�������� %c ���ڣ�\n", p->data);
    else
        printf("�������� %c �����ڣ�\n", x);

    printf("\n�������ĸ߶��ǣ�%d\n", BTHeight(root));

    DestroyBTree(root);

    return 0;
}