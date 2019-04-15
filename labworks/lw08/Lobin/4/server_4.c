#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <iostream>
#define LAST_MESSAGE 255

int main()
{
std::cout << "Лабораторная работа №8 Лобина Михаила, ИСТбд-22" << std::endl;
int quid, len;
key_t key = ftok ("server_4.c", 0);
quid = msgget(key, 0666|IPC_CREAT|IPC_EXCL);
if (quid < 0) return 0;
struct mymsg {long int mtype; struct msgs{long int i;} nums;} msg;
while (1)
{
  msgrcv(quid, &msg, sizeof(msg)+1, 1,0);
  if (msg.nums.i < 0) 
  {
    msgctl(quid, IPC_RMID, (msqid_ds *)NULL);
    break;
  }
  long int temp = msg.nums.i;
  msg.mtype = temp;
  msg.nums.i = 451;	
  msgsnd(quid, &msg, sizeof(msg)+1, 0); 
  std::cout<<"Ответили клиенту с ID = " << temp << std::endl;
}
return 0; 
}
