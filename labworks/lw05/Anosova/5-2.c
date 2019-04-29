/*Лабораторная работа № 5. Организация работы с разделяемой памятью.
Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.
Задание: Вторая программа должна брать из сегмента разделяемой памяти тест,
печатать его на экране и удалять сегмент разделяемой памяти из системы*/

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

    fd = fopen("1.c", "r");
    fseek(fd, 0, SEEK_END);
    size = ftell(fd);
    fclose(fd);

    if((shmid = shmget(key, size, 0)) < 0)
    {
         if(errno != EEXIST)
        {
            printf("Can't create shared memory \n");
            exit(-1);
        }
        else
        {
            if((shmid = shmget(key, size, 0)) < 0)
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

    printf("%s", s);

    if(shmdt(s) < 0)
    {
        printf("Can't detach shared memory \n");
        exit(-1);
    }

    if(shmctl(shmid, IPC_RMID, NULL) < 0)
    {
        printf("Can't delete shared memory \n");
        exit(-1);
    }

    return 0;
}
