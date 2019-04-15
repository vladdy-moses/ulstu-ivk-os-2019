#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

int main()
{
int fd[2], forks, number;
pipe(fd);
forks = fork();

if (forks > 0)
{
close(fd[0]);
for (int i =0; i < 100; i++)
number++;
write(fd[1], &number, 2);
close(fd[1]);
}else
{
close(fd[1]);
read(fd[0], &number, 2);
while(number >0)
std::cout<< number-- << std::endl;
close(fd[0]);
}
return 0;

}
