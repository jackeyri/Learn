// fork2.c fork创建进程生成的进程树，尝试根据进程ID绘制出进程创建树
#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
    pid_t pid;
    pid = fork();
    if (pid > 0) {
        printf("[%d]进程生成了[%d]子进程\n", getpid(), pid);
    }
    pid = fork();
    if (pid > 0) {
        printf("[%d]进程生成了[%d]子进程\n", getpid(), pid);
    }
    pid = fork();
    if (pid > 0) {
        printf("[%d]进程生成了[%d]子进程\n", getpid(), pid);
    }
    printf("当前进程ID号为:[%d]\n", getpid());
    printf("[%d]进程的父进程ID号为:[%d]\n", getpid(), getppid());
    sleep(5);
    return 0;
}