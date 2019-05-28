#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 1.2\n");

    DIR *opdir;//открывает поток папки
    struct dirent *dir;//струтура данных, описывающая одну запись в директории
    //директория-файл последовательного доступа
    opdir=opendir("/");//открытие потока информации для директории
    while ((dir=readdir(opdir))!=NULL)//чтение очередной записи директории
    {
        printf(" %s [%d]", dir->d_name, dir->d_type);
    }
    closedir(opdir);
}
