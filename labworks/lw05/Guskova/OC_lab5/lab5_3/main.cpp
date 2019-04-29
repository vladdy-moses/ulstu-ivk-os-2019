#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
//Лабораторная работа №5.3
//Организация работы с разделяемой памятью
//Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.
using namespace std;
int main()
{
    printf("Лабораторная работа №5.3\n");
    printf("Организация работы с разделяемой памятью\n");
    printf("Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.\n");
    printf("Задание: первая программа должна создавать сегмент разделяемой памяти и копировать туда\
            собственный исходный текст, вторая программа должна брать оттуда этот\
            текст, печатать его на экране и удалять сегмент разделяемой памяти из системы.\n");
    cout<<"Программа 1"<<endl;
    int cpp = open("/home/student/Documents/OC_lab5/lab5_3/main.cpp", O_RDONLY);
    struct stat st;
    lstat("/home/student/Documents/OC_lab5/lab5_3/main.cpp", &st);
    int s = st.st_size;
    key_t key = ftok("/home/student/Documents", 1);
    int sh;
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            cout<<"Ошибка!"<<endl;
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                cout<<"Ошибка!"<<endl;
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0777);
        }
    }
    int* m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    *t = s;
    t++;
    char * c = (char *)t;
    read(cpp, c, s);
    close(cpp);
    shmdt(m);
    return 0;
}
