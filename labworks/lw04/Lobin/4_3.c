#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>

int main()
{
std::cout<<"Лобин Михаил, ИСТбд-22"<<std::endl;
int fd[2], i =0;
pipe(fd);
try
{ 
  for(; i==i; i++)
    {
	if (write(fd[1],&i, 1)==-1)
break;
	std::cout<<i<<std::endl;
    }
}catch(int a)
{}
std::cout<<i<<std::endl;
return 0;

}
