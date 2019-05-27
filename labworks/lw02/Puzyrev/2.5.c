#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>


int main()
{
    ///Лабораторная работа №2.5

  printf("Лабораторная работа №2.5 \n");
 printf("Выполнил студент гр.ИСТбд-21 Пузырев И.И.");
DIR * fd;///nип данных DIR представляет собой некоторую структуру данных, описывающую поток каталога, который открывает opendir
fd = opendir(".");///открывает поток каталога и вовращает указатель на структуру типа DIR
struct dirent * d;///специальная структура данных, описывающая одну запись в директории
int i = 50;
while(fd && i-- > 0)///распечатку содержимого каталога,
  {
   d = readdir(fd);
     if (d!=NULL)
	    printf("%s\n",d->d_name);
  }
closedir(fd);
return 0;
}
