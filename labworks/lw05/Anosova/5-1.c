/*Лабораторная работа № 5. Организация работы с разделяемой памятью.
Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.
Задание: Первая программа должна создавать сегмент разделяемой памяти
и копировать туда собственный исходный текст*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <unistd.h>


int main()
{
    printf("Лабораторная работа № 5. Организация работы с разделяемой памятью.\
            \n Выполнила студентка гр. ИСТбд-22 Аносова Е.Р. \n");

    char *s;
    int shmid;
    long size;
    FILE *fd;
    key_t key;

    if((key = ftok("5-1.c", 0)) < 0)
    {
        printf("Can't generate key \n");
        exit(-1);
    }

    fd = fopen ("1.c", "r");
    fseek(fd, 0, SEEK_END);
    size = ftell(fd);
    rewind(fd);

    if((shmid = shmget(key, size+1, 0666|IPC_CREAT|IPC_EXCL)) < 0)
    {
        if(errno != EEXIST)
        {
            printf("Can't create shared memory \n");
            exit(-1);
        }
        else
        {
            if((shmid = shmget(key, size+1, 0)) < 0)
            {
                printf("Can't find shared memory \n");
                exit(-1);
            }
        }
    }

    if((s = (char*)shmat(shmid, NULL, 0)) == (char*)(-1))
    {
        printf("Can't attach shared memory \n");
        exit(-1);
    }

    fread(s, 1, size, fd);
    fclose(fd);

    if(shmdt(s) < 0)
    {
        printf("Can't detach shared memory \n");
        exit(-1);
    }
    return 0;
}
