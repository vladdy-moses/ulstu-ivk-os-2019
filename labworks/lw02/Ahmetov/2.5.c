#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

/*
	Лаб.раб. ОС №2.5
	Выполнил: Ахметов Э.Н. ИСТбд-22 
*/

int main()
{
    DIR * f;
    f = opendir(".");

    struct dirent* rdear;

    while(rdear != NULL)
    {
        rdear = readdir(f);
        printf("%s \n", rdear->d_name);
    }

    closedir(f);
    return 0;
}
