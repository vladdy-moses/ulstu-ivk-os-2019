#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>
#include <unistd.h>

int main()
{
std::cout << "Лабораторная работа №7 Лобина Михаила, ИСТбд-22" << std::endl;
int semid, errno, fd[2];
key_t key;
struct sembuf buf;
key = ftok("1.c",0);
semid = semget(key, 1, 0666|IPC_CREAT|IPC_EXCL);
pipe(fd);
int s = fork();
if (s != 0) //родитель
{
char ss[11];
buf.sem_op = -1;
buf.sem_num = 0;
buf.sem_flg = 0;
write(fd[1], "PARENT WRITE", 12);
semop(semid, &buf, 1);
read(fd[0], ss, 11);
std::cout << "PARENT READ: "<< ss << std::endl; 
semctl(semid, 0, IPC_RMID, NULL);
}
else //дитё
{
buf.sem_op = 1;
buf.sem_num = 0;
buf.sem_flg = 0;
char ss[12];
read(fd[0], ss, 12);
std::cout <<"CHILD READ: "<<ss<<std::endl;
semop(semid, &buf, 1);
write(fd[1], "CHILD WRITE", 11);
}
return 0;
}
