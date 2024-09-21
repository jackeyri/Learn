// 08-03.c 获得本机时间
#include <stdio.h>
#include "string.h"
#include "time.h"
#define MAXDATASIZE 100
int main(int argc, char* argv[]) {
    time_t currentTime;
    char timebuffer[MAXDATASIZE];
    memset(timebuffer, 0, MAXDATASIZE);
    currentTime = time(NULL);
    snprintf(timebuffer, MAXDATASIZE, "%s\n", ctime(&currentTime));
    printf("time is %s", timebuffer);
    return 0;
}
