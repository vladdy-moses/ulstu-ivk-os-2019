#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
int fd = 0;
fd = open("txt1.txt", O_CREAT|O_WRONLY, 322);
char * atxt = "Бутузов А.Е. ИСТбд-22 №2.1";
write(fd,atxt, 42);
close(fd);
return 0;
}
