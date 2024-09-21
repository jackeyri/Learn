#include <bits/stdc++.h>
using namespace std;
typedef struct student {
    long ID;       // 学号
    char Name[9];  // 姓名
    char Sex[3];   // 性别
    int English;   // 英语成绩
    int Computer;  // 计算机成绩
    int Math;      // 高数成绩
    int Sum;       // 3门课程的总分
    float Ave;     // 3门课程的平均分
} STUDENT;
typedef struct Lnode {
    STUDENT Data;
    struct Lnode* next;
} LinkNode;
void InputStu(LinkNode*& stu, int n) {  // 输入学生信息
    LinkNode* p;
    for (int i = 0; i < n; ++i) {
        p = (LinkNode*)malloc(sizeof(LinkNode));
        scanf("%ld", &p->Data.ID);                                        // 输入学号
        scanf("%s", p->Data.Name);                                        // 输入姓名
        scanf("%s", p->Data.Sex);                                         // 输入性别
        scanf("%d", &p->Data.English);                                    // 输入英语成绩
        scanf("%d", &p->Data.Computer);                                   // 输入计算机成绩
        scanf("%d", &p->Data.Math);                                       // 输入高数成绩
        p->Data.Sum = p->Data.English + p->Data.Computer + p->Data.Math;  // 计算总分
        p->Data.Ave = p->Data.Sum / 3;                                    // 计算平均分
        p->next = stu;
        stu = p;
    }
}
void OutputStu(LinkNode*& stu) {  // 输出学生信息
    printf("学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
    LinkNode* p;
    p = stu;
    while (p != NULL) {
        printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // 输出学生信息
        p = p->next;
    }
}
void SearchStu(LinkNode*& stu) {  // 查找学生信息
    int i;
    long ID;  // 待查找的学号
    LinkNode* p;
    p = stu;
    printf("请输入待查找的学号：");
    scanf("%ld", &ID);
    while (p != NULL) {
        if (p->Data.ID == ID) {
            printf("\n查询成功\n\n");
            printf("学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
            printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // 输出学生信息
            return;
        }
        p = p->next;
    }
    printf("\n学号不存在\n");
}
void UpdateStu(LinkNode*& stu) {  // 修改学生信息
    int op;                       // 用户选项
    long ID;                      // 要修改记录的学号
    LinkNode* p;
    p = stu;
    printf("请输入要修改记录的学号：");
    scanf("%ld", &ID);
    while (p != NULL) {
        if (p->Data.ID == ID) {
            printf("\n学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
            printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // 输出学生信息
            printf(
                "        1.姓名\n"
                "        2.性别\n"
                "        3.英语\n"
                "        4.计算机\n"
                "        5.高数\n"
                "        请选择（1-5）：");
            scanf("%d", &op);  // 输入用户选项
            printf("请输入修改后的信息：");
            if (op == 1)
                scanf("%s", p->Data.Name);  // 输入要修改记录的姓名
            else if (op == 2)
                scanf("%s", p->Data.Sex);  // 输入要修改记录的姓别
            else {
                if (op == 3)
                    scanf("%d", &p->Data.English);  // 输入要修改记录的英语成绩
                else if (op == 4)
                    scanf("%d", &p->Data.Computer);  // 输入要修改记录的计算机成绩
                else
                    scanf("%d", &p->Data.Math);                                   // 输入要修改记录的高数成绩
                p->Data.Sum = p->Data.English + p->Data.Computer + p->Data.Math;  // 计算总分
                p->Data.Ave = p->Data.Sum / 3;                                    // 计算平均分
            }
            printf("\n学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");
            printf("%ld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2f\n", p->Data.ID, p->Data.Name, p->Data.Sex, p->Data.English, p->Data.Computer, p->Data.Math, p->Data.Sum, p->Data.Ave);  // 输出学生信息
            return;
        }
        p = p->next;
    }
}
void AppendStu(LinkNode*& stu) {  // 添加学生信息
    LinkNode* p;
    printf("请输入学生信息：");
    p = (LinkNode*)malloc(sizeof(LinkNode));
    scanf("%ld", &p->Data.ID);                                        // 输入学号
    scanf("%s", p->Data.Name);                                        // 输入姓名
    scanf("%s", p->Data.Sex);                                         // 输入性别
    scanf("%d", &p->Data.English);                                    // 输入英语成绩
    scanf("%d", &p->Data.Computer);                                   // 输入计算机成绩
    scanf("%d", &p->Data.Math);                                       // 输入高数成绩
    p->Data.Sum = p->Data.English + p->Data.Computer + p->Data.Math;  // 计算总分
    p->Data.Ave = p->Data.Sum / 3;                                    // 计算平均分
    p->next = stu;
    stu = p;
    printf("更新成功");
}
int main() {
    int n;               // 学生记录个数
    LinkNode* s = NULL;  // 学生记录
    int op;              // 用户选项
    printf("请输入学生记录个数n=");
    scanf("%d", &n);  // 输入学生记录个数n
    printf("请输入学生信息：\n");
    InputStu(s, n);  // 调用函数InputStu输入学生信息
    do {
        printf(
            "\n                                  学生信息管理系统\n"
            "        1.显示学生信息\n"
            "        2.查找学生信息\n"
            "        3.修改学生信息\n"
            "        4.添加学生信息\n"
            "        请选择（1-4）：");
        scanf("%d", &op);  // 输入用户选项
        printf("\n");
        switch (op) {
            case 1:
                OutputStu(s);  // 调用函数OutputStu显示学生信息
                break;
            case 2:
                SearchStu(s);  // 调用函数SearchStu查找学生信息
                break;
            case 3:
                UpdateStu(s);  // 调用函数UpdateStu修改学生信息
                break;
            case 4:
                AppendStu(s);  // 调用函数AppendStu添加学生信息
                ++n;           // 记录数增加1
                break;
            default:
                break;
        }
    } while (op);
    return 0;
}