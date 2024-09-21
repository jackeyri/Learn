// 《TCP/IP网络编程》page121  fsend.c   030.c 文件传输发送端
// 本程序执行socket监听，文件发送操作
// 10-01.c 文件传输发送端
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

#define SERVPORT 1300
#define MAXDATASIZE 1000
#define FILE_NAME_LEN 30
int main(int argc, char* argv[]) {
    int sockfd, sendbytes;
    char buf[MAXDATASIZE];
    char file_name[FILE_NAME_LEN];
    struct hostent* host;
    struct sockaddr_in serv_addr;
    int fd = 0;
    int totalbytes = 0;
    int readbytes = 0;
    printf("This program is tcp client, prepare to connect and send file.\n");
    if (argc < 2) {
        fprintf(stderr, "Please enter the server's hostname!\n");
        exit(1);
    }
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVPORT);
    serv_addr.sin_addr = *((struct in_addr*)host->h_addr);
    bzero(&(serv_addr.sin_zero), 8);
    if (connect(sockfd, (struct sockaddr*)&serv_addr,
                sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
    printf("please input the file you want to open:\n");
    scanf("%s", file_name);
    printf("filename is %s\n", file_name);
    fd = open(file_name, O_RDONLY, 0666);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    printf("press s to send file\n");
    getchar();
    while ((readbytes = read(fd, buf, MAXDATASIZE))) {
        if ((sendbytes = send(sockfd, buf, readbytes, 0)) == -1) {
            perror("send");
            exit(1);
        }
        totalbytes += sendbytes;
    }
    // shutdown read and write of socket
    shutdown(sockfd, 2);
    printf("sent %d bytes ..\n", totalbytes);
    printf("file sending finished.\n", totalbytes);
    close(sockfd);
    return 0;
}
