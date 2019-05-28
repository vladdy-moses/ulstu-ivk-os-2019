#include <stdio.h>
#include <stdlib.h>

int main()
{
    mkdir("/home/asd/codeblocks/2 laba/Папка созданная программно");
    FILE * fo;
   fo = fopen("/home/asd/codeblocks/2 laba/Папка созданная программно/txt1.txt","w+t");
    fprintf( fo, "первый файл" );
    fclose(fo);

    FILE * fo2;
    fo2 = fopen("/home/asd/codeblocks/2 laba/Папка созданная программно/txt2.txt","w+t");
    fprintf( fo2, "второй файл" );
    fclose(fo2);

   // mount("/dev/dvd", "/mnt/test", "asd", 0xC0ED ,NULL );
    execl("/bin/mount", "mount", "/dev/dvd/", "/mnt/test", NULL);

    return 0;
}
