#include <bits/stdc++.h>
using namespace std;
typedef struct student {
    long ID;       // ѧ��
    char Name[9];  // ����
    char Sex[3];   // �Ա�
    int English;   // Ӣ��ɼ�
    int Computer;  // ������ɼ�
    int Math;      // �����ɼ�
    int Sum;       // 3�ſγ̵��ܷ�
    float Ave;     // 3�ſγ̵�ƽ����
} STUDENT;
typedef struct Lnode {
    STUDENT Data;
    struct Lnode* next;
} LinkNode;
void InputStu(LinkNode*& stu, int n) {  // ����ѧ����Ϣ
    LinkNode* p;
    for (int i = 0; i < n; ++i) {
        p = (LinkNode*)malloc(sizeof(LinkNode));
        scanf("%ld", &p->Data.ID);                                        // ����ѧ��
        scanf("%s", p->Data.Name);                                        // ��������
        scanf("%s", p->Data.Sex);                                         // �����Ա�
        scanf("%d", &p->Data.English);                                    // ����Ӣ��ɼ�
        scanf("%d", &p->Data.Computer);                                   // ���������ɼ�
        scanf("%d", &p->Data.Math);                                       // ��������ɼ�
        p->Data.Sum = p->Data.English + p->Data.Computer + p->Data.Math;  // �����ܷ�
        p->Data.Ave = p->Data.Sum / 3;                                    // ����ƽ����
        p->next = stu;
        stu = p;
    }
}
void OutputStu(LinkNode*& stu) {  // ���ѧ����Ϣ
    printf("ѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");
    LinkNode* p;
    p = stu;
    while (p != NULL) {
        printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // ���ѧ����Ϣ
        p = p->next;
    }
}
void SearchStu(LinkNode*& stu) {  // ����ѧ����Ϣ
    int i;
    long ID;  // �����ҵ�ѧ��
    LinkNode* p;
    p = stu;
    printf("����������ҵ�ѧ�ţ�");
    scanf("%ld", &ID);
    while (p != NULL) {
        if (p->Data.ID == ID) {
            printf("\n��ѯ�ɹ�\n\n");
            printf("ѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");
            printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // ���ѧ����Ϣ
            return;
        }
        p = p->next;
    }
    printf("\nѧ�Ų�����\n");
}
void UpdateStu(LinkNode*& stu) {  // �޸�ѧ����Ϣ
    int op;                       // �û�ѡ��
    long ID;                      // Ҫ�޸ļ�¼��ѧ��
    LinkNode* p;
    p = stu;
    printf("������Ҫ�޸ļ�¼��ѧ�ţ�");
    scanf("%ld", &ID);
    while (p != NULL) {
        if (p->Data.ID == ID) {
            printf("\nѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");
            printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // ���ѧ����Ϣ
            printf(
                "        1.����\n"
                "        2.�Ա�\n"
                "        3.Ӣ��\n"
                "        4.�����\n"
                "        5.����\n"
                "        ��ѡ��1-5����");
            scanf("%d", &op);  // �����û�ѡ��
            printf("�������޸ĺ����Ϣ��");
            if (op == 1)
                scanf("%s", p->Data.Name);  // ����Ҫ�޸ļ�¼������
            else if (op == 2)
                scanf("%s", p->Data.Sex);  // ����Ҫ�޸ļ�¼���ձ�
            else {
                if (op == 3)
                    scanf("%d", &p->Data.English);  // ����Ҫ�޸ļ�¼��Ӣ��ɼ�
                else if (op == 4)
                    scanf("%d", &p->Data.Computer);  // ����Ҫ�޸ļ�¼�ļ�����ɼ�
                else
                    scanf("%d", &p->Data.Math);                                   // ����Ҫ�޸ļ�¼�ĸ����ɼ�
                p->Data.Sum = p->Data.English + p->Data.Computer + p->Data.Math;  // �����ܷ�
                p->Data.Ave = p->Data.Sum / 3;                                    // ����ƽ����
            }
            printf("\nѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");
            printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // ���ѧ����Ϣ
            return;
        }
        p = p->next;
    }
}
void AppendStu(LinkNode*& stu) {  // ���ѧ����Ϣ
    LinkNode* p;
    printf("������ѧ����Ϣ��");
    p = (LinkNode*)malloc(sizeof(LinkNode));
    scanf("%ld", &p->Data.ID);                                        // ����ѧ��
    scanf("%s", p->Data.Name);                                        // ��������
    scanf("%s", p->Data.Sex);                                         // �����Ա�
    scanf("%d", &p->Data.English);                                    // ����Ӣ��ɼ�
    scanf("%d", &p->Data.Computer);                                   // ���������ɼ�
    scanf("%d", &p->Data.Math);                                       // ��������ɼ�
    p->Data.Sum = p->Data.English + p->Data.Computer + p->Data.Math;  // �����ܷ�
    p->Data.Ave = p->Data.Sum / 3;                                    // ����ƽ����
    p->next = stu;
    stu = p;
    printf("���³ɹ�");
}
int main() {
    int n;               // ѧ����¼����
    LinkNode* s = NULL;  // ѧ����¼
    int op;              // �û�ѡ��
    printf("������ѧ����¼����n=");
    scanf("%d", &n);  // ����ѧ����¼����n
    printf("������ѧ����Ϣ��\n");
    InputStu(s, n);  // ���ú���InputStu����ѧ����Ϣ
    do {
        printf(
            "\n                                  ѧ����Ϣ����ϵͳ\n"
            "        1.��ʾѧ����Ϣ\n"
            "        2.����ѧ����Ϣ\n"
            "        3.�޸�ѧ����Ϣ\n"
            "        4.���ѧ����Ϣ\n"
            "        ��ѡ��1-4����");
        scanf("%d", &op);  // �����û�ѡ��
        printf("\n");
        switch (op) {
            case 1:
                OutputStu(s);  // ���ú���OutputStu��ʾѧ����Ϣ
                break;
            case 2:
                SearchStu(s);  // ���ú���SearchStu����ѧ����Ϣ
                break;
            case 3:
                UpdateStu(s);  // ���ú���UpdateStu�޸�ѧ����Ϣ
                break;
            case 4:
                AppendStu(s);  // ���ú���AppendStu���ѧ����Ϣ
                ++n;           // ��¼������1
                break;
            default:
                break;
        }
    } while (op);
    return 0;
}