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
key_t key = ftok ("send_receive_3.c", 0);
quid = msgget(key, 0666|IPC_CREAT|IPC_EXCL);
struct mymsg {long int mtype; char ss[81];} msg;
int s = fork();
if (s!=0)//родитель
{
msg.mtype = 1;
strcpy(msg.ss, "PARENT SENDS");
msgsnd(quid, &msg, sizeof(msg)+1,0);
msgrcv(quid, &msg, sizeof(msg)+1, 2, 0);
std::cout << "PARENT READS:" << msg.ss << std::endl;
msgctl(quid, IPC_RMID, (msqid_ds *)NULL);
}
else //ребенок
{
msgrcv(quid, &msg, sizeof(msg)+1, 1, 0);
std::cout << "CHILD READS:" <<msg.ss << std::endl;
msg.mtype = 2;
strcpy(msg.ss, "CHILD SENDS");
msgsnd(quid, &msg, sizeof(msg)+1, 0);
}
return 0; 
}
