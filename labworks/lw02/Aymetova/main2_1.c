#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
printf("лабораторная работа 2. Айметова Р.А. ИСТбд-21\n");
int fd = 0;
fd = open("txt4.dat", O_CREAT|O_RDWR, 777);
ftruncate(fd, 1000*sizeof(int));///увеличение длины файла
int * ptr = (int *) mmap(NULL, 1000*sizeof(int), PROT_WRITE, MAP_SHARED, fd, 0);///файл отображаем от начала и до конца
if (ptr == MAP_FAILED) {
printf("произошла ошибка\n");
exit(1);
}
close(fd);
int * tmpptr = ptr;
///заполняем образ файла числами
for (int i = 0; i < 1000; i++) {
(*tmpptr) = i;
tmpptr++;
}
///прекращаем отображение файла в память, отображаем на диск и освобождаем память
munmap((void*)ptr, 1000*sizeof(int));

return 0;
}
