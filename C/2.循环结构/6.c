//判断某数是否素数完数
#include <stdio.h>
int main(void)
{
    int n, total, i;
    scanf("%d", &n);
    for (i = 1, total = 0; i < n; i++)
    {
        if (n % i == 0)
            total += i;
    }
    total == i ? printf("yes") : printf("no");
    return 0;
}