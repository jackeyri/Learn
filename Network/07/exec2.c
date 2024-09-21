// exec.c execve创建进程2
#include <stdio.h>
#include <unistd.h>
int main(void) {
    char* args[] = {"/Users/zhang/Source/exec1", NULL};
    printf("系统分配的进程号是：%d\n", getpid());
    if (execve("/Users/zhang/Source/exec1", args, NULL) < 0)
        printf("创建进程出错！\n");
    printf("你不可能看到这行输出的。");
    return 0;
}