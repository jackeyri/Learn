/*文件lseek-1.c, 在文件最后追加内容*/
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
    char* buf = "a quick brown fox jumps over the lazy dog";
    int i = 0;
    fd = open("300.txt", O_WRONLY);
    if (fd < 0) {
        perror("open");
        close(fd);
        exit(1);
    } else {
        lseek(fd, 0, SEEK_END);
        write(fd, buf, strlen(buf));
        close(fd);
    }
    exit(0);
}