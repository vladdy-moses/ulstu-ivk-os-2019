#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{

    printf("Выполнил студент группы ИСТбд-22 Ильинский М.В.");
    int cf = open("/home/maxim/Documents/Projects/5.3lab/main.c", O_RDONLY);
    struct stat st;
    lstat("/home/maxim/Documents/Projects/5.3lab/main.c", &st);
    int s = st.st_size;
    key_t key = ftok("/home/maxim/Documents/files", 1);
    int sh;
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0666))<0)
    {
        if(errno != EEXIST)
        {
            printf("Ошибка!");
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                printf("Ошибка!");
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0666);
        }
    }
    int* m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    *t = s;
    t++;
    char * c = (char *)t;
    read(cf, c, s);
    close(cf);
    shmdt(m);
    return 0;
}
