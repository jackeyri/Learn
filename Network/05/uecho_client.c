// uecho_client.c
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define BUF_SIZE 30

void error_handling(char* message);

int main(int argc, char const* argv[]) {
    int sock;
    char message[BUF_SIZE];
    int str_len;
    socklen_t adr_sz;
    struct sockaddr_in serv_adr, from_adr;
    if (argc != 3) {
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        exit(1);
    }
    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        error_handling("UDP socket() create failed.");
    }
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = inet_addr(argv[1]);  // IP
    serv_adr.sin_port = htons(atoi(argv[2]));       // PORT
    while (1) {
        fputs("Insert message(q to quit): ", stdout);
        fgets(message, sizeof(message), stdin);
        sendto(sock, message, strlen(message), 0, (struct sockaddr*)&serv_adr,
               sizeof(serv_adr));
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n")) {
            break;
        }
        // sendto(sock, message, strlen(message), 0, (struct
        // sockaddr*)&serv_adr,
        //        sizeof(serv_adr));
        adr_sz = sizeof(from_adr);
        str_len = recvfrom(sock, message, BUF_SIZE, 0,
                           (struct sockaddr*)&from_adr, &adr_sz);
        message[str_len] = 0;
        printf("Message from server: %s\n", message);
    }
    close(sock);
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
