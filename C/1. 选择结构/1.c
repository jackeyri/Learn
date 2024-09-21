//分段函数值求解
#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    n > 0 ? printf("%d", n) : printf("%d", -n);
    return 0;
}