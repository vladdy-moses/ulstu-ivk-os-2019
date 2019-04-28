#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Rus");
    printf ("Лабораторная работа №5 Часть 3, выполнили Клементьев С.В., группа ИСТбд-21\n");
    printf ("Программа 1, которая должна создавать сегмент разделяемой памяти\n");
    printf ("и копировать туда собственный исходный текст\n");
    int filec = open("main.c", O_RDONLY);
    struct stat st;
    lstat("main.c", &st);
    int s = st.st_size;
    key_t key = ftok("Key.c", 1);
    int sh;
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            printf("Ошибка\n");
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                printf("Ошибка\n");
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0777);
        }
    }
    int* m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    *t = s;
    t++;
    char * c = (char *)t;
    read(filec, c, s);
    close(filec);
    shmdt(m);
    return 0;
}
