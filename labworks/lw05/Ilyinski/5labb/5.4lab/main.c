#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    printf("Выполнил студент группы ИСТбд-22 Ильинский М.В.");
    key_t key = ftok("/home/maxim/Documents/files", 1);
    int sh = shmget(key, sizeof(int), IPC_CREAT|0666);
    int* m = (int*)shmat(sh, NULL, 0);
    int length = *m;
    shmdt(m);
    sh = shmget(key, length+sizeof(int), IPC_CREAT|0666);
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
    printf(buff);
    shmdt(m);
    shmctl(sh, IPC_RMID, NULL);
    return 0;
}
