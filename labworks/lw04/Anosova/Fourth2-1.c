/*Лабораторная работа № 4 Часть 2
Потоковое межпроцессное взаимодействие
Выполнила студентка гр. ИСТбд-22  Аносова Е.Р.*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd, resmod;
    size_t size;
    char resstring[14];
    char name[] = "canal.fifo";

    printf("Лабораторная работа № 4 Часть 2\
            \n Потоковое межпроцессное взаимодействие \
            \n Выполнила студентка гр. ИСТбд-22  Аносова Е.Р.");

    printf("Файл открыт для чтения\n");
    fd = open(name, O_RDONLY);
    if (fd == -1)
    {
        printf("ERROR");
    }

    printf("FIFO производит чтение\n");
    size = read(fd, resstring, 14);
    if(size == -1)
    {
        printf("Ошибка чтения");
    }
    printf("Полученная строка\n");

    printf("%s\n", resstring);
    printf("Закрытие канала и завершение работы\n");
    close(fd);

    return 0;
}

