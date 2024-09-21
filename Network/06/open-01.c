/*文件open-01.c, 打开文件的例子*/
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(void) {
    int fd = -1;                    // 文件描述符
    char filename[] = "test.txt";   // 文件名
    fd = open(filename, O_RDONLY);  // 打开文件为可读写方式
    if (fd == -1) {                 // 打开文件失败
        printf("Open file %s failure, fd: %d.\n", filename, fd);
    } else {  // 打开文件成功
        printf("Open file %s success, fd: %d.\n", filename, fd);
    }
    return 0;
}