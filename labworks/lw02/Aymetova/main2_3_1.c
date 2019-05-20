#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int main()
{
printf("лабораторная работа 2. Айметова Р.А. ИСТбд-21\n");
int fd = 0;
fd = open("txt4.dat", O_CREAT|O_RDONLY, 777);
int * ptr = (int *) mmap(NULL, 1000*sizeof(int), PROT_READ, MAP_SHARED, fd, 0);
close(fd);
int * tmpptr = ptr;
for (int i = 0; i < 1000; i++)
{
printf("%i ",*tmpptr);
tmpptr++;
}
munmap((void*)ptr, 1000*sizeof(int));

return 0;
}
