// 13-03.c 基于fork方法多进程的回声服务《TCP/IP网络编程》page174
#include <arpa/inet.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUF_SIZE 30
void error_handling(char* message);
// 处理子进程的结束
void read_childproc(int sig);

int main(int argc, char* argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    pid_t pid;
    struct sigaction act;
    socklen_t adr_sz;
    int str_len, state;
    char buf[BUF_SIZE];
    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    // 接收子进程的返回值
    state = sigaction(SIGCHLD, &act, 0);
    // 创建TCP服务端socket文件资源
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    // 绑定TCP监听端口
    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error.");
    // 开启TCP监听
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error.");
    while (1) {
        adr_sz = sizeof(clnt_adr);
        // 每一个客户端连接，服务端都创建一个新socket资源用于配对通信
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
        if (clnt_sock == -1)
            continue;
        else
            puts("New client connected....");
        pid = fork();
        if (pid == -1) {  // 线程创建失败
            close(clnt_sock);
            continue;
        }
        if (pid == 0)  // 子进程由此处运行，父进程不执行该段代码
        {              // 子进程创建成功
            close(serv_sock);
            // 循环接收客户端发来的数据，直到发来长度为0
            while ((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0)
                // 将客户端信息原样回复
                write(clnt_sock, buf, str_len);
            close(clnt_sock);
            puts("clinet disconnected...");
            return 0;
        } else
            close(clnt_sock);  // 创建子进程失败，清除socket资源
    }
    // 结束监听，终止TCP服务。
    close(serv_sock);
    return 0;
}
// 处理子进程的结束
void read_childproc(int sig) {
    int status;
    // 获得子进程的返回值
    pid_t id = waitpid(-1, &status, WNOHANG);
    if (WIFEXITED(status)) {
        printf("Removed proc id: %d\n", id);
        printf("Child send:%d \n", WEXITSTATUS(status));
    }
}
// 错误处理是将信息输出到标准输出，然后退出进程。
void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
