#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

int main()
{
int fd, result, data=222; size_t size; char name[] = "1.txt";
(void)umask(0);
fd = open(name, O_RDONLY);
read(fd, &data, 2);
std::cout<< data<<std::endl;
close(fd);
return 0;
}

