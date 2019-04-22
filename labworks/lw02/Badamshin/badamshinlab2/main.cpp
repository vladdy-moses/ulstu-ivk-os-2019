#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <sys/mman.h>

using namespace std;

int main()
{
    ///Бадамшин Т.И. Псбд-21
    ///лабораторная работа №1
    ///Тема: Файлы и файловая система
    int i=open("/home/comrade/Documents/read",O_RDONLY,777);
struct  stat bufstat;
memset(&bufstat,0,sizeof(bufstat));
    fstat(i,&bufstat);
    cout << bufstat.st_dev << "\n";
    char* buffer = new char[12];
    read(i,buffer,12);
    close(i);
   i=open("/home/comrade/Documents/write_file.text",O_WRONLY|O_CREAT,777);
   fstat(i,&bufstat);
    cout << bufstat.st_dev << "\n";
    write(i,buffer,12);
    close(i);
    link("/home/comrade/Documents/read","readtwo");
    symlink("/home/comrade/Documents/read","linkthree");

    ///Дирректори
    char folder[230],foldertwo[230];
    cin>>folder;
    DIR* directory=opendir(folder);

    int fr;
    dirent* dir;
   struct stat filestat;
    while(dir=readdir(directory)){
        cout << dir->d_name <<" "<<dir->d_ino<<" ";
        strcpy(foldertwo,folder);
        strcat(foldertwo,"/");
        strcat(foldertwo,dir->d_name);
        memset(&filestat,0,sizeof(filestat));
        stat(foldertwo,&filestat);
       cout <<filestat.st_mode<<"\n";

    }
    closedir(directory);

    ///отображение в память
    i=NULL;
    i=open("/home/comrade/Documents/write_file.text",O_RDONLY,777);

    char* m=(char*)mmap(NULL,20,PROT_READ,MAP_SHARED,i,0);
    close(i);
    cout << m;
    munmap((void *)m, 20);

    delete buffer;


    return 0;
}
