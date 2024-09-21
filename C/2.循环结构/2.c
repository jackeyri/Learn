//求1/2+2/3+…19/20之和（及其变形）
#include <stdio.h>
int main(void)
{
    int i;
    float sign, sum;
    for (i = 1, sum = 0; i < 20; i++)
        sum += (float)i / (i + 1);
    printf("1/2 + 2/3 + … + 19/20 = %.2f\n", sum);
    for (i = sign = 1, sum = 0; i < 20; i++, sign *= -1)
        sum += sign * i / (i + 1);
    printf("1/2 - 2/3 + … + 19/20 = %.2f\n", sum);
    return 0;
}