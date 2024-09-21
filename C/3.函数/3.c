//编写函数判断某数是否为素数/完数，并在main中调用该函数求[m, n]范围内的素数之和/完数之和。
#include <stdio.h>
int IsPrime(int n);
int IsPerfect(int n);
int main(void)
{
    int m, n, PrimeSum, PerfectSum;
    scanf("%d%d", &m, &n);
    for (PrimeSum = 0, PerfectSum = 0; m <= n; m++)
    {
        if (IsPrime(m))
            PrimeSum += m;
        if (IsPerfect(m))
            PerfectSum += m;
    }
    printf("素数之和 = %d\n", PrimeSum);
    printf("完数之和 = %d\n", PerfectSum);
    return 0;
}
//函数功能：判断x是否是素数，若函数返回0，则代表不是素数，若返回1，则代表是素数
int IsPrime(int x)
{
    int flag, i;
    for (i = 2, flag = 1; i * i <= x && flag; i++)
    {
        if (x % i == 0)
            flag = 0;
    }
    return flag && x != 1 ? 1 : 0;
}
//函数功能：判断完美数，若函数返回0，则代表不是完美数，若返回1，则代表是完美数
int IsPerfect(int x)
{
    int total, i;
    for (i = 1, total = 0; i < x; i++)
    {
        if (x % i == 0)
            total += i;
    }
    return total == i ? 1 : 0;
}