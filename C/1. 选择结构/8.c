//根据里程计算运费问题
#include <stdio.h>
int main(void)
{
    float p, w, s, d;
    scanf("%f%f%f", &p, &w, &s);
    if (s < 250)
        d = 0;
    else if (s < 500)
        d = 0.02;
    else if (s < 1000)
        d = 0.05;
    else if (s < 2000)
        d = 0.08;
    else if (s < 3000)
        d = 0.10;
    else
        d = 0.15;
    printf("%.2f", p * w * s * (1 - d));
    return 0;
}