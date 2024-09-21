//求二维数组上三角/下三角的总和
#include <stdio.h>
int main(void)
{
    int n, m, arr[100][100], sum, i, j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    }
    for (i = 0, sum = 0; i < n; i++)
    {
        for (j = i; j < m; j++)
            sum += arr[i][j];
    }
    printf("上三角的总和 = %d\n", sum);
    for (i = 0, sum = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
            sum += arr[i][j];
    }
    printf("下三角的总和 = %d\n", sum);
    return 0;
}