// fork1.c 创建进程2
#include <stdio.h>
#include <unistd.h>
int gval = 10;
int main(int argc, char* argv[]) {
    pid_t pid;
    int lval = 20;
    gval++, lval += 5;
    pid = fork();
    if (pid == 0) {  // 子进程执行
        gval += 2, lval += 2;
        printf("This is Child Proc: [%d, %d]\n", gval, lval);
        printf("Child进程ID号为: [%d]\n", getpid());
        printf("Child进程的父进程ID号为: [%d]\n", getppid());
    } else {  // 父进程执行
        sleep(1);
        gval -= 2, lval -= 2;
        printf("This is Parent Proc: [%d, %d]\n", gval, lval);
        printf("Parent进程ID号为: [%d]\n", getpid());
        printf("Parent进程的父进程ID号为: [%d]\n", getppid());
    }
    return 0;
}