//判断某数是否素数
#include <stdio.h>
int main(void)
{
    int n, flag, i;
    scanf("%d", &n);
    for (i = 2, flag = 1; i * i <= n && flag; i++)
    {
        if (n % i == 0)
            flag = 0;
    }
    flag && n != 1 ? printf("yes") : printf("no");
    return 0;
}