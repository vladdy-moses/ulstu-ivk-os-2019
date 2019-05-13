#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

/*
	Лаб.раб. ОС №5.3
	Выполнил: Ахметов Э.Н. ИСТбд-22 
*/


int main()
{
    printf("program 1");

    int cpp = open("/home/emil/Documents/4/4_3/main.cpp", O_RDONLY);

    struct stat st;

    lstat("/home/emil/Documents/4/4_3/main.c", &st);

    int s = st.st_size;

    key_t key = ftok("/home/myfiles/files", 1);

    int sh;

    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            printf("error");
            exit(-1);
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                printf("error");
                exit(-1);
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

    read(cpp, c, s);
    close(cpp);
    shmdt(m);
    return 0;
}
