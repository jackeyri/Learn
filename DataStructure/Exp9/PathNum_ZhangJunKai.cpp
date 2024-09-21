#include <stdio.h>
#define MaxSize 100
int pathnum(int m, int n) {  // 求解从(m, n)到(1, 1)路径条数
    if (m < 1 || n < 1)
        return 0;
    if (m == 1 && n == 1)
        return 1;
    return pathnum(m - 1, n) + pathnum(m, n - 1);
}
int main() {
    int m = 2, n = 5;
    printf("m = %d，n = %d的路径条数：%d\n", m, n, pathnum(m, n));
    return 1;
}