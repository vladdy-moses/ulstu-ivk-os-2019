/*
Лабораторная работа№ 1.
Пункт № 4.
Выполнила студентка гр. ИСТбд-22
Аносова Екатерина Романовна.
*/


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    printf ("Лабораторная работа № 1. \
    \n Пункт № 4. \
    \n Выполнила студентка гр. ИСТбд-22 \
    \n Аносова Екатерина Романовна.");

    struct stat buf;

    int f;
    f=open("txt1", O_RDWR | O_CREAT, 777);
    char* text1 = "First txt";
    write (f, text1, 9);
    close (f);

    f=open("txt2", O_RDWR | O_CREAT, 777);
    char* text2="Second txt";
    write(f, text2, 10 );
    close(f);

    stat("txt1", &buf);
    printf("\n txt1");
    printf ("\n %d mode,  %ld size", buf.st_mode, buf.st_size);
    if (S_ISLNK(buf.st_mode))
    {
        printf("This is link");
    }

    stat("txt2", &buf);
    printf("\n txt2");
    printf ("\n %d mode,  %ld size", buf.st_mode, buf.st_size);


    link("txt1", "new1");
    stat("new1", &buf);
    printf("\n new1");
    printf ("\n %d mode,  %ld size", buf.st_mode, buf.st_size);
    if (S_ISLNK(buf.st_mode))
    {
        printf("This is link");
    }

    symlink("txt2", "new2");
    lstat("new2", &buf);
    printf("\n new1");
    printf ("\n %d mode,  %ld size", buf.st_mode, buf.st_size);
    if (S_ISLNK(buf.st_mode))
    {
        printf("\n This is link");
    }

    return 0;
}
