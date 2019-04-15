#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
std::cout << "Лабораторная работа №5, ч.2 Лобина Михаила, ИСТбд-22" << std::endl;
int *array, shmid, size;
FILE *f;
key_t key;
key = ftok("1_1.c",0);
f = fopen("1_1.c", "r");
fseek(f, 0, SEEK_END);
size = ftell(f);
fclose(f);
shmid = shmget(key, size, 0);
char * s = (char *)shmat(shmid, NULL, 0);
printf("%s", s);
shmdt((void *)s);
shmctl(shmid, IPC_RMID, NULL);
}
