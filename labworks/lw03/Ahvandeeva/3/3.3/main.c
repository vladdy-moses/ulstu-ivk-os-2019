#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    printf ("Лабораторная работа № 3.3.Выполнила студентка группы ИСТбд-21 Ахвандеева О.С.\n");

    pid = getpid();
    pid=fork();
    if(pid!=0)//если это не ребенок
      {
        sleep(360);//задержка процесса на 360 сек

      }
    else
      {
        exit(2); //процессу родителю ничего не возвращает
      }
}
