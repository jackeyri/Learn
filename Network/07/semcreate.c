// semcreate.c  创建有名信号量
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
char semName1[] = {"nmsem1"};
char semName2[] = {"nmsem2"};
int main(int argc, char* argv[]) {
    sem_t* sem1 = NULL;  // 控制print进程运行的信号量
    sem_t* sem2 = NULL;  // 控制创建进程结束的信号量
    sem1 = sem_open(semName1, O_CREAT | O_RDWR, 0666, 0);  // 信号量初值为0
    if (sem1 == SEM_FAILED) {  // 有名信号量创建失败
        perror("sem_open nmsem1");
        return -1;
    }
    sem2 = sem_open(semName2, O_CREAT | O_RDWR, 0666, 0);  // 信号量值为 0
    if (sem2 == SEM_FAILED) {  // 有名信号量创建失败
        perror("sem_open  nmsem2");
        return -1;
    }
    printf("Waiting for sem2.\n");
    sem_wait(sem2);        // 等待结束信号量
    sem_close(sem1);       // 关闭有名信号量
    sem_close(sem2);       // 关闭有名信号量
    sem_unlink(semName1);  // 删除有名信号量
    sem_unlink(semName2);  // 删除有名信号量
}