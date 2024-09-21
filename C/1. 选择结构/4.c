//判断奇偶数
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    n % 2 == 0 ? printf("Even number") : printf("Odd number");
    return 0;
}