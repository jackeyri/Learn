//将一个任意位数的整数分解出各位的数值
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    while (n)
    {
        printf("%d ", n % 10);
        n /= 10;
    }
    return 0;
}