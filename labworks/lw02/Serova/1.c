#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    //Лабораторная работа №1
    //Выполнила студентка ИСТбд-22 Серова В.И.
     printf("Лабораторная работа №1 \n");
     printf("Выполнила студентка гр.ИСТбд-22 Серова В.И.");
     int fd = 0;//файловый дескриптор
     fd = open("1.txt", O_CREAT|O_WRONLY, 777);//открываем текстовый файл, если его нет, то он будет создан, файл только для записи
     char * atxt = "TEXT FILE";
     write(fd,atxt, 9);//записываем текст в файл
     close(fd);//закрытие
    return 0;
}
