#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void GetMemory(char** p) {
    (*p) = (char*)malloc(100);
}
void CalcBlank(void) {
    char* str = NULL;
    char* ptr = NULL;
    unsigned int i = 0;
    GetMemory((char**)&str);
    strcpy(str,
           "Karl marx is born in Germany and German is his native language\n");
    ptr = str;
    while (('\0' != (*ptr))) {
        if (*ptr == ' ') {
            i++;
        }
        ptr++;
    }
    printf("the blank number is %d\n", i);
    free(str);
}
int main(void) {
    CalcBlank();
    return 0;
}
