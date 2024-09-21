// 10-04.c文件传输接收端支持文件名接收
// 发送端  connect
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXDATASIZE 30
#define FILE_NAME_LEN 40
#define SERVPORT 50

void main(int argc, char* argv[]) {
    int sockfd, sendbytes;
    char buf[MAXDATASIZE];
    char file_name[FILE_NAME_LEN];
    struct hostent* host;
    struct sockaddr_in serv_adr;

    int fd = 0;
    int totalbytes = 0;
    int readbytes = 0;
    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    // 要连接的目标socket资源
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    // serv_adr.sin_addr.s_addr=htonl(argv[1]);
    inet_pton(AF_INET, argv[1], &serv_adr.sin_addr);
    // serv_adr.sin_addr.s_addr=htonl(argv[1]);
    serv_adr.sin_port = htons(atoi(argv[2]));
    // 连接目标主机
    connect(sockfd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));

    printf("please input the file you want to open:\n");
    // 清空文件名字符串缓冲区
    memset(file_name, 0, FILE_NAME_LEN);
    // 输入文件名字符
    scanf("%s", file_name);
    // 将文件名字符串发送给接收端
    send(sockfd, file_name, strlen(file_name), 0);
    printf("filename is %s\n", file_name);
    readbytes = recv(sockfd, buf, MAXDATASIZE, 0);

    // 打开文件
    fd = open(file_name, O_RDONLY, 0666);
    if (fd < 0) {
        perror("open file error.");
        exit(1);
    }

    printf("press s to send file\n");
    getchar();
    while ((readbytes = read(fd, buf, MAXDATASIZE))) {
        if ((sendbytes = send(sockfd, buf, readbytes, 0)) == -1) {
            perror("send");
            exit(1);
        }
        // 累加当有已发送的字节数
        totalbytes += sendbytes;
    }
    printf("sent %d bytes ..\n", totalbytes);
    // 在此补充代码---关闭套接字资源
    shutdown(sockfd, 2);
    close(sockfd);
}
