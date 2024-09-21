// 10-05.c  网络传输中整数的序列化
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/file.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 100
#define FILE_NAME_LEN 100

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
    int sockfd, sendbytes;
    char buf[BUFSIZE];
    struct hostent* host;
    struct sockaddr_in serv_addr;
    int fd = 0;
    int iInput = 0;
    printf("This program will connect and send an integer.\n");
    // 命令 IP PORT
    if (argc != 3) {
        printf("Usage :%s <IP> <PORT>\n", argv[0]);
        exit(1);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // IP地址,较老的方法
    // serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    // 新的地址转换方法
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    // PORT
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (connect(sockfd, (struct sockaddr*)&serv_addr,
                sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    printf("Server connected.\n");
    printf("Input integer:");
    scanf("%d", &iInput);
    memset(buf, 0, BUFSIZE);
    IntToByte(iInput, buf);
    send(sockfd, buf, 4, 0);
    printf("Integer value of decimal %d  Hex value :%0X\n", iInput, iInput);
    close(sockfd);
    return 0;
}
