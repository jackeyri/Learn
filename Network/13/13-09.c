// 13-09.c《TCP/IP网络编程》page 279  epoll_serv.c 交互 echo_client.c
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 100
#define EPOLL_SIZE 50
void setnonblockingmode(int fd);
void error_handling(char* message);
int main(int argc, char* argv[]) {
    int server_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_adr;
    socklen_t adr_sz;
    int str_len, i;
    char buf[BUF_SIZE];

    struct epoll_event* ep_events;
    struct epoll_event event;
    int epfd, event_cnt;
    if (argc != 2) {
        printf("Usage :%s <PORT>\n", argv[0]);
        exit(1);
    }
    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1)
        error_handling("socket() create failed.");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // IP地址
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // PORT
    serv_addr.sin_port = htons(atoi(argv[1]));
    if (bind(server_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) ==
        -1)
        error_handling("bind() failed.");
    if (listen(server_sock, 5) == -1)
        error_handling("listen() failed.");
    epfd = epoll_create(EPOLL_SIZE);
    // 分配EPOLL_SIZE个epoll_event用于记录事件
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);
    printf("ep_events=malloc(). \n");
    // 设置socket为非阻塞模式
    setnonblockingmode(server_sock);
    event.events = EPOLLIN;
    event.data.fd = server_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, server_sock, &event);

    while (1) {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, 500);
        if (event_cnt == -1) {
            puts("epoll_wait() error.");
            break;
        }
        // printf("return epoll_wait(). event_cnt=%d\n",event_cnt);
        // 遍历所有ep_events对象
        for (i = 0; i < event_cnt; i++) {
            // 是监听socket对象事件则执行accept方法
            if (ep_events[i].data.fd == server_sock) {
                adr_sz = sizeof(clnt_adr);
                // 每次accept会创建一个新socket用于数据通信
                clnt_sock =
                    accept(server_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
                printf("connected client ID=: %d \n", clnt_sock);
                // 设置socket为非阻塞模式
                setnonblockingmode(clnt_sock);
                event.events = EPOLLIN | EPOLLET;
                event.data.fd = clnt_sock;
                // 注册监视对象文件描述符
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
            } else {  // 是普通socket对象则执行读操作
                str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
                if (str_len ==
                    0) {  // 收到字节长度为0，表示对方shutdown，则执行close操作
                    epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                    close(ep_events[i].data.fd);
                    printf("closed client:%d \n", ep_events[i].data.fd);
                    break;
                } else if (str_len < 0) {  // 收到字节长度小于0
                    if (errno == EAGAIN)
                        break;
                } else {  // 收到字节度大于0，执行回复操作
                    printf("Message from %d. :%s", ep_events[i].data.fd, buf);
                    write(ep_events[i].data.fd, buf, str_len);
                }
            }
        }
    }
    close(server_sock);
    close(epfd);
    return 0;
}

void setnonblockingmode(int fd) {
    int flag = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}
// 错误处理是将信息输出到标准输出，然后退出进程。
void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
