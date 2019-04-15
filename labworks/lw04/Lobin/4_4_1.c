#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

int main()
{
int fd, data; size_t size; char name[] = "1.txt";
(void)umask(0);
data = 451;
mknod(name, S_IFIFO|0666, 0);
fd = open(name, O_WRONLY);
write(fd, &data, 2);
close(fd);
return 0;
}

