#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf ("Лабораторная работа №3.1 Ильинский М.В. ИСТбд-22\n");
    pid_t pid, ppid; //Тип данных pid_t является синонимом для одного из целочисленных типов языка C
    /* Узнаем идентификаторы текущего и родительского процесса*/
    pid = getpid();
    ppid = getppid();
    printf("pid = %d, ppid = %d", (int)pid, (int)ppid);
    return 0;
}
