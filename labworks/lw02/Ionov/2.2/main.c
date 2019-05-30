#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    printf("Лабораторная работа №2.2\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
    DIR* dir;            //Dir - структура данных, описывающая поток каталога, который открывает opendir
    struct dirent *entry;//специальная структура данных, описывающая одну запись в директории
    dir=opendir(".");    //открывает поток каталога и вовращает указатель на структуру типа DIR
    while ((entry=readdir(dir))!=NULL) {//возвращает название след файла в каталоге
        //printf ("%lu - %s %d \n", entry->d_ino, entry->d_name, entry->d_type);
        printf("%s \n", entry->d_name);
    };
    closedir(dir);
    return 0;
}
