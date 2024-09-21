#include <malloc.h>
#include <cstdio>

#define MaxSize 100
typedef int KeyType;  // ����ؼ�������
KeyType predt = -32767;  // ���浱ǰ�ڵ�����ǰ����ֵ����ֵΪ-�ޣ�������������������������ǵ������У�
typedef char InfoType;
typedef struct node {              // ��¼����
    KeyType key;                   // �ؼ�����
    InfoType data;                 // ����������
    struct node *lchild, *rchild;  // ���Һ���ָ��
} BSTNode;

/**
 * ����btΪ���ڵ��BST�в���һ���ؼ���Ϊk�Ľڵ�
 * @param bt
 * @param k
 * @return
 */
bool InsertBST(BSTNode *&bt, KeyType k) {
    if (bt == nullptr) {  // ԭ��Ϊ�գ��²���ļ�¼Ϊ���ڵ�
        bt = (BSTNode *) malloc(sizeof(BSTNode));
        bt->key = k;
        bt->lchild = bt->rchild = nullptr;
        return true;
    } else if (k == bt->key)
        return false;
    else if (k < bt->key)
        return InsertBST(bt->lchild, k);  // ���뵽bt�ڵ����������
    else
        return InsertBST(bt->rchild, k);  // ���뵽bt�ڵ����������
}

/**
 * �����ű�ʾ���������������bt
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
 * ������A�еĹؼ��ֽ���һ�Ŷ���������
 * @param A
 * @param n
 * @return
 */
BSTNode *CreateBST(KeyType A[], int n) {
    BSTNode *bt = nullptr;  // ��ʼʱbtΪ����
    int i = 0;
    while (i < n)
        if (InsertBST(bt, A[i]) == 1) {  // ��A[i]�������������T��
            printf("    ��%d��������%d��", i + 1, A[i]);
            DisplayBST(bt);
            printf("\n");
            ++i;
        }
    return bt;  // ���ؽ����Ķ����������ĸ�ָ��
}

/**
 * ��ɾ�ڵ�p������������rָ��������
 * @param p
 * @param r
 */
void Delete1(BSTNode *p, BSTNode *&r) {
    BSTNode *q;
    if (r->rchild != nullptr)  // �ݹ��ҽڵ�r�������½ڵ�
        Delete1(p, r->rchild);
    else {                // �ҵ��������½ڵ�r����û����������
        p->key = r->key;  // ���ڵ�r��ֵ��ŵ��ڵ�p�У��ڵ�ֵ�����
        p->data = r->data;
        q = r;          // ɾ���ڵ�r
        r = r->lchild;  // ���ýڵ�r�����������
        free(q);        // �ͷŽڵ�r�Ŀռ�
    }
}

/**
 * �Ӷ�����������ɾ��p�ڵ�
 * @param p
 */
void Delete(BSTNode *&p) {
    BSTNode *q;
    if (p->rchild == nullptr) {  // p�ڵ�û�������������
        q = p;
        p = p->lchild;
        free(q);
    } else if (p->lchild == nullptr) {  // p�ڵ�û�������������
        q = p;
        p = p->rchild;
        free(q);
    } else  // p�ڵ�������������������������
        Delete1(p, p->lchild);
}

/**
 * ��bt��ɾ���ؼ���Ϊk�Ľڵ�
 * @param bt
 * @param k
 * @return
 */
bool DeleteBST(BSTNode *&bt, KeyType k) {
    if (bt == nullptr)
        return false;  // ����ɾ��ʧ��
    else {
        if (k < bt->key)
            return DeleteBST(bt->lchild, k);  // �ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
        else if (k > bt->key)
            return DeleteBST(bt->rchild, k);  // �ݹ�����������ɾ���ؼ���Ϊk�Ľڵ�
        else {                    // k = bt->key�����
            Delete(bt);           // ����Delete(bt)����ɾ��bt�ڵ�
            return true;
        }
    }
}

/**
 * �Եݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
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
            SearchBST(bt->lchild, k);  // ���������еݹ����
        else
            SearchBST(bt->rchild, k);  // ���������еݹ����
    }
}

/**
 * �Եݹ鷽ʽ����Ӹ��ڵ㵽���ҵ��Ľڵ��·��
 * @param bt
 * @param k
 * @param path
 * @param i
 */
void SearchBST1(BSTNode *bt, KeyType k, KeyType path[], int i) {
    if (bt == nullptr)
        return;
    else if (k == bt->key) {    // �ҵ��˽ڵ�
        path[i + 1] = bt->key;  // �����·��
        for (int j = 0; j <= i + 1; ++j) {
            printf("%3d", path[j]);
        }
        printf("\n");
    } else {
        path[i + 1] = bt->key;
        if (k < bt->key) {
            SearchBST1(bt->lchild, k, path, i + 1);  // ���������еݹ����
        } else {
            SearchBST1(bt->rchild, k, path, i + 1);  // ���������еݹ����
        }
    }
}

/**
 * �ж�bt�Ƿ�ΪBST
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
 * ����һ��BST
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
    printf("��1������һ��BST����\n");
    bt = CreateBST(a, n);
    printf("��2��BST��");
    DisplayBST(bt);
    printf("\n");
    // printf("��3��bt%s\n", JudgeBST(bt) ? "��һ��BST" : "����һ��BST");
    // printf("��4������%d�ؼ��֣�", k);
    // SearchBST1(bt, k, path, -1);
    printf("��3������%d�ؼ��֣�", k);
    SearchBST(bt, k);
    // printf("\n��5��ɾ��������\n");
    // printf("    ԭBST��");
    // DisplayBST(bt);
    // printf("\n");
    // printf("    ɾ���ڵ�4��");
    // DeleteBST(bt, 4);
    // DisplayBST(bt);
    // printf("\n");
    // printf("    ɾ���ڵ�5��");
    // DisplayBST(bt);
    // printf("\n");
    printf("\n��4������BST\n");
    DestroyBST(bt);
    return 1;
}