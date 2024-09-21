//百钱买百鸡
#include <stdio.h>
int main(void)
{
    int x, y, z;
    for (x = 0; x <= 20; x++)
    {
        for (y = 0; y <= 33; y++)
        {
            z = 100 - x - y;
            if (5 * x + 3 * y + z / 3.0 == 100)
                printf("公鸡 = %d只, 母鸡 = %d只，小鸡 = %d只\n", x, y, z);
        }
    }
    return 0;
}