//求某年某月的天数（用数组的方式）
#include <stdio.h>
int main(void)
{
    int year, month, days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, i;
    scanf("%d%d", &year, &month);
    (year % 100 != 0 && year % 4 == 0) || year % 400 == 0 && month == 2 ? printf("29") : printf("%d", days[month - 1]);
    return 0;
}