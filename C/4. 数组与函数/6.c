//编写函数实现将数组元素逆向存放void reverse(int arr[], int n);
#include <stdio.h>
void reverse(int arr[], int n);
int main(void)
{
    int n, arr[100], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    reverse(arr, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
void reverse(int arr[], int n)
{
    int temp, i, j;
    for (i = 0; i <= (n - 1) / 2; i++)
    {
        j = n - i - 1;
        temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
    }
}