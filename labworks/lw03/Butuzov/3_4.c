#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[], char *envp[]) //Аргумент argv представляет собой массив из указателей на аргументы командной строки
{
    /*Задание: напишите программу, которая распечатывает на экране значения переменных окружения.*/
    printf ("Бутузов А.Е. ИСТбд-22 №3.4\n");
    execle("/usr/bin/printenv", "/usr/bin/printenv", 0, envp);
    return 0;
}
