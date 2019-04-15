#include <sys/types.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char **argv, char ** envp)
{
std::cout << "Лабораторная работа №3, Лобин Михаил, ИСТбд-22, вызывает ps -l";
execl("/bin/ps", "/bin/ps", "-l", 0, envp); //Первый аргумент - что вызываем, 
			     //второй - тоже, ибо соглашение об argv 
return 0;
}
