#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <iostream>
#define LAST_MESSAGE 255

int main()
{
std::cout << "Лабораторная работа №8 Лобина Михаила, ИСТбд-22" << std::endl;
int quid, sem = 0;
long int uid = 0;
key_t key = ftok ("server_5.c", 0);
quid = msgget(key, 0666|IPC_CREAT|IPC_EXCL);
if (quid < 0) return 0;
struct mymsg {long int mtype; struct msgs{long int address; long int data; } nums;} msg;
while (1)
{
  msgrcv(quid, &msg, sizeof(long int)*2, 1,0);
  if (msg.nums.address < 0) 
  {
    msgctl(quid, IPC_RMID, (msqid_ds *)NULL);
    return 0;
  }
  if (msg.nums.data < 0)
  {
    uid = msg.nums.address;
    sem = msg.nums.data;
  }
  if (msg.nums.data > 0)
  sem+=msg.nums.data;
  if (msg.nums.data == 0)
  sem = 0;
if (sem == 0)
{
  msg.mtype = uid;
  msg.nums.data = 451;	
  msgsnd(quid, &msg, sizeof(long int)*2, 0); 
  std::cout<<"Ответили клиенту с ID = " << uid << std::endl;
}
}
return 0; 
}
