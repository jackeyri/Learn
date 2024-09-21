//编写函数实现输入/输出数组元素，如void input(int arr[], int n);
#include <stdio.h>
void input(int arr[], int n);
void output(int arr[], int n);
int main(void)
{
    int n, arr[100];
    scanf("%d", &n);
    input(arr, n);
    output(arr, n);
    return 0;
}
void input(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
void output(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
}