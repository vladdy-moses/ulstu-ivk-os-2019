#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №2 Часть 1, выполнил  Мельников Г.Р., группа ИСТбд-21\n");
    int fd = 0;
    /* O_WRONLY – если над файлом в дальнейшем будут осуществляться
только операции записи;
    O_CREAT – если файла с указанным именем не существует, он должен
быть создан;
    777-права доступа к данному файлу;*/
    fd = open("Gleb222.txt", O_CREAT|O_WRONLY, 0777);
    if (fd==-1) printf(" Произошла ошибка ");
        char * atxt = "Write your text hear";
        write(fd,atxt, 20);
    close(fd);
    return 0;
}
