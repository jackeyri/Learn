// 08-09.c 使用线程的聊天客户端《TCP/IP网络编程》page310  chat_clnt.c
// 聊天程序客户端
#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 100
#define NAME_SIZE 20
void* recv_msg(void* arg);
void* send_msg(void* arg);
void error_handling(char* msg);
// 全局变量
char name[NAME_SIZE] = "[default]";
char msg[BUF_SIZE];
int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in serv_adr;
    pthread_t snd_thread, rcv_thread;
    void* thread_return;
    if (argc != 4) {
        printf("Usage: %s <IP> <port> <name>\n", argv[0]);
        exit(1);
    }
    sprintf(name, "[%s]", argv[3]);
    // 用于连接和通讯的socket资源
    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));
    // 连接目标主机
    if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("connect() error");

    // 创建一个线程管理发送数据
    pthread_create(&snd_thread, NULL, send_msg, (void*)&sock);
    // 创建一个线程管理接收数据
    pthread_create(&rcv_thread, NULL, recv_msg, (void*)&sock);
    // 等待发送线程结束
    pthread_join(snd_thread, &thread_return);
    // 等待接收线程结束
    pthread_join(rcv_thread, &thread_return);
    // 关闭socket文件资源
    close(sock);
    return 0;
}

// 发送线程代码
void* send_msg(void* arg) {
    int sock = *((int*)arg);
    char name_msg[NAME_SIZE + BUF_SIZE];

    while (1) {
        fgets(msg, BUF_SIZE, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n")) {
            close(sock);
            exit(0);
        }
        sprintf(name_msg, "%s %s", name, msg);
        write(sock, name_msg, strlen(name_msg));
    }
    return NULL;
}
// 接收信息线程代码
void* recv_msg(void* arg) {
    int sock = *((int*)arg);
    char name_msg[NAME_SIZE + BUF_SIZE];
    int str_len;
    while (1) {
        str_len = read(sock, name_msg, NAME_SIZE + BUF_SIZE - 1);
        if (str_len == -1)
            return (void*)-1;
        name_msg[str_len] = 0;
        fputs(name_msg, stdout);
    }
    return NULL;
}
// 输出出错信息后结束本进程
void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
