//编写求阶乘的函数，并在main中调用该函数计算1！+2！+……+n！
#include <stdio.h>
long Fact(int n);
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d！ = %ld", n, Fact(n));
    return 0;
}
//函数功能：用迭代法计算n！
long Fact(int n)
{
    int i;
    long result = 1;
    for (i = 2; i <= n; i++)
        result *= i;
    return result;
}