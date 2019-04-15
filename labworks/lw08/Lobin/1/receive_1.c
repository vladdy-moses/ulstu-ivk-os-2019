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
key_t key = ftok ("send_1.c", 0);
quid = msgget(key, 0);
if (quid < 0) return 0;
struct mymsg {long int mtype; char mtext[81];} msg;
while (1)
{
msgrcv(quid, &msg, 20, 0,0);
if (msg.mtype == 255) 
{
msgctl(quid, IPC_RMID, (struct msqid_ds *)NULL);
return 0;
}
std::cout << msg.mtext << std::endl;
}
return 0; 
}
