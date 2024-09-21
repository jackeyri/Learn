// zm.c  sigaction 信号响应函数
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void read_childproc(int sig) {
    int status;
    // 等待子进程退出，并获得子进程的返回值
    pid_t id = waitpid(-1, &status, WNOHANG);
    if (WIFEXITED(status))  // 正常退出为真
    {
        printf("Removed proc id: %d\n", id);
        printf("Child send:%d \n", WEXITSTATUS(status));
    }
}
int main(int argc, char* argv[]) {
    pid_t pid;
    struct sigaction act;
    act.sa_handler = read_childproc;

    sigemptyset(&act.sa_mask);  // 初始化并清空
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act,
              0);  // 修改SIGCHLD信号的处理动作，子进程终止时调用。
    pid = fork();
    if (pid == 0) {
        puts("Hi,I am the First Child Process.");
        sleep(10);
        return 12;
    } else {
        printf("First Child Proc ID: %d\n", pid);
        pid = fork();
        if (pid == 0) {
            puts("Hi,I am the Second Child Process.");
            sleep(10);
            exit(24);
        } else {
            int i;
            printf("Second Child Proc ID: %d\n", pid);
            for (i = 0; i < 5; i++) {
                puts("wait...");
                sleep(5);
            }
        }
    }
    return 0;
}
