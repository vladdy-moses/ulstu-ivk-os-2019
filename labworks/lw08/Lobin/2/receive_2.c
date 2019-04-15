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
key_t key = ftok ("send_2.c", 0);
quid = msgget(key, 0);
if (quid < 0) return 0;
struct mymsg {long int mtype; struct msgs{int i;} nums;} msg;
while (1)
{
  msgrcv(quid, &msg, sizeof(msg)+1, 0,0);
  if (msg.mtype == 255) 
  {
    msgctl(quid, IPC_RMID, (struct msqid_ds *)NULL); 
    break;
  }
  std::cout << msg.nums.i << std::endl;
}
return 0; 
}
