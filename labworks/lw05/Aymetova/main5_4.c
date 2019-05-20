#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>


int main(){
    printf("Айметова Р.А. лаб.раб 5");
    key_t key = ftok("/home/student/new/files", 1);
    int sh = shmget(key, 5*sizeof(int), IPC_CREAT|0777);
    int* m = (int*)shmat(sh, NULL, 0);
    int length = *m;
    //shmdt(m);
    //sh = shmget(key, 5*sizeof(int), IPC_CREAT|0777);
    //m = (int*)shmat(sh, NULL, 0);
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
