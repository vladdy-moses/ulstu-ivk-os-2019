#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int args, char *argv[], char *envp[])
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 2.5");

    pid_t pr=fork();
    if(pr==0)
        {
            printf("Дочерний\n");
           //Загрузка новой программы в системный контекст текущего процесса
            //замена пользовательского контекста тек процесса содержимыым некоторого исполняемого файла
            execle("/bin/cat",//указатель на полный путь файла, который должен быть загружен
            "/bin/cat",//указатели на аргументы командной строки
            "main.c",0,
             envp);//содержит переменные окружения, установленные в операционной системе для данного пользовател

        }
    else if(pr==-1)
        {
            printf("Error \n");

        }
        else
        {
            printf("Родительский\n");
        }
    return 0;
}
