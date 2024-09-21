// 10-03.c文件传输接收端支持文件名接收
// 接收端  listen
#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 100
void error_handling(char* message);
int main(int argc, char* argv[]) {
    int sd;
    FILE* fp;
    char buf[BUF_SIZE];
    int read_cnt;
    struct sockaddr_in serv_adr, clnt_adr;
    int serv_sd, clnt_sd, fd_creat;
    int iRecvLen;
    socklen_t clnt_adr_sz;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sd = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
    // 绑定监听端口
    bind(serv_sd, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
    // 执行监听
    listen(serv_sd, 5);
    printf("listen... \n");
    clnt_adr_sz = sizeof(clnt_adr);
    // 连接建立
    clnt_sd = accept(serv_sd, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
    printf("Client connect success... \n");
    // 接收文件名称
    memset(buf, 0, BUF_SIZE);
    iRecvLen = (int)recv(clnt_sd, buf, BUF_SIZE, 0);
    printf("File name :%s  namelen:%d\n", buf, iRecvLen);
    fd_creat = open(buf, O_RDWR | O_CREAT, 0666);
    printf("File open ,fd_creat=%d\n", fd_creat);
    memset(buf, 0, BUF_SIZE);
    sprintf(buf, "Ready to receive.");
    send(clnt_sd, buf, strlen(buf), 0);

    // 从socket资源接收数据
    while ((read_cnt = recv(clnt_sd, buf, BUF_SIZE, 0)) != 0)
        // 将数据写入文件
        write(fd_creat, buf, read_cnt);
    puts("Received file data.");
    close(fd_creat);
    // 关闭socket资源
    close(sd);
    return 0;
}
