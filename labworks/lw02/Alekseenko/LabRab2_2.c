#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>


int main()
{
  printf("Лабораторная работа №2.2\n");
 printf("Выполнил студент группы ИСТбд-21 Алексеенко Д.В.");
DIR * fd;///тип данных DIR представляет собой некоторую структура данных, описвающую поток каталога, который открывает opendir
fd = opendir(".");///служит для открытия поток информации для директории
struct dirent * d;///структура данных описывающая одну запись в директории
int i = 50;
while(fd && i-- > 0)///распечатка содержимого каталога
  {
   d = readdir(fd);/// осуществляет чтение очередной записи
     if (d!=NULL)
	    printf("%s\n",d->d_name);
  }
closedir(fd);
return 0;
}
