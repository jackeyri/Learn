//求二维数组每行/每列的最大值/最小值
#include <stdio.h>
int main(void)
{
    int n, m, arr[100][100], max, min, i, j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i][0]);
        for (j = 1, max = min = arr[i][0]; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > max)
                max = arr[i][j];
            if (arr[i][j] < min)
                min = arr[i][j];
        }
        printf("第%d行的最大值 = %d, 最小值 = %d\n", i + 1, max, min);
    }
    for (j = 0; j < m; j++)
    {
        for (i = 1, max = min = arr[0][j]; i < n; i++)
        {
            if (arr[i][j] > max)
                max = arr[i][j];
            if (arr[i][j] < min)
                min = arr[i][j];
        }
        printf("第%d列的最大值 = %d, 最小值 = %d\n", j + 1, max, min);
    }
    return 0;
}