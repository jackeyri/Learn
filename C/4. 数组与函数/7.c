//掌握至少一种排序算法（如冒泡排序）void sort(int arr[], int n);
#include <stdio.h>
int main(void)
{
    int n, a[100], temp, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &n);
    for (i = 9; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
    return 0;
}