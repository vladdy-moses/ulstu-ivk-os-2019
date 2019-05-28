#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
    printf ("Лабораторная работа № 3.4.Выполнила студентка группы ИСТбд-21 Ахвандеева О.С.\n");
    execle("/bin/cat", "/bin/cat", "main.c", envp);
    //Аргумент envp содержит переменные окружения,
    //установленные в операционной системе для данного пользователя

    return 0;
}
