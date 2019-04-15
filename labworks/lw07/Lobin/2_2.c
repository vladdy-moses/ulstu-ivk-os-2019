#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>

int main()
{
std::cout << "Лабораторная работа №7 Лобина Михаила, ИСТбд-22" <<std::endl;
int semid;
key_t key = ftok("1.c", 0);
struct sembuf buf;
semid = semget(key, 1, 0666);
buf.sem_op = 1;
buf.sem_flg = 0;
buf.sem_num = 0;
semop(semid, &buf, 1);
std::cout << "Поставили условие" << std::endl;
return 0;
}
