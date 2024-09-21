// sempost.c  给有名信号量增加值
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
    int i = 0;
    sem_t* sem1 = NULL;            // 控制print进程运行的信号量
    sem_t* sem2 = NULL;            // 控制创建进程结束的信号量
    sem1 = sem_open(semName1, 0);  // 打开一个已有的信号量
    if (sem1 == SEM_FAILED) {      // 有名信号量创建失败
        perror("sem_open nmsem1");
        return -1;
    }
    sem2 = sem_open(semName2, 0);  // 打开一个已有的信号量
    if (sem2 == SEM_FAILED) {      // 有名信号量创建失败
        perror("sem_open  nmsem2");
        return -1;
    }
    printf("Type char for sem_post sem1.\n");
    scanf("%d", &i);
    sem_post(sem1);
    printf("Type char for sem_post sem2.\n");
    scanf("%d", &i);
    sem_post(sem2);
    sem_close(sem1);  // 关闭有名信号量
    sem_close(sem2);  // 关闭有名信号量
}
