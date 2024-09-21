// 13-06.c 使用线程的并发服务端《TCP/IP网络编程》page307  chat_server.c
// 本程序执行socket监听，信息发送操作
#include <arpa/inet.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 100
#define MAX_CLNT 256
void* handle_clnt(void* arg);
void send_msg(char* msg, int len);
void error_handling(char* msg);
// 全局变量
int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;
int main(int argc, char* argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    int clnt_adr_sz;
    pthread_t t_id;
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    pthread_mutex_init(&mutx, NULL);
    // 用于监听的socket资源
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
    // 绑定监听端口
    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");
    // 执行监听
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");
    while (1) {
        clnt_adr_sz = sizeof(clnt_adr);
        // 每个客户连接请求，服务端都创建一个新socket资源用于通讯
        clnt_sock =
            accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

        pthread_mutex_lock(&mutx);
        clnt_socks[clnt_cnt++] = clnt_sock;
        pthread_mutex_unlock(&mutx);

        // 创建一个线程管理与客户端的socket通讯
        pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);
        pthread_detach(t_id);
        printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
    }
    // 关闭监听socket文件资源
    close(serv_sock);
    return 0;
}

// 线程代码
void* handle_clnt(void* arg) {
    int clnt_sock = *((int*)arg);
    int str_len = 0, i;
    char msg[BUF_SIZE];

    while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
        send_msg(msg, str_len);
    pthread_mutex_lock(&mutx);
    for (i = 0; i < clnt_cnt; i++)  // remove disconnected client
    {
        if (clnt_sock == clnt_socks[i]) {
            while (i++ < clnt_cnt - 1)  // 向前移动数据元素
                clnt_socks[i] = clnt_socks[i + 1];
            break;
        }
    }
    clnt_cnt--;
    pthread_mutex_unlock(&mutx);
    close(clnt_sock);
    return NULL;
}

void send_msg(char* msg, int len) {
    int i;
    pthread_mutex_lock(&mutx);
    for (i = 0; i < clnt_cnt; i++)
        write(clnt_socks[i], msg, len);
    pthread_mutex_unlock(&mutx);
}
// 输出出错信息后结束本进程
void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
