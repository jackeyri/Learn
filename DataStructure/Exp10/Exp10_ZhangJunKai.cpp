// 二叉树的基本运算算法
#include <malloc.h>
#include <stdio.h>

#define MaxSize 100
typedef char ElemType;
typedef struct node {
    ElemType data;        // 数据元素
    struct node *lchild;  // 指向左孩子结点
    struct node *rchild;  // 指向右孩子结点
} BTNode;

// 方法1：根据结点的在完全二叉树中的层序编号创建二叉链表
void CreateBTree(int No[], ElemType da[], int n, BTNode *&root) {
    BTNode *s[MaxSize];
    BTNode *q;
    int i, j;
    for (i = 1; i <= n; i++) {
        q = (BTNode *) malloc(sizeof(BTNode));  // 动态申请空间，构造一个结点
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

// 方法2：借助完全二叉树形式和队列创建二叉链表
BTNode *CreateBTree() {
    BTNode *q[MaxSize];         // 定义q数组作为队列存放二叉链表中结点，MaxSize为最大容量
    BTNode *s;                  // 二叉链表中的结点
    BTNode *root = NULL;        // 二叉链表的根指针
    int front = -1, rear = -1;  // 定义队列的头、尾指针;
    char ch;                    // 结点的data域值
    scanf("%c", &ch);
    while (ch != '#') {  // 输入值为#号，算法结束
        s = NULL;
        if (ch != ',') {
            s = (BTNode *) malloc(sizeof(BTNode));  // 动态申请空间，构建一个结点
            s->data = ch;
            s->lchild = NULL;
            s->rchild = NULL;
        }
        rear++;
        q[rear] = s;  // 新结点或虚结点进队
        if (rear == 0)
            root = s;
        else {
            if (s != NULL && q[front + 1] != NULL) {  // rear为偶数，s为双亲左孩子
                if (rear % 2)
                    q[front + 1]->lchild = s;
                else
                    q[front + 1]->rchild = s;  // rear奇数，s为双亲右孩子
            }
            if (rear % 2 == 0)
                front++;  // 进队
        }
        scanf("%c", &ch);
    }  // while end
    return root;
}

// 方法3：借助二叉树的括号表示法和栈创建二叉链表
void CreateBTree(BTNode *&b, char *str) {  // 创建二叉树
    BTNode *St[MaxSize], *p = NULL;
    int top = -1, k, j = 0;
    char ch;
    b = NULL;  // 建立的二叉树初始时为空
    ch = str[j];
    while (ch != '\0') {  // str未扫描完时循环
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;  // 为左孩子结点
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;  // 为右孩子结点
            default:
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                if (b == NULL)  // *p为二叉树的根结点
                    b = p;
                else {  // 已建立二叉树根结点
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

// 以括号表示法输出二叉树
void DispBTree(BTNode *b) {  // 以括号表示法输出二叉树
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");           // 有孩子结点时才输出'('
            DispBTree(b->lchild);  // 递归处理左子树
            if (b->rchild != NULL)
                printf(",");       // 有右孩子结点时才输出','
            DispBTree(b->rchild);  // 递归处理右子树
            printf(")");           // 有孩子结点时才输出')'
        }
    }
}

// 销毁二叉树
void DestroyBTree(BTNode *&b) {
    if (b != NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

// 查找值为x的结点
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

// 求左孩子
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

// 求右孩子
BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

// 求二叉树b的高度
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == NULL)
        return 0;  // 空树的高度为0
    else {
        lchildh = BTHeight(b->lchild);  // 求左孩子的高度为lchildh
        rchildh = BTHeight(b->rchild);  // 求右孩子的高度为rchildh
        return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
    }
}

int main() {
    BTNode *root;

    /* 创建方法一测试 */
    /** int No[8] = {0, 1, 2, 4, 5, 10, 11, 22};
     * ElemType da[8] = {'#', 'A', 'B', 'C', 'D', 'E', 'F', 'G');
     * int n = 7;
     * CreateBTree(No, da, n, root);
     * DispBTree(root);
     * DestroyBTree(root);
     */

    /* 创建方法二测试 */
    /** AB, CD....EF..........G#
     * root = CreateBTree();
     * DispBTree(root);
     * DestroyBtree(root);
     */

    /* 创建方法三测试 */
    /**
     * A(B(C,D(E,F(G))))
     */
    char *str = "A(B(C,D(E,F(G))))";
    CreateBTree(root, str);

    printf("打印输出二叉树：");
    DispBTree(root);
    printf("\n");

    ElemType x = 'M';
    printf("\n在二叉树中查找：%c\n", x);
    BTNode *p = FindNode(root, x);
    if (p != NULL)
        printf("二叉树中 %c 存在！\n", p->data);
    else
        printf("二叉树中 %c 不存在！\n", x);

    printf("\n二叉树的高度是：%d\n", BTHeight(root));

    DestroyBTree(root);

    return 0;
}