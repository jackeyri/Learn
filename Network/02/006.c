#include "stdio.h"

int* p = NULL;
int x;
int i = 0;

int* fFun(void) {
    printf("variant i's address is 0x%ls and value is %d\n", &i, i);
    return &i;
    // return &x;
}

void subFun(void) {
    (*p)--;
    printf("pointer p's address is 0x%ls and value is %d\n", p, *p);
}

void gFun(void) {
    int j;
    printf("variant j's address is 0x%ls and value is %d\n", &j, j);
    for (j = 0; j < 10; j++) {
        subFun();
        printf("%d\n", j);
    }
}

int main(void) {
    p = fFun();
    gFun();
}
