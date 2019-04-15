#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#define LAST_MESSAGE 255

int main()
{
std::cout << "Лабораторная работа №8 Лобина Михаила, ИСТбд-22" << std::endl;
int quid, len;
key_t key = ftok ("server_5.c", 0);
quid = msgget(key, 0);
struct mymsg {long int mtype; struct msgs {long int address; long int data;} nums;} msg;
msg.mtype = 1;
msg.nums.data = 1;
msg.nums.address = getpid();
msgsnd(quid, &msg, sizeof(long int)*2,0);
return 0; 
}
