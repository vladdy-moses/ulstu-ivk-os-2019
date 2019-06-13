#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>

    int main(void)
    {
    printf ("Лабораторная работа № 2.2\
            \nЛарёхин Е.Н. Псбд-21 ");
    int fd;
    int size;
    /* Файловыйдескриптор*/
    size_t length;
    /* Длина отображаемой части файла */
    int i;
    /* structA–тип  данных для заполнения файла, ptr–начальный адрес выделенной области памяти, tmpptr–указатель для перемещения внутри области памяти. */
    struct A {double f;double f2; } *ptr, *tmpptr;/* Открываемфайл*/
    fd = open("mapped.dat", O_RDWR | O_CREAT, 0666);
    /* Вычисляем будущую длину файла для записи в него 1000 структур */
    length= 1000*sizeof(struct A);
    /* Увеличиваем длину файла с помощью вызова ftruncate(). */
    ftruncate(fd,length);
    /* Файл отображаем с его начала (offset = 0) и до конца (length= длине фай-ла). */
    ptr = (struct A *) mmap (NULL, length, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
    /* Файловый дескриптор нам более не нужен, и мы его закрываем */
    close(fd);
    /* Если отобразить файл не удалось –сообщаем об ошибке */
    if ( ptr == MAP_FAILED )
    { printf("Mapping failed!\n"); exit(2);  }
    /* В цикле заполняем образ файла числами */
    tmpptr = ptr;
    for(i = 1; i <=1000; i++)
    {tmpptr->f = i;tmpptr->f2 = i*i;tmpptr++; }
    /* Прекращаем отображать файл в память, записываем содержимое отобра-жения на диск и освобождаем память.*/
    munmap((void*)ptr, length);
    struct stat st;
    stat ("mapped.dat",&st);
    size= st.st_size;
    char buf[size+1];
    fd = open("mapped.dat", O_RDWR);
    read (fd,buf,size);
    buf[size]='\0';
    close (fd);
    printf ("buf: %s\n",buf);
    return 0;
}

