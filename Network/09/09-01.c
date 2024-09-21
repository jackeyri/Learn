#include <bits/pthreadtypes.h>
#include <errno.h>
#include <linux/if_ether.h>
#include <linux/in.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
typedef struct _ethdr {
    char src_mac[6];
    char dst_mac[6];
    short type;
} ETH_HEADER;
typedef struct _iphdr  // 定义IP首部
{
    unsigned char h_verlen;         // 4位首部长度+4位IP版本号
    unsigned char tos;              // 8位服务类型TOS
    unsigned short total_len;       // 16位总长度（字节）
    unsigned short ident;           // 16位标识
    unsigned short frag_and_flags;  // 3位标志位
    unsigned char ttl;              // 8位生存时间 TTL
    unsigned char proto;            // 8位协议 (TCP, UDP 或其他)
    unsigned short checksum;        // 16位IP首部校验和
    unsigned int sourceIP;          // 32位源IP地址
    unsigned int destIP;            // 32位目的IP地址
} IP_HEADER;

int n;
pthread_t id1;
int sock;
char buffer[1518];
unsigned char *iphead, *ethhead;

/*线程函数声明*/
void pthread1(void* arg) {
    printf("it is a new thread.....\n");
    while (1) {
        printf("----------\n");
        n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        printf("%d bytes read\n", n);

        int num = 1;
        for (num = 1; num <= n; num++) {
            printf("%d ", buffer[num]);
            if (0 == (num % 16)) {
                printf(";\n");
            }
        }
        printf("\n");

        /* Check to see if the packet contains at least
         * complete Ethernet (14), IP (20) and TCP/UDP
         * (8) headers.
         */
        if (n < 42) {
            perror("recvfrom():");
            printf("Incomplete packet (errno is %d)\n", errno);
            close(sock);
            exit(0);
        }

        ethhead = buffer;
        char protocol = *(ethhead + 14 + 9);  //
        if (0x01 == protocol)                 //
        {
            printf(
                "Source MAC address: "
                "%02x:%02x:%02x:%02x:%02x:%02x\n",
                ethhead[0], ethhead[1], ethhead[2], ethhead[3], ethhead[4],
                ethhead[5]);
            printf(
                "Destination MAC address: "
                "%02x:%02x:%02x:%02x:%02x:%02x\n",
                ethhead[6], ethhead[7], ethhead[8], ethhead[9], ethhead[10],
                ethhead[11]);
        }

        IP_HEADER* ipHdr = (IP_HEADER*)(buffer + sizeof(ETH_HEADER));
        unsigned char* p = (unsigned char*)&ipHdr->sourceIP;
        printf("Source IP\t: %u.%u.%u.%u\n", p[0], p[1], p[2], p[3]);
        p = (unsigned char*)&ipHdr->destIP;
        printf("Destination IP\t: %u.%u.%u.%u\n", p[0], p[1], p[2], p[3]);
#if 0
			iphead = buffer+14; /* Skip Ethernet header */
			if (*iphead==0x45) { /* Double check for IPv4
			                  * and no options present */
			printf("Source host %d.%d.%d.%d\n",
			     iphead[12],iphead[13],
			     iphead[14],iphead[15]);
			printf("Dest host %d.%d.%d.%d\n",
			     iphead[16],iphead[17],
			     iphead[18],iphead[19]);
			printf("Source,Dest ports %d,%d\n",
			     (iphead[20]<<8)+iphead[21],
			     (iphead[22]<<8)+iphead[23]);
			printf("Layer-4 protocol %d\n",iphead[9]);
			}
#endif
    }
}
int main(int argc, char** argv) {
    int ret;
    printf("entering main thread\n");
    if ((sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_IP))) < 0) {
        perror("socket");
        exit(1);
    }

    /*创建线程pthread1*/
    ret = pthread_create(&id1, NULL, (void*)pthread1, NULL);
    if (ret != 0) {
        perror("pthread create1");
    }
    while (1) {
        printf("Main thread is running\n");
        sleep(1);
    }
}
