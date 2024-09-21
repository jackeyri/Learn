//将字符串转全大写、全小写、替换某个字符、删除空格等操作。
#include <stdio.h>
int main(void)
{
    int i;
    char str[100], key, ch;
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    puts(str);
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    puts(str);
    gets(str);
    scanf("%c %c", &key, &ch);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == key)
            str[i] = ch;
    }
    puts(str);
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
            printf("%c", str[i]);
    }
    return 0;
}