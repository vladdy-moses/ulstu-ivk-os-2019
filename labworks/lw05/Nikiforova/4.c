#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 4.4\n");

    key_t key = ftok("/home/alya/Рабочий стол/labar/os4.3/key.c", 1);
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
    shmdt(m);
    shmctl(sh, IPC_RMID, NULL);
    return 0;

}
