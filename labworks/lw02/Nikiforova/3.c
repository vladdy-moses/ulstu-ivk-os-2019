#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 1.3\n");

    int fd;//файловый дескриптор
    size_t length;//длина отображаемой части файла
    int i;


    fd=open("mapped.dat",O_RDWR|O_CREAT, 0666);//открываем файл
    length=1000*sizeof(int);
    ftruncate(fd,length);//увеличиваем длину файла
    //прекращение отображения файла memory mapped в адресное пространство вычислительной системы
    int *ptr=(int*)mmap(NULL,//начало области адресного пространства
                        length,
                        PROT_WRITE,//разрешена запись
                        MAP_SHARED,//полученное отображение будет использоваться и другими процессами
                        fd,
                        0);
    close(fd);//закрываем файловый дескриптор
    if (ptr==MAP_FAILED)
    {
    //Если отобразить файл не удалось-сообщаем об ошибке
        printf("Mapping failed!\n");
        exit(2);
    }
    int *tmpptr=ptr;
    //Заполняем образ числами
    for(i=1;i<1000;i++)
    {
        (*tmpptr)=-i;
        tmpptr++;

    }
    //Прекращаем отображать файл в память, записываем содержимое на диск и освобождаем память
    munmap((void*)ptr, length);
    return 0;
}
