#include "stdio.h"
unsigned short csum(unsigned short* addr, int count);
unsigned char data[] = {
    0x45, 0x00, 0x00, 0x54, 0xc0, 0x56, 0x40, 0x00,
    0x40, 0x01, 0x00, 0x00,                           // 0x04, 0x31
    0x0a, 0x01, 0x08, 0xf4, 0xb7, 0x02, 0xac, 0x2a};  // 这是一个IP头部分
int main(void) {
    printf("the check sum is 0x%x\n",
           csum((unsigned short*)data, sizeof(data)));
    return 0;
}
unsigned short csum(unsigned short* addr, int count) {
    /* Compute Internet Checksum for "count" bytes
     * beginning at location "addr".
     */
    long sum = 0;
    unsigned short tmp = 0;
    while (count > 1) {
        /* This is the inner loop */
        sum += (long)(*((unsigned short*)addr++));
        count -= 2;
    }
    /* Add left-over byte, if any */
    if (count > 0) {
        sum += *(unsigned char*)addr;
    }
    /* Fold 32-bit sum to 16 bits */
    while (sum >> 16) {
        sum = (sum & 0xffff) + (sum >> 16);
    }
    return ~sum;
}