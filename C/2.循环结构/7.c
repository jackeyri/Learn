//输出三角形、倒三角形等
#include <stdio.h>
int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
            printf("*");

        for (j = 1; j <= 2 * (n - i) + n; j++)
            printf(" ");
        for (j = 1; j <= i; j++)
            printf("*");

        for (j = 1; j <= n - i + n; j++)
            printf(" ");
        for (j = 1; j <= 2 * (i - 1) + 1; j++)
            printf("*");

        for (j = 1; j <= n + n; j++)
            printf(" ");
        for (j = 1; j <= 2 * (n - i) + 1; j++)
            printf("*");

        for (j = 1; j <= n + n; j++)
            printf(" ");
        printf("*");
        if (i > 1 && i < n)
        {
            for (j = 1; j <= 2 * (i - 1) - 1; j++)
                printf(" ");
            printf("*");
        }
        if (i == n)
        {
            for (j = 1; j <= 2 * (n - 1); j++)
                printf("*");
        }

        for (j = 1; j <= n + n; j++)
            printf(" ");
        if (i == 1)
        {
            for (j = 1; j <= 2 * (n - 1); j++)
                printf("*");
        }
        printf("*");
        if (i > 1 && i < n)
        {
            for (j = 1; j <= 2 * (n - i) - 1; j++)
                printf(" ");
            printf("*");
        }

        printf("\n");
    }
    return 0;
}