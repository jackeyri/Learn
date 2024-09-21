//求1+2+…+n
#include <stdio.h>
int main(void)
{
    int n, sum, i;
    scanf("%d", &n);
    for (i = 1, sum = 0; i <= n; i++)
        sum += i;
    printf("%d", sum);
    return 0;
}