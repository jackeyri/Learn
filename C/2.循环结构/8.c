//输出九九乘法表
#include <stdio.h>
int main(void)
{
    int i, j;
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
            printf("%d * %d = %d\t", i, j, i * j);
        printf("\n");
    }
    
    for (printf("\n"), i = 1; i < 10; i++)
    {
        for (j = 1; j <= i; j++)
            printf("%d * %d = %d\t", i, j, i * j);
        printf("\n");
    }

    for (printf("\n"), i = 1; i < 10; i++)
    {
        for (j = 1; j < i; j++)
            printf("    \t\t");
        for (j = i; j < 10; j++)
            printf("%d * %d = %d\t", i, j, i * j);
        printf("\n");
    }
    return 0;
}