/*文件read-02.c, 显示文件内容*/
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
    int fd = -1, i;
    ssize_t size = -1;
    char buf[11];  // 存放数据的缓冲区
    char filename[] = "test.txt";

    fd = open(filename, O_RDONLY);  // 打开文件，如果文件不存在，则报错
    if (fd == -1) {                 // 文件已经存在
        printf("Open file %s failure, fd: %d.\n", filename, fd);
    } else {  // 文件不存在，创建并打开
        printf("Open file %s success, fd: %d.\n", filename, fd);
    }

    /*每次读取10个字节数据*/
    size = read(fd, buf, 10);
    while (size) {
        for (i = 0; i < size; ++i) {  // 将读取的数据打印出来
            printf("%c", buf[i]);
        }
        size = read(fd, buf, 10);
    }
    close(fd);
    printf("\nFile closed.\n");
    return 0;
}