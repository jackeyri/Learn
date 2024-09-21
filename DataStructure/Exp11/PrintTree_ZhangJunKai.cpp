#include "btree_ZhangJunKai.h"

// 竖向打印二叉树，按右根左顺序，nLayer是b所在的层次
void PrintTree2(BTNode *b, int nLayer) {
    if (b == NULL)
        return;
    PrintTree2(b->rchild, nLayer + 1);
    for (int i = 0; i < nLayer; i++)
        printf("----------");
    printf("%c\n", b->data);
    PrintTree2(b->lchild, nLayer + 1);
}

int main() {
    BTNode *b;
    CreateBiTree(b);  // 提示：ABD..EHJ..KL..M.N...CF..G.I..

    printf("竖向打印二叉树b:\n");
    PrintTree2(b, 0);

    DestroyBTree(b);
    return 1;
}