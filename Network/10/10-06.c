// 10-06.c  网络传输中整数的反序列化
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BACKLOG 10
#define MAX_CONNECTED_NO 10
#define BUFSIZE 100

void IntToByte(int iData, char* cData) {
    union IntChar {
        int a;      // 4 bytes
        char b[4];  // 4 byte
    } InCh;
    InCh.a = iData;
    cData[0] = InCh.b[0];
    cData[1] = InCh.b[1];
    cData[2] = InCh.b[2];
    cData[3] = InCh.b[3];
}
int ByteToInt(char* cData) {
    union IntChar {
        int a;      // 4 bytes
        char b[4];  // 4 byte
    } InCh;
    InCh.b[0] = cData[0];
    InCh.b[1] = cData[1];
    InCh.b[2] = cData[2];
    InCh.b[3] = cData[3];
    return InCh.a;
}

int main(int argc, char* argv[]) {
    struct sockaddr_in server_sockaddr, client_sockaddr;
    int sin_size, recvbytes;
    int listen_sockfd, client_fd;
    time_t currentTime;
    int nwrite = 0;
    char buf[BUFSIZE];
    printf("This program will listen and recv an integer.\n");
    if (argc != 2) {
        printf("Usage:%s <port>\n", argv[0]);
        exit(1);
    }
    if ((listen_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    printf("socket success!,listen_sockfd=%d\n", listen_sockfd);
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(atoi(argv[1]));
    server_sockaddr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(server_sockaddr.sin_zero), 8);
    if (bind(listen_sockfd, (struct sockaddr*)&server_sockaddr,
             sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }
    printf("bind success!\n");
    if (listen(listen_sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    printf("listening....\n");
    sin_size = sizeof(struct sockaddr);
    if ((client_fd = accept(listen_sockfd, (struct sockaddr*)&client_sockaddr,
                            &sin_size)) == -1) {
        perror("accept");
        exit(1);
    }
    recvbytes = recv(client_fd, buf, BUFSIZE, 0);
    printf("Received int =%d\n", ByteToInt(buf));
    shutdown(client_fd, SHUT_RDWR);
    close(listen_sockfd);
}
