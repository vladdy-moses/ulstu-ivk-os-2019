#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <iostream>
#define LAST_MESSAGE 255

int main()
{
std::cout << "Лабораторная работа №8 Лобина Михаила, ИСТбд-22" <<std::endl;
int quid, len;
key_t key = ftok ("send_1.c", 0);
quid = msgget(key, 0666|IPC_CREAT|IPC_EXCL);
struct mymsg {long int mtype; char mtext[81];} msg;
for (int i = 0; i < 5; i++)
{
msg.mtype = 1;
strcpy(msg.mtext, "TEXT MESSAGE");
msgsnd(quid, &msg, strlen(msg.mtext)+1,0);
}
strcpy(msg.mtext, "END");
msg.mtype = 255;
msgsnd(quid, &msg, 0, 0);
return 0; 
}
