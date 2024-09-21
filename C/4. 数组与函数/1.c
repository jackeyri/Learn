//计算数组的总和/平均值/最大值/最小值
#include <stdio.h>
int main(void)
{
    int n, a[100], sum, max, min, i;
    scanf("%d", &n);
    for (i = 0, sum = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (max = min = a[0], i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    printf("总和 = %d\n", sum);
    printf("平均值 = %d\n", sum / n);
    printf("最大值 = %d\n", max);
    printf("最小值 = %d\n", min);
    return 0;
}