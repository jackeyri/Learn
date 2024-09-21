/*文件read-01.c, O_CREAT和O_EXCL的使用*/
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

    /*循环读取数据，直到文件末尾或者出错*/
    while (size) {
        for (i = 0; i < 11; i++) {  // 初始化缓冲区
            buf[i] = 0;
        }
        size = read(fd, buf, 10);  // 每次读取10个字节数据
        if (size == -1) {          // 读取数据出错
            close(fd);             // 关闭文件
            printf("Read file error occurs.\n");
            return -1;  // 返回
        } else {        // 读取数据成功
            if (size > 0) {
                printf("Read %zd bytes data: \"%s\".\n", size, buf);  // 输出读取的数据
            } else {
                printf("Reach the end of file.\n");
            }
        }
    }
    return 0;
}