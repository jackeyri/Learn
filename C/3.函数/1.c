//会调用常用的数学函数，如sqrt(x)、fabs(x)、pow(x, y)
#include <stdio.h>
#include <math.h>
int main(void)
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%.2f\n", sqrt(x));
    printf("%.2f\n", fabs(x));
    printf("%.2f", pow(x, y));
    return 0;
}