#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define AUTHOR "Нгуен Хыу Ан"
#define GROUP "ИСТбд-21"
#define LAB_NUM 5

void print_author_and_group() {
    printf("Лабораторная работа №%d\n Выполнил студент %s группы %s \n\n", LAB_NUM,AUTHOR, GROUP);
}

int main() {
    char *str;
    int shmid;
    char pathname[] = "1.c";
    key_t key;
    FILE *f;
    
    print_author_and_group();
    
    key = ftok(pathname,0);

    f = fopen(pathname, "r");
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fclose(f);

    shmid = shmget(key, size, 0);

    str = (char *)shmat(shmid, NULL, 0);

    printf("Program source \n%s", str);

    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;

}
