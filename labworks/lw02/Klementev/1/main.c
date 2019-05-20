#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №2 Часть 1, выполнили Клементьев С.В., группа ИСТбд-21\n");
    int fd = 0;
    /* O_WRONLY – если над файлом в дальнейшем будут осуществляться
только операции записи;
    O_CREAT – если файла с указанным именем не существует, он должен
быть создан;
    777-права доступа к данному файлу;*/
    fd = open("txt.txt", O_CREAT|O_WRONLY, 777);
    if (fd==-1) printf("Что-то пошло не так");
        char * atxt = "This should be a text";
        write(fd,atxt, 10);
    close(fd);
    return 0;
}
