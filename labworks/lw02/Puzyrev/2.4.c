#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    ///Лабораторная работа №2.4
     printf("Лабораторная работа №2.4 \n");
     printf("Выполнил студент гр.ИСТбд-21 Пузырев И.И.");
     int fd = 0;///файловый дескриптор
     fd = open("1.txt", O_CREAT|O_WRONLY, 777);///открываем текстовый файл, если его нет, то он будет создан, файл только для записи
     char * atxt = "TEXT IN MY FILE";
     write(fd,atxt, 16);///записываем текст в файл
     close(fd);///закрытие
    return 0;
}
