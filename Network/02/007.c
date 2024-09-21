#include <memory.h>
#include <stdio.h>
#define MAX_MSG_LEN 1024

void copystr(char* dest, const char* src) {
    // dest是目标字符串指针首地址，src是源字符串指针首地址
    // 将src指向的字符串内容复制到由dest指向的地址中
    if (dest != NULL && src != NULL) {
        char* strD = dest;
        while ((*strD++ = *src++) != '\0')
            ;
    }
}

int main(int argc, char** argv) {
    char* p =
        "This is an exam for Linux Software. Please Coding carefully and check "
        "slowly";
    char szMsg[MAX_MSG_LEN];
    memset(szMsg, 0, sizeof(szMsg));
    copystr(szMsg, p);
    printf("The string is %s\n", szMsg);
}
