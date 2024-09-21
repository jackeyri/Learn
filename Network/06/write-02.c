/*文件write-02.c, 向文件写入字符串*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_LEN 5
int main(void) {
    int fd, iCharLen;
    char buf_num[BUF_LEN];
    int i = 0;
    fd = open("300.txt", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        close(fd);
        exit(1);
    }

    /*向文件写入 0-299 字符格式的整数*/
    for (i = 0; i < 300; i++) {
        iCharLen = snprintf(buf_num, BUF_LEN, "%d;", i);
        if (write(fd, buf_num, iCharLen) != iCharLen) {
            perror("write");
            close(fd);
            exit(1);
        }
    }
    close(fd);
    exit(0);
}