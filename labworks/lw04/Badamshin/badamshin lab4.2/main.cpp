#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main()
{
   int fd;
   char name[]="/home/student/Documents/labs/aaa.fifo";
   char resstring [30];
   mknod(name, S_IFIFO | 0666, 0);
   fd = open(name, O_RDONLY);
   read(fd, resstring, 25);
   close(fd);

    cout << resstring <<"\n";
    return 0;
}
