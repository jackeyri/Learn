//三个数求最大值
#include <stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b)
        a > c ? printf("%d", a) : printf("%d", c);
    else
        b > c ? printf("%d", b) : printf("%d", c);
    return 0;
}