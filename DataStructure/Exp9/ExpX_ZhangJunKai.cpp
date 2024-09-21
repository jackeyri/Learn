// 利用递归方法求解x~n，要求最多使用log2n次递归调用
#include <stdio.h>

double expx1(double x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else if (n % 2 == 0)  // 当n为大于1的偶数时
        return expx1(x, n / 2) * expx1(x, n / 2);
    else  // 当n为大于1的奇数时
        return x * expx1(x, (n - 1) / 2) * expx1(x, (n - 1) / 2);
}

// 传统方法
double expx(double x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else
        return expx(x, n - 1) * x;
}

int main() {
    double x;
    int n;
    printf("x：");
    scanf("%lf", &x);
    printf("n：");
    scanf("%d", &n);
    printf("%g的%d次方：%g\n", x, n, expx(x, n));
    printf("%g的%d次方：%g\n", x, n, expx1(x, n));
}