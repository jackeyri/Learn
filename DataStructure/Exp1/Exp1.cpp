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

//����
void InputStu(STUDENT stu[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &stu[i].num);
        scanf("%s", stu[i].name);
        scanf("%s", stu[i].gender);
        scanf("%f", &stu[i].english);
        scanf("%f", &stu[i].computer);
        scanf("%f", &stu[i].math);
        //����
        //cin >> stu[i].num >> stu[i].name >> stu[i].gender >> stu[i].english >> stu[i].computer >> stu[i].math ;
        stu[i].sum = stu[i].english + stu[i].computer + stu[i].math;
        stu[i].average = stu[i].sum / 3;
    }
    return;
}

//��ӡ���
void OutputStu(STUDENT stu[], int n) {
    int i;
    cout << "ѧ��" << "\t����" << "\t�Ա�" << "\tӢ��" << "\t�����" << "\t��ѧ" << "\t�ܷ�" << "\tƽ����\n";
    for (i = 0; i < n; i++)
        cout << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].gender << "\t" << stu[i].english << "\t"
             << stu[i].computer << "\t" << stu[i].math << "\t" << stu[i].sum << "\t" << stu[i].average << "\n";
    cout << endl;
    return;
}

//���ң���ѧ�����в���ָ��ѧ������Ϣ������ҵ�����ʾ������������Ϣ��������ʾ����ѧ������Ϣ�����ڣ�����ʧ�ܡ���
void SearchStu(STUDENT stu[], int n) {
    int i, number;
    cout << "���������ѧ����ѧ�ţ�";
    cin >> number;
    for (i = 0; i < n; i++) {
        if (stu[i].num == number) {
            cout << "ѧ��" << "\t����" << "\t�Ա�" << "\tӢ��" << "\t��ѧ" << "\t�ܷ�" << "\tƽ����\n";
            cout << stu[i].num << "\t" << stu[i].name << "\t" << stu[i].gender << "\t" << stu[i].english << "\t"
                 << stu[i].computer << "\t" << stu[i].math << "\t" << stu[i].sum << "\t" << stu[i].average << "\n";
            return;
        }
    }
    cout << "��ѧ������Ϣ�����ڣ�����ʧ��" << endl;
    return;
}

//�޸ģ���ѧ�������޸�ָ��ѧ������Ϣ��Ȼ����ʾ����ѧ����Ϣ��������в����ڸ�������ʾ����������Ϣ�����ڣ��޸�ʧ�ܡ���
void UpdateStu(STUDENT stu[], int n) {
    int i, number;
    cout << "������Ҫ�޸�ѧ����ѧ�ţ�";
    cin >> number;
    for (i = 0; i < n; i++) {
        if (stu[i].num == number)
            break;
    }
    if (i == n)
        cout << "��������Ϣ�����ڣ��޸�ʧ�ܡ�" << endl;
    else {
        cout << "\nѧ�ţ�";
        cin >> stu[i].num;
        cout << "\n������";
        cin >> stu[i].name;
        cout << "\n�Ա�";
        cin >> stu[i].gender;
        cout << "\nӢ��ɼ���";
        cin >> stu[i].english;
        cout << "\n������ɼ���";
        cin >> stu[i].computer;
        cout << "\n��ѧ�ɼ���";
        cin >> stu[i].math;
        stu[i].sum = stu[i].english + stu[i].computer + stu[i].math;
        stu[i].average = stu[i].sum / 3;
    }
    OutputStu(stu, n);
}

//��ӣ��ڵ�ǰѧ�����ĩβ���һ����¼����¼������1��.���磬��Ӽ�¼Ϊ��4256033  ��ǿ �� 82 85 90
void AppendStu(STUDENT stu[], int *pn) {
    int i;
    if (*pn == MAXSIZE)
        cout << "�ռ����������ʧ�ܣ�" << endl;
    else {
        cout << "\nѧ�ţ�";
        cin >> stu[*pn].num;
        cout << "\n������";
        cin >> stu[*pn].name;
        cout << "\n�Ա�";
        cin >> stu[*pn].gender;
        cout << "\nӢ��ɼ���";
        cin >> stu[*pn].english;
        cout << "\n������ɼ���";
        cin >> stu[*pn].computer;
        cout << "\n��ѧ�ɼ���";
        cin >> stu[*pn].math;
        stu[*pn].sum = stu[*pn].english + stu[*pn].computer + stu[*pn].math;
        stu[*pn].average = stu[*pn].sum / 3;
        *pn = *pn + 1;
    }
}

int main() {
    STUDENT STU[MAXSIZE];
    int index, length;
    cout << "������ѧ����¼�ĸ�����";
    cin >> length;
    InputStu(STU, length);
    while (1) {
        printf("\n\t\tѧ����Ϣ����ϵͳ\n\n");
        printf("\t1.��ʾѧ����Ϣ\n");
        printf("\t2.����ѧ����Ϣ\n");
        printf("\t3.�޸�ѧ����Ϣ\n");
        printf("\t4.���ѧ����Ϣ\n");
        printf("\t0.�˳�\n");
        printf("\t��ѡ��1-4����");
        scanf("%d", &index);
        /*���ߣ�
        cout << "\n\t\t\t\tѧ����Ϣ����ϵͳ\n";
        cout << "\t1.��ʾѧ����Ϣ\n";
        cout << "\t2.����ѧ����Ϣ\n";
        cout << "\t3.�޸�ѧ����Ϣ\n";
        cout << "\t4.���ѧ����Ϣ\n";
        cout << "\t0.�˳�\n";
        cout << "\t��ѡ��1-4����";
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
                printf("\n�����������������룡\n");
        }
    }
    return 1;
}
