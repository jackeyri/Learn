#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
static int sum(int value);
struct inout {
    int value;
    int result;
};
int main(int argc, char* argv[]) {
    struct inout* io = (struct inout*)malloc(sizeof(struct inout));
    if (NULL == io) {
        printf("fail to malloc \n");
        return -1;
    }
    if (argc != 2) {
        printf("wrong argc \n");
        return -1;
    }
    io->value = atoi(argv[1]);
    io->result = sum(io->value);
    printf("the sum result: %d\n", io->result);
    return 0;
}
static int sum(int value) {
    int result = 0;
    int i = 0;
    for (i = 0; i <= value; i++) {
        result += i;
    }
    return result;
}
