#include <malloc.h>
#include <cstdio>

#define MaxSize 100
typedef int KeyType;  // 定义关键字类型
KeyType predt = -32767;  // 保存当前节点中序前驱的值，初值为-∞（二叉排序树按照中序遍历，是递增序列）
typedef char InfoType;
typedef struct node {              // 记录类型
    KeyType key;                   // 关键字项
    InfoType data;                 // 其它数据域
    struct node *lchild, *rchild;  // 左右孩子指针
} BSTNode;

/**
 * 在以bt为根节点的BST中插入一个关键字为k的节点
 * @param bt
 * @param k
 * @return
 */
bool InsertBST(BSTNode *&bt, KeyType k) {
    if (bt == nullptr) {  // 原树为空，新插入的记录为根节点
        bt = (BSTNode *) malloc(sizeof(BSTNode));
        bt->key = k;
        bt->lchild = bt->rchild = nullptr;
        return true;
    } else if (k == bt->key)
        return false;
    else if (k < bt->key)
        return InsertBST(bt->lchild, k);  // 插入到bt节点的左子树中
    else
        return InsertBST(bt->rchild, k);  // 插入到bt节点的右子树中
}

/**
 * 以括号表示法输出二叉排序树bt
 * @param bt
 */
void DisplayBST(BSTNode *bt) {
    if (bt != nullptr) {
        printf("%d", bt->key);
        if (bt->lchild != nullptr || bt->rchild != nullptr) {
            printf("(");
            DisplayBST(bt->lchild);
            if (bt->rchild != nullptr) {
                printf(",");
            }
            DisplayBST(bt->rchild);
            printf(")");
        }
    }
}

/**
 * 由数组A中的关键字建立一颗二叉排序树
 * @param A
 * @param n
 * @return
 */
BSTNode *CreateBST(KeyType A[], int n) {
    BSTNode *bt = nullptr;  // 初始时bt为空树
    int i = 0;
    while (i < n)
        if (InsertBST(bt, A[i]) == 1) {  // 将A[i]插入二叉排序树T中
            printf("    第%d步，插入%d：", i + 1, A[i]);
            DisplayBST(bt);
            printf("\n");
            ++i;
        }
    return bt;  // 返回建立的二叉排序树的根指针
}

/**
 * 被删节点p有左、右子树，r指向其左孩子
 * @param p
 * @param r
 */
void Delete1(BSTNode *p, BSTNode *&r) {
    BSTNode *q;
    if (r->rchild != nullptr)  // 递归找节点r的最右下节点
        Delete1(p, r->rchild);
    else {                // 找到了最右下节点r（它没有右子树）
        p->key = r->key;  // 将节点r的值存放到节点p中（节点值替代）
        p->data = r->data;
        q = r;          // 删除节点r
        r = r->lchild;  // 即用节点r的左孩子替代它
        free(q);        // 释放节点r的空间
    }
}

/**
 * 从二叉排序树中删除p节点
 * @param p
 */
void Delete(BSTNode *&p) {
    BSTNode *q;
    if (p->rchild == nullptr) {  // p节点没有右子树的情况
        q = p;
        p = p->lchild;
        free(q);
    } else if (p->lchild == nullptr) {  // p节点没有左子树的情况
        q = p;
        p = p->rchild;
        free(q);
    } else  // p节点既有左子树又有右子树的情况
        Delete1(p, p->lchild);
}

/**
 * 在bt中删除关键字为k的节点
 * @param bt
 * @param k
 * @return
 */
bool DeleteBST(BSTNode *&bt, KeyType k) {
    if (bt == nullptr)
        return false;  // 空树删除失败
    else {
        if (k < bt->key)
            return DeleteBST(bt->lchild, k);  // 递归在左子树中删除关键字为k的节点
        else if (k > bt->key)
            return DeleteBST(bt->rchild, k);  // 递归在右子树中删除关键字为k的节点
        else {                    // k = bt->key的情况
            Delete(bt);           // 调用Delete(bt)函数删除bt节点
            return true;
        }
    }
}

/**
 * 以递归方式输出从根节点到查找到的节点的路径
 * @param bt
 * @param k
 * @return
 */
int SearchBST(BSTNode *bt, KeyType k) {
    if (bt == nullptr)
        return 0;
    else {
        printf("%3d", bt->key);
        if (k == bt->key)
            return 1;
        else if (k < bt->key)
            SearchBST(bt->lchild, k);  // 在左子树中递归查找
        else
            SearchBST(bt->rchild, k);  // 在右子树中递归查找
    }
}

/**
 * 以递归方式输出从根节点到查找到的节点的路径
 * @param bt
 * @param k
 * @param path
 * @param i
 */
void SearchBST1(BSTNode *bt, KeyType k, KeyType path[], int i) {
    if (bt == nullptr)
        return;
    else if (k == bt->key) {    // 找到了节点
        path[i + 1] = bt->key;  // 输出其路径
        for (int j = 0; j <= i + 1; ++j) {
            printf("%3d", path[j]);
        }
        printf("\n");
    } else {
        path[i + 1] = bt->key;
        if (k < bt->key) {
            SearchBST1(bt->lchild, k, path, i + 1);  // 在左子树中递归查找
        } else {
            SearchBST1(bt->rchild, k, path, i + 1);  // 在右子树中递归查找
        }
    }
}

/**
 * 判断bt是否为BST
 * @param bt
 * @return
 */
bool JudgeBST(BSTNode *bt) {
    bool b1, b2;
    if (bt == nullptr) {
        return true;
    } else {
        b1 = JudgeBST(bt->lchild);
        if (!b1 || bt->key <= predt) {
            return false;
        }
        predt = bt->key;
        b2 = JudgeBST(bt->rchild);
        return b2;
    }
}

/**
 * 销毁一颗BST
 * @param bt
 */
void DestroyBST(BSTNode *bt) {
    if (bt != nullptr) {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}

int main() {
    BSTNode *bt;
    int path[MaxSize];
    KeyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    printf("（1）创建一颗BST树：\n");
    bt = CreateBST(a, n);
    printf("（2）BST：");
    DisplayBST(bt);
    printf("\n");
    // printf("（3）bt%s\n", JudgeBST(bt) ? "是一颗BST" : "不是一颗BST");
    // printf("（4）查找%d关键字：", k);
    // SearchBST1(bt, k, path, -1);
    printf("（3）查找%d关键字：", k);
    SearchBST(bt, k);
    // printf("\n（5）删除操作：\n");
    // printf("    原BST：");
    // DisplayBST(bt);
    // printf("\n");
    // printf("    删除节点4：");
    // DeleteBST(bt, 4);
    // DisplayBST(bt);
    // printf("\n");
    // printf("    删除节点5：");
    // DisplayBST(bt);
    // printf("\n");
    printf("\n（4）销毁BST\n");
    DestroyBST(bt);
    return 1;
}