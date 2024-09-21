#include <stdio.h>
#include <stdlib.h>

int main() {
    char *p1 = malloc(100);
    char p2[100]; 

    printf("sizeof p1 = %ld, sizeof p2 = %ld\n", sizeof(p1), sizeof(p2));
    free(p1);

    return 0;
}
