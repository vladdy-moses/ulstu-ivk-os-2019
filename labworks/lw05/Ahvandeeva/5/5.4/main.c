#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>


int main()
{
    printf("Лаб.раб.5.4 Выполнила студентка группы ИСТбд-21 Ахвандеева О.С.");
    key_t key = ftok("/home/student/new/5", 1);
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
    printf(buff);
    shmdt(m);
    shmctl(sh, IPC_RMID, NULL);

    return 0;
}
