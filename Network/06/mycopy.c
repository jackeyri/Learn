/*文件mycopy.c, 实现文件拷贝的基本功能./mycopy 1.txt 2.txt*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUF_LEN 5
int main(int argc, char* argv[]) {
    int fd1, fd2, iCharLen;
    char buf[BUF_LEN];
    int i = 0;
    if (argc != 3) {
        printf("Usage: %s <src_file> <dst_file>\n", argv[0]);
        exit(1);
    }
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        perror("open");
        close(fd1);
        exit(1);
    }
    fd2 = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if (fd2 < 0) {
        perror("open");
        close(fd2);
        exit(1);
    }
    while ((iCharLen = read(fd1, buf, BUF_LEN)) > 0) {
        if (write(fd2, buf, iCharLen) != iCharLen) {
            perror("write");
            close(fd1);
            close(fd2);
            exit(1);
        }
    }
    close(fd1);
    close(fd2);
    exit(0);
}