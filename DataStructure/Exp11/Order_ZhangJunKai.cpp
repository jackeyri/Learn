#include "btree_ZhangJunKai.h"

int main() {
    BTNode *b;
    CreateBiTree(b);  // ��ʾ��ABD..EHJ..KL..M.N...CF..G.I..
    printf("������b:");
    DispBTree(b);
    printf("\n");
    printf("��α�������:");
    TravLevel(b);
    printf("�����������:\n");
    printf("    �ݹ��㷨:");
    PreOrder(b);
    printf("\n");
    printf(" �ǵݹ��㷨1:");
    PreOrder1(b);
    printf(" �ǵݹ��㷨2:");
    PreOrder2(b);
    printf("�����������:\n");
    printf("    �ݹ��㷨:");
    InOrder(b);
    printf("\n");
    printf("  �ǵݹ��㷨:");
    InOrder1(b);
    printf("�����������:\n");
    printf("    �ݹ��㷨:");
    PostOrder(b);
    printf("\n");
    printf(" �ǵݹ��㷨1:");
    PostOrder1(b);
    printf(" �ǵݹ��㷨2:");
    PostOrder2(b);
    DestroyBTree(b);
    return 1;
}