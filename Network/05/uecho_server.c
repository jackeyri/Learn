// uecho_server.c
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define BUF_SIZE 30

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int serv_sock;
    char message[BUF_SIZE];
    int str_len;
    socklen_t clnt_adr_sz;
    struct sockaddr_in serv_adr, clnt_adr;
    if (argc != 2) {
        printf("Usage :%s <PORT>\n", argv[0]);
        exit(1);
    }
    serv_sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (serv_sock == -1)
        error_handling("UDP socket() create failed.");
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);  // IP
    serv_adr.sin_port = htons(atoi(argv[1]));      // PORT
    if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
        error_handling("UDP bind() failed.");
    }
    while (1) {
        memset(message, 0, BUF_SIZE);
        clnt_adr_sz = sizeof(clnt_adr);
        str_len = recvfrom(serv_sock, message, BUF_SIZE, 0,
                           (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;
        printf("message from client: %s", message);
        memset(message, 0, BUF_SIZE);
        scanf("%s", message);
        sendto(serv_sock, message, str_len, 0, (struct sockaddr*)&clnt_adr,
               clnt_adr_sz);
    }
    close(serv_sock);
    return 0;
}

/**
 * 错误处理：将信息输出到标准输出，然后退出进程
 */
void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
