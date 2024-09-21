// exec1.c execve创建进程1
#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
    printf("我是被用来测试的进程，系统分配的进程号是：%d\n", getpid());
    return 0;
}