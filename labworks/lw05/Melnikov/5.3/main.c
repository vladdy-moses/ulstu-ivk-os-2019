#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Rus");
    printf ("Лабораторная работа №5 Часть 3, выполнил Мельников Г.Р., группа ИСТбд-21\n");
    printf ("Программа 1, которая должна создавать сегмент разделяемой памяти\n");
    printf ("и копировать туда собственный исходный текст\n");
    int filec = open("main.c", O_RDONLY);
    struct stat st;
    lstat("main.c", &st);// получают информацию об атрибутах файла
    int s = st.st_size;
    key_t key = ftok("Klych.c", 1);// создается ключ
    int sh;
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0) // создание области разделяемой памяти
    {
        if(errno != EEXIST)//системная переменная
        {
            printf("Ошибка\n");
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)// доступ к сегменту разделяемой памяти (ключ размер флаги)
            {
                printf("Ошибка\n");
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);// получение информации об области разделяемой памяти(инфа об разделенной памяти.значение которое вернул шгет.
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0777);
        }
    }
    int* m = (int*)shmat(sh, NULL, 0);//включение области разделяемой памяти в адресное пространстнво
    int* t = m;
    *t = s;
    t++;
    char * c = (char *)t;
    read(filec, c, s);
    close(filec);
    shmdt(m);
    return 0;
}
