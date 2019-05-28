#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>


int main()
{
    printf ("Лабораторная работа №5 Часть 4, выполнил Мельников Г.Р., группа ИСТбд-21\n");
    printf ("Программа 2, которая должна брать из первой программы исходный текст,\n");
    printf ("печатать его на экране и удалять сегмент разделяемой памяти из системы\n");
    key_t key = ftok("../5.3/Klych.c", 1);
    int sh = shmget(key, sizeof(int), IPC_CREAT|0777);
    int* m = (int*)shmat(sh, NULL, 0);
    int length = *m;
    shmdt(m);
    sh = shmget(key, length+sizeof(int), IPC_CREAT|0777);
    m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    t++;
    char* c = (char *) t;
    char buff[length];
    for (int i = 0; i < length-1; i++)
    {
        buff[i] = *c;
        c++;
    }
    printf("\n%s",buff);
    shmdt(m);// уменьшение адресного пространства исключая использованную область
    shmctl(sh, IPC_RMID, NULL);
    return 0;
}
