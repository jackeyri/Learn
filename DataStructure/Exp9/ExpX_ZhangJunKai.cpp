// ���õݹ鷽�����x~n��Ҫ�����ʹ��log2n�εݹ����
#include <stdio.h>

double expx1(double x, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else if (n % 2 == 0)  // ��nΪ����1��ż��ʱ
        return expx1(x, n / 2) * expx1(x, n / 2);
    else  // ��nΪ����1������ʱ
        return x * expx1(x, (n - 1) / 2) * expx1(x, (n - 1) / 2);
}

// ��ͳ����
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
    printf("x��");
    scanf("%lf", &x);
    printf("n��");
    scanf("%d", &n);
    printf("%g��%d�η���%g\n", x, n, expx(x, n));
    printf("%g��%d�η���%g\n", x, n, expx1(x, n));
}