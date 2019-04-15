#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
std::cout << "Лабораторная работа №5 Лобина Михаила, ИСТбд-22" << std::endl;
int *array, shmid, size;
FILE *f;
key_t key;
key = ftok("1_1.c",0);
f = fopen("1_1.c", "r");
fseek(f, 0L, SEEK_END);
size = ftell(f);
rewind(f);
shmid = shmget(key, size+1, 0666|IPC_CREAT|IPC_EXCL);
char *s = (char*)shmat(shmid, NULL, 0);
fread (s, 1, size, f);
fclose(f);
shmdt((void*)s);
return 0;
}
