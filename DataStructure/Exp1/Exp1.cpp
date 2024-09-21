#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <iostream>

using namespace std;
#define MAXSIZE 100

typedef struct student {
    int num;
    char name[20];
    char gender[6];
    float english;
    float computer;
    float math;
    float sum;
    float average;
} STUDENT;

//输入
void InputStu(STUDENT stu[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &stu[i].num);
        scanf("%s", stu[i].name);
        scanf("%s", stu[i].gender);
        scanf("%f", &stu[i].english);
        scanf("%f", &stu[i].computer);
        scanf("%f", &stu[i].math);
        //或者
        //cin >> stu[i].num >> stu[i].name >> stu[i].gender >> stu[i].english >> stu[i].computer >> stu[i].math ;
        stu[i].sum = stu[i].english + stu[i].computer + stu[i].math;
        stu[i].average = stu[i].sum / 3;
    }
    return;
}

//打印输出
void OutputStu(STUDENT stu[], int n) {
    int i;
    cout << "学号" << "\t姓名" << "\t性别" << "\t英语" << "\t计算机" << "\t数学" << "\t总分" << "\t平均分\n";
    for (i = 0; i < n; i++)
        cout << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].gender << "\t" << stu[i].english << "\t"
             << stu[i].computer << "\t" << stu[i].math << "\t" << stu[i].sum << "\t" << stu[i].average << "\n";
    cout << endl;
    return;
}

//查找：在学生表中查找指定学生的信息，如果找到就显示该生的所有信息，否则显示“该学生的信息不存在，查找失败”。
void SearchStu(STUDENT stu[], int n) {
    int i, number;
    cout << "请输入查找学生的学号：";
    cin >> number;
    for (i = 0; i < n; i++) {
        if (stu[i].num == number) {
            cout << "学号" << "\t姓名" << "\t性别" << "\t英语" << "\t数学" << "\t总分" << "\t平均分\n";
            cout << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].gender << "\t" << stu[i].english << "\t"
                 << stu[i].computer << "\t" << stu[i].math << "\t" << stu[i].sum << "\t" << stu[i].average << "\n";
            return;
        }
    }
    cout << "该学生的信息不存在，查找失败" << endl;
    return;
}

//修改：在学生表中修改指定学生的信息，然后显示所有学生信息，如果表中不存在该生就显示“该生的信息不存在，修改失败”。
void UpdateStu(STUDENT stu[], int n) {
    int i, number;
    cout << "请输入要修改学生的学号：";
    cin >> number;
    for (i = 0; i < n; i++) {
        if (stu[i].num == number)
            break;
    }
    if (i == n)
        cout << "该生的信息不存在，修改失败。" << endl;
    else {
        cout << "\n学号：";
        cin >> stu[i].num;
        cout << "\n姓名：";
        cin >> stu[i].name;
        cout << "\n性别：";
        cin >> stu[i].gender;
        cout << "\n英语成绩：";
        cin >> stu[i].english;
        cout << "\n计算机成绩：";
        cin >> stu[i].computer;
        cout << "\n数学成绩：";
        cin >> stu[i].math;
        stu[i].sum = stu[i].english + stu[i].computer + stu[i].math;
        stu[i].average = stu[i].sum / 3;
    }
    OutputStu(stu, n);
}

//添加：在当前学生表的末尾添加一个记录（记录数增加1）.例如，添加记录为：4256033  吴强 男 82 85 90
void AppendStu(STUDENT stu[], int *pn) {
    int i;
    if (*pn == MAXSIZE)
        cout << "空间已满，添加失败！" << endl;
    else {
        cout << "\n学号：";
        cin >> stu[*pn].num;
        cout << "\n姓名：";
        cin >> stu[*pn].name;
        cout << "\n性别：";
        cin >> stu[*pn].gender;
        cout << "\n英语成绩：";
        cin >> stu[*pn].english;
        cout << "\n计算机成绩：";
        cin >> stu[*pn].computer;
        cout << "\n数学成绩：";
        cin >> stu[*pn].math;
        stu[*pn].sum = stu[*pn].english + stu[*pn].computer + stu[*pn].math;
        stu[*pn].average = stu[*pn].sum / 3;
        *pn = *pn + 1;
    }
}

int main() {
    STUDENT STU[MAXSIZE];
    int index, length;
    cout << "请输入学生记录的个数：";
    cin >> length;
    InputStu(STU, length);
    while (1) {
        printf("\n\t\t学生信息管理系统\n\n");
        printf("\t1.显示学生信息\n");
        printf("\t2.查找学生信息\n");
        printf("\t3.修改学生信息\n");
        printf("\t4.添加学生信息\n");
        printf("\t0.退出\n");
        printf("\t请选择（1-4）：");
        scanf("%d", &index);
        /*或者：
        cout << "\n\t\t\t\t学生信息管理系统\n";
        cout << "\t1.显示学生信息\n";
        cout << "\t2.查找学生信息\n";
        cout << "\t3.修改学生信息\n";
        cout << "\t4.添加学生信息\n";
        cout << "\t0.退出\n";
        cout << "\t请选择（1-4）：";
        cin >> index;
        */
        switch (index) {
            case 1:
                OutputStu(STU, length);;
                break;
            case 2:
                SearchStu(STU, length);
                break;
            case 3:
                UpdateStu(STU, length);
                break;
            case 4:
                AppendStu(STU, &length);
                break;
            case 0:
                return 1;
            default:
                printf("\n输入有误，请重新输入！\n");
        }
    }
    return 1;
}
