//统计字符串中大小写字母、数字等的个数。
#include <stdio.h>
int main(void)
{
    int upper, lower, num, i;
    char str[100];
    gets(str);
    for (i = upper = lower = num = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            upper++;
        if (str[i] >= 'a' && str[i] <= 'z')
            lower++;
        if (str[i] >= '0' && str[i] <= '9')
            num++;
    }
    printf("大写字母 = %d, 小写字母 = %d, 数字 = %d", upper, lower, num);
    return 0;
}