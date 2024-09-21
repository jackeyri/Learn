// 二叉树的基本运算算法
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;
#define MaxSize 100
typedef char ElemType;
typedef struct node {
    ElemType data;        // 数据元素
    struct node *lchild;  // 指向左孩子结点
    struct node *rchild;  // 指向右孩子结点
} BTNode;

// 创建二叉链表方法1：根据结点的在完全二叉树中的层序编号创建二叉链表
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
            if (No[i] % 2 == 0) s[j]->lchild = q;
            else s[j]->rchild = q;
        }
    }
}

// 创建二叉链表方法2：借助完全二叉树形式和队列创建二叉链表
BTNode *CreateBTree() {
    BTNode *q[MaxSize];         // 定义q数组作为队列存放二叉链表中结点，MaxSize为最大容量
    BTNode *s;                  // 二叉链表中的结点
    BTNode *root = NULL;        // 二叉链表的根指针
    int front = -1, rear = -1;  // 定义队列的头、尾指针
    char ch;                    // 结点的data域值
    scanf("%c", &ch);
    while (ch != '#')  // 输入值为#号,算法结束
    {
        s = NULL;
        if (ch != ',') {
            s = (BTNode *) malloc(sizeof(BTNode));  // 动态申请空间，构造一个结点
            s->data = ch;
            s->lchild = NULL;
            s->rchild = NULL;
        }
        rear++;
        q[rear] = s;  // 新结点或虚结点进队
        if (rear == 0) root = s;
        else {
            if ((s != NULL) && (q[front + 1] != NULL)) {  // rear 为偶数, s为双亲左孩子
                if (rear % 2 == 1) q[front + 1]->lchild = s;
                else q[front + 1]->rchild = s;  // rear为奇数,s为双亲右孩子
            }
            if (rear % 2 == 0) front++;  // 出队
        }
        scanf("%c", &ch);
    }  // while end
    return root;
}

// 创建二叉链表方法3：借助二叉树的括号表示法和栈创建二叉链表
void CreateBTree(BTNode *&b, char *str)  // 创建二叉树
{
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
                break;  // 为孩子结点右结点
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

// 销毁二叉链表
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
    if (b == NULL) return (0);  // 空树的高度为0
    else {
        lchildh = BTHeight(b->lchild);  // 求左子树的高度为lchildh
        rchildh = BTHeight(b->rchild);  // 求右子树的高度为rchildh
        return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
    }
}

// 以括号表示法输出二叉树
void DispBTree(BTNode *b) {  // 以括号表示法输出二叉树
    if (b != NULL) {
        printf("%c", b->data);
        if (b->lchild != NULL || b->rchild != NULL) {
            printf("(");                         // 有孩子结点时才输出(
            DispBTree(b->lchild);             // 递归处理左子树
            if (b->rchild != NULL) printf(",");  // 有右孩子结点时才输出,
            DispBTree(b->rchild);             // 递归处理右子树
            printf(")");                         // 有孩子结点时才输出)
        }
    }
}

// 竖向打印二叉树，按右根左顺序，nLayer是b所在的层次
void PrintTree(BTNode *b, int nLayer) {
    if (b == NULL) return;
    PrintTree(b->rchild, nLayer + 1);
    for (int i = 0; i < nLayer; i++)
        printf("      ");
    printf("%c\n", b->data);
    PrintTree(b->lchild, nLayer + 1);
}

// 创建二叉链表方法4：扩展的前序遍历建立二叉链表
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

// 先序遍历的 递归 算法
void PreOrder(BTNode *b) {
    if (b != NULL) {
        printf("%c ", b->data);  // 访问根结点
        PreOrder(b->lchild);         // 递归访问左子树
        PreOrder(b->rchild);         // 递归访问右子树
    }
}

// 先序遍历的 非递归 算法1
void PreOrder1(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL) {
        top++;  // 根节点进栈
        St[top] = b;
        while (top > -1) {  // 栈不为空时循环
            p = St[top];    // 退栈并访问该结点
            top--;
            printf("%c ", p->data);
            if (p->rchild != NULL) {  // 有右孩子，将其进栈
                top++;
                St[top] = p->rchild;
            }
            if (p->lchild != NULL) {  // 有左孩子，将其进栈
                top++;
                St[top] = p->lchild;
            }
        }
        printf("\n");
    }
}

// 先序遍历的 非递归 算法2
void PreOrder2(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;  // 初始化栈
    p = b;
    while (top > -1 || p != NULL) {
        while (p != NULL) {          // 访问结点p及其所有左下结点并进栈
            printf("%c ", p->data);  // 访问结点p
            top++;                   // 结点p进栈
            St[top] = p;
            p = p->lchild;  // 移动到左孩子
        }
        // 以下考虑栈顶结点
        if (top > -1) {   // 若栈不空
            p = St[top];  // 出栈结点p
            top--;
            p = p->rchild;  // 转向处理其右子树
        }
    }
    printf("\n");
}

// 中序遍历的 递归 算法
void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder(b->lchild);      // 递归访问左子树
        printf("%c ", b->data);  // 访问根结点
        InOrder(b->rchild);      // 递归访问右子树
    }
}

// 中序遍历的 非递归 算法
void InOrder1(BTNode *b) {
    BTNode *St[MaxSize], *p;
    int top = -1;
    if (b != NULL) {
        p = b;
        while (top > -1 || p != NULL) {
            while (p != NULL) {  // 扫描结点p的所有左下结点并进栈
                top++;
                St[top] = p;
                p = p->lchild;
            }
            if (top > -1) {
                p = St[top];  // 出栈结点p并访问
                top--;
                printf("%c ", p->data);
                p = p->rchild;
            }
        }
        printf("\n");
    }
}

// 后序遍历的 递归 算法
void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);    // 递归访问左子树
        PostOrder(b->rchild);    // 递归访问右子树
        printf("%c ", b->data);  // 访问根结点
    }
}

// 后序遍历的 非递归 算法1
void PostOrder1(BTNode *b) {
    BTNode *St[MaxSize];
    BTNode *p;
    int top = -1;  // 栈指针置初值
    bool flag;
    if (b != NULL) {
        do {
            while (b != NULL) { // 将b结点的所有左下结点进栈
                top++;
                St[top] = b;
                b = b->lchild;
            }
            p = NULL;     // p指向当前结点的前一个已访问的结点
            flag = true;  // flag为真表示正在处理栈顶指针
            while (top != -1 && flag) {
                b = St[top];                 // 取出当前的栈顶指针
                if (b->rchild == p) {        // 右子树不存在或已被访问，访问之
                    printf("%c ", b->data);  // 访问b结点
                    top--;
                    p = b;  // p指向则被访问的结点
                } else {
                    b = b->rchild;  // b指向右子树
                    flag = false;   // 表示当前不是处理栈顶结点
                }
            }
        } while (top != -1);
        printf("\n");
    }
}

// 后序遍历的 非递归 算法2
void PostOrder2(BTNode *b) {  // 后序非递归遍历算法
    BTNode *p;
    BTNode *St[MaxSize];  // 定义一个顺序栈指针st
    int top = -1;         // 栈指针置初始值
    int flag[MaxSize];    // 标记第几次遇到
    p = b;
    do {
        while (p != NULL) {  // 扫描结点p的所有左下结点并进栈
            top++;
            St[top] = p;
            flag[top] = 1;  // 第一次遇见p
            p = p->lchild;  // 移动到左孩子
        }
        p = St[top];                 // 取出当前的栈顶结点p
        if (flag[top] == 2) {        // 第二次遇到p
            printf("%c ", p->data);  // 访问结点p
            top--;                   // p的左右子树都处理完，出栈
            p = NULL;
        } else {
            p = p->rchild;  // 转向处理其右子树
            flag[top] = 2;  // 下次遇到将是第二次了
        }
    } while (top != -1);  // 栈不空循环
    printf("\n");
}

// 层次遍历
void TravLevel(BTNode *b) {
    BTNode *Qu[MaxSize];  // 定义环形队列
    int front, rear;      // 定义队首和队尾指针
    front = rear = 0;     // 置队列为空队
    if (b != NULL)
        printf("%c ", b->data);
    rear++;  // 根结点进队
    Qu[rear] = b;
    while (rear != front) {  // 队列不为空
        front = (front + 1) % MaxSize;
        b = Qu[front];            // 出队结点b
        if (b->lchild != NULL) {  // 输出左孩子，并进队
            printf("%c ", b->lchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->lchild;
        }
        if (b->rchild != NULL) {  // 输出右孩子，并进队
            printf("%c ", b->rchild->data);
            rear = (rear + 1) % MaxSize;
            Qu[rear] = b->rchild;
        }
    }
    printf("\n");
}