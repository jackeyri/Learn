//求二维数组每行/每列的总和/平均值
#include <stdio.h>
int main(void)
{
    int n, m, arr[100][100], sum, i, j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0, sum = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
        printf("第%d行的总和 = %d, 平均值 = %d\n", i + 1, sum, sum / m);
    }
    for (j = 0; j < m; j++)
    {
        for (i = 0, sum = 0; i < n; i++)
            sum += arr[i][j];
        printf("第%d列的总和 = %d, 平均值 = %d\n", j + 1, sum, sum / n);
    }
    return 0;
}