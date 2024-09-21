// semwait.c 等待有名信号量
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
char semName1[] = {"nmsem1"};
int main(int argc, char* argv[]) {
    int i = 0;
    sem_t* sem1 = NULL;            // 控制print进程运行的信号量
    sem1 = sem_open(semName1, 0);  // 打开一个已有的信号量
    if (sem1 == SEM_FAILED) {      // 有名信号量创建失败
        perror("sem_open nmsem1");
        return -1;
    }
    printf("Wait for sem_post sem1.\n");
    sem_wait(sem1);
    printf("sem_wait(sem1) success and print data.\n");
    sem_close(sem1);  // 关闭有名信号量
}