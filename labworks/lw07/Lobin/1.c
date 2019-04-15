#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>

int main()
{
std::cout << "Лабораторная работа №7 Лобина Михаила, ИСТбд-22" << std::endl;
int semid, errno;
key_t key;
struct sembuf buf;
key = ftok("1.c",0);
semid = semget(key, 1, 0666|IPC_CREAT|IPC_EXCL);
buf.sem_op=-1;
buf.sem_flg = 0;
buf.sem_num = 0;
semop(semid, &buf, 1);
std::cout << "Дождались события" << std::endl;
semctl(semid,0, IPC_RMID, NULL);
return 0;
}
