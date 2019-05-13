#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

/*Задание: используя системные вызовы для работы с файлами и дирек-
ториями, реализуйте программу на языке Си, позволяющую сделать распе-
чатку содержимого каталога, указав тип файла и права доступа*/

int main()
{
DIR * fd;
fd = opendir(".");
struct dirent * d;
int i = 50;
while(fd && i-- > 0)
{
d = readdir(fd);
if (d!=NULL)
	printf("%s\n",d->d_name);
}
closedir(fd);
return 0;
}
