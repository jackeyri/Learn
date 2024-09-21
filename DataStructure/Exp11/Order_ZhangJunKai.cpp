#include "btree_ZhangJunKai.h"

int main() {
    BTNode *b;
    CreateBiTree(b);  // 提示：ABD..EHJ..KL..M.N...CF..G.I..
    printf("二叉树b:");
    DispBTree(b);
    printf("\n");
    printf("层次遍历序列:");
    TravLevel(b);
    printf("先序遍历序列:\n");
    printf("    递归算法:");
    PreOrder(b);
    printf("\n");
    printf(" 非递归算法1:");
    PreOrder1(b);
    printf(" 非递归算法2:");
    PreOrder2(b);
    printf("中序遍历序列:\n");
    printf("    递归算法:");
    InOrder(b);
    printf("\n");
    printf("  非递归算法:");
    InOrder1(b);
    printf("后序遍历序列:\n");
    printf("    递归算法:");
    PostOrder(b);
    printf("\n");
    printf(" 非递归算法1:");
    PostOrder1(b);
    printf(" 非递归算法2:");
    PostOrder2(b);
    DestroyBTree(b);
    return 1;
}