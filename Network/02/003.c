#include <stdio.h>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(void) {
    int bb = 1;
    int cc = 99;

    swap(&bb, &cc);
    printf("bb = %d, cc = %d\n", bb, cc);

    return 0;
}