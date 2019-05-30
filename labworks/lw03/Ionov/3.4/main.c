#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    /* Пример создания нового процесса с одинаковой работой процессов
    ребенка и родителя */
    printf("Лабораторная работа №3.4\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
    execle("/bin/ls", "-ahl", NULL, envp);//Аргумент envp содержит переменные окружения, установленные в операционной системе для данного пользователя
    return 0;
}
