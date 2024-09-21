//根据百分制成绩输出等级
#include <stdio.h>
int main(void)
{
    int t;
    scanf("%d", &t);
    if (t >= 90)
        printf("A");
    else if (t >= 80)
        printf("B");
    else if (t >= 70)
        printf("C");
    else if (t >= 60)
        printf("D");
    else
        printf("E");
    return 0;
}