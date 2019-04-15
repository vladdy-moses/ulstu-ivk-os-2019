#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>


int main()
{
std::cout << "Лобин Михаил, ИСТбд-22"<<std::endl;
int fd[2], fd2[2],  forks, number = 0;
pipe(fd);
pipe(fd2);
forks = fork();

if (forks > 0)
{
  close(fd[0]);
  close(fd2[1]);
  for (int i =0; i < 100; i++)
    number++;
  write(fd[1], &number, 2);
  close(fd[1]);
  read(fd2[0], &number, 2);
  for(;number<100; number++)
    std::cout<< -number<<" ";
  std::cout<<std::endl;
  close(fd2[0]); 
}else
{
  close(fd[1]);
  close(fd2[0]);
  read(fd[0], &number, 2);
  close(fd[0]);
  std::cout<<number<<std::endl;
  while(number >0)
    std::cout<< number-- << " ";
  std::cout<<std::endl;
  write(fd2[1], &number, 2);
  close(fd2[1]);
  
}
return 0;

}
