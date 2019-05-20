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
    char resstring[14]="Hello world!";
    char name[] = "canal.fifo";

    printf("Лабораторная работа № 4 Часть 2\
            \n Потоковое межпроцессное взаимодействие \
            \n Выполнила студентка гр. ИСТбд-22  Аносова Е.Р.");

    (void)umask(0);
    resmod = mknod (name, S_IFIFO | 0666, 0);

    if (resmod == -1)
    {
        printf("ERROR FIFO");
    }

    printf("Открыт канал для записи\n");
    fd = open(name, O_WRONLY);
    if (fd == -1)
    {
        printf("ERROR");
    }

    printf("Начало записи\n");
    size = write(fd, resstring, 14);
    if(size == -1)
    {
        printf("Ошибка записи");
    }
    printf("Конец записи\n");

    close(fd);
    printf("Закрытие канала и завершение работы \n");

    return 0;
}
