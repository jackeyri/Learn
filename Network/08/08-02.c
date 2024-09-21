// 08-02.c TCP服务端hello程序
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
void error_handling(char* message);
int main(int argc, char* argv[]) {
    int serv_listen_sock;  // 服务端负责监听的socket文件标识
    int serv_data_sock;    // 服务端负责数据通信的socket文件标识
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;
    char message[] = "Hello embedded.";
    if (argc != 2) {
        printf("Usage:%s <port>\n", argv[0]);
        exit(1);
    }
    // 创建一个TCP的socket资源
    serv_listen_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_listen_sock == -1)
        error_handling("serv_listen_sock  create() error");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));
    // 端口绑定
    if (bind(serv_listen_sock, (struct sockaddr*)&serv_addr,
             sizeof(serv_addr)) == -1)
        error_handling("bind() error");
    // 执行监听
    if (listen(serv_listen_sock, 5) == -1)
        error_handling("bind() error");
    clnt_addr_size = sizeof(clnt_addr);
    // 实现连接请求响应
    serv_data_sock =
        accept(serv_listen_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (serv_data_sock == -1)
        error_handling("bind() error");
    write(serv_data_sock, message, sizeof(message));

    shutdown(serv_data_sock, SHUT_RDWR);
    close(serv_data_sock);
    close(serv_listen_sock);
    return 0;
}
// 错误处理是将信息输出到标准输出，然后退出进程。
void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
