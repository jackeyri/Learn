#include "btree_ZhangJunKai.h"

// �����ӡ�����������Ҹ���˳��nLayer��b���ڵĲ��
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
    CreateBiTree(b);  // ��ʾ��ABD..EHJ..KL..M.N...CF..G.I..

    printf("�����ӡ������b:\n");
    PrintTree2(b, 0);

    DestroyBTree(b);
    return 1;
}