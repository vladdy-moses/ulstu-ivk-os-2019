/* Пример создания нового процесса с одинаковой работой процессов
ребенка и родителя */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
///Алиуллин Азат. ИСТбд-21. Лабараторная работа 3.

int main(int argc, char *argv[], char *envp[])
{
    execle("/home/linux/hello", "/home/linux/hello", "hello.c", envp);
    return 0;
}
