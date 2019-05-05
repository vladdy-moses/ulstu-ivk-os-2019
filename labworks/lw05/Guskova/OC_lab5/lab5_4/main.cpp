#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
//Лабораторная работа №5.4
//Организация работы с разделяемой памятью
//Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.
using namespace std;
int main()
{
    printf("Лабораторная работа №5.4\n");
    printf("Организация работы с разделяемой памятью\n");
    printf("Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.\n");
    printf("Задание: первая программа должна создавать сегмент разделяемой памяти и копировать туда\
            собственный исходный текст, вторая программа должна брать оттуда этот\
            текст, печатать его на экране и удалять сегмент разделяемой памяти из системы.\n");
    key_t key = ftok("/home/student/Documents", 1);
    int sh = shmget(key, sizeof(int), IPC_CREAT|0777);
    int* m = (int*)shmat(sh, NULL, 0);
    int length = *m;
    shmdt(m);
    sh = shmget(key, length+sizeof(int), IPC_CREAT|0777);
    m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    t++;
    char* c = (char *) t;
    char buff[length];
    for (int i = 0; i < length-1; i++)
    {
        buff[i] = *c;
        c++;
    }
    cout<<buff<<endl;
    shmdt(m);
    shmctl(sh, IPC_RMID, NULL);
    return 0;
}
