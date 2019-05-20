#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) //Аргумент argv представляет собой массив из указателей на аргументы командной строки
{
    printf ("Лабораторная работа №3.4 Ильинский М.В. ИСТбд-22\n");
    execle("/bin/cat", "/bin/cat", "/home/student/Documents/3.5lab/main.c",0, envp);
    /* Вызов exec() заменяет пользовательский контекст текущего процесса содержимым
    некоторого исполняемого файла и устанавливает начальные значения регистров процессора */
    return 0;
}
