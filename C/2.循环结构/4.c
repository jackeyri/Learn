//输入一批数（以-1 结束输入），求它们之和
#include <stdio.h>
int main(void)
{
    int n, sum = 0;
    while (~scanf("%d", &n) && n != -1)
        sum += n;
    printf("%d", sum);
}