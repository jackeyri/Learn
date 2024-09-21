//判断水仙花数
#include <stdio.h>
int main(void)
{
    int x, a, b, c;
    scanf("%d", &x);
    a = x / 100;
    b = (x % 100) / 10;
    c = x % 10;
    a * a * a + b * b * b + c * c * c == x ? printf("yes") : printf("no");
    return 0;
}