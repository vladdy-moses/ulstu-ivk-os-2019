#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Лабораторная работа №2\n");
    printf("Выполнил студент группы ИСТбд-22 Каяшов П.А./n");
     int fd = 0;///файловый дескриптор
     fd = open("1.txt", O_CREAT|O_WRONLY, 777);///открывается текстовый файл(если его нет, создается)(только для записи)
     char * atxt = "TEXT FILE";
     write(fd,atxt, 9);///записывается текст в файл
     close(fd);///закрытие файла
    return 0;
}
