//输入年月日求本年度第多少天（用数组的方式）
#include <stdio.h>
int main(void)
{
    int year, month, day, days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, sum, i;
    scanf("%d%d%d", &year, &month, &day);
    for (sum = 0, i = 0; i < month - 1; i++)
        sum += days[i];
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0 && month > 2)
        sum++;
    sum += day;
    printf("%d", sum);
    return 0;
}