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
    
    key = ftok(pathname, 0);

    f = fopen(pathname, "r");
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    rewind(f);
    printf("Size of program source - %d\n", size);

    printf("shmget called...\n");
    shmid = shmget(key, size+1, 0666|IPC_CREAT|IPC_EXCL);

    printf("shmat called...\n");
    str = (char *)shmat(shmid, NULL, 0);

    fread(str, 1, size, f);

    fclose(f);
    printf("File closed.\n");

    shmdt(str);
    printf("Shared memory detached.\n");

    return 0;

}
