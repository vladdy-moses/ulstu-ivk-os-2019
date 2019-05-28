#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{

    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 4.3\n");

    int file = open("main.c", O_RDONLY);
    struct stat st;
    lstat("main.c", &st);
    int s = st.st_size;
    key_t key = ftok("key.c", 1);
    int sh;
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            printf("Ошибка!\n");
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                printf("Ошибка!\n");
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
    read(file, c, s);
    close(file);
    shmdt(m);

    return 0;
}
