#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
     printf("Лабораторная работа №2.1\n");
     printf("Выполнил студент группы ИСТбд-21 Алексеенко Д.В.");
     int fd = 0;///файловый дискриптор
     fd = open("t1.txt", O_CREAT|O_WRONLY, 777);///открываем текстовый файл, если его нет, то он будет создан, файл только для записи
     char * atxt = "Text";
     write(fd,atxt, 4);///записываем текст в файл
     close(fd);///закрытие
    return 0;
}
