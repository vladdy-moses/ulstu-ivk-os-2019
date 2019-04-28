#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf ("Лабораторная работа №3 Часть 1, выполнили Клементьев С.В., группа ИСТбд-21\n");
    /* Тип данных pid_t является синонимом для одного из целочисленных типов языка C */
    pid_t pid, ppid;
    /* Значения идентификатора текущего процесса может быть получено: */
    pid = getpid();
    ppid = getppid();
    /* Распечатываем значения PID и PPID для текущего процесса */
    printf("pid = %d, ppid = %d", pid, ppid);
    return 0;
}
