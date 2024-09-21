//将数组最大值/最小值交换
#include <stdio.h>
int main(void)
{
    int n, a[100], max, min, maxPos, minPos, temp, i;
    scanf("%d", &n);
    scanf("%d", &a[0]);
    for (i = 1, max = min = a[0], maxPos = minPos = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max)
        {
            max = a[i];
            maxPos = i;
        }
        if (a[i] < min)
        {
            min = a[i];
            minPos = i;
        }
    }
    temp = a[maxPos];
    a[maxPos] = a[minPos];
    a[minPos] = temp;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}