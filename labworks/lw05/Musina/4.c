//#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    printf("lab 5.3 Musina\n");
    key_t key = ftok("/home/user/lab5/1", 1);
    int shmid = shmget(key, sizeof(int), IPC_CREAT|0777);
    int* array = (int*)shmat(shmid, NULL, 0);
    int length = *array;
    shmdt(array);
    shmid = shmget(key, length+sizeof(int), IPC_CREAT|0777);
    array = (int*)shmat(shmid, NULL, 0);
    int* t = array;
    t++;
    char* c = (char *) t;
    char buff[length];
    for (int i = 0; i < length-1; i++)
    {
        buff[i] = *c;
        c++;
    }
    printf(buff);
    shmdt(array);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
