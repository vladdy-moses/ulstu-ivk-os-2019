#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    printf("lab 5.3 Musina\n");
    int cpp = open("/home/user/lab5/3/main.c", O_RDONLY);
    struct stat st;
    lstat("/home/user/lab5/3/main.c", &st);
    int s = st.st_size;
    char pathname[] = "/home/user/lab5/1";
    key_t key;
    int shmid;
    if((key = ftok(pathname,0)) < 0)
        {
            printf("Can\'t generate key\n");
            exit(-1);
        }
    if ((shmid = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            printf("Can\'t create shared memory\n");
            exit(-1);
        }
        else
        {
             if((shmid = shmget(key, 3*sizeof(int), 0)) < 0)
                {
                    printf("Can\'t find shared memory\n");
                    exit(-1);
                }
            shmctl(shmid, IPC_RMID, NULL);
            shmid = shmget(key, s+sizeof(int), IPC_CREAT|0777);
        }
    }
    int* array = (int*)shmat(shmid, NULL, 0);
    int* t = array;
    *t = s;
    t++;
    char * c = (char *)t;
    read(cpp, c, s);
    close(cpp);
    shmdt(array);
    return 0;
}

