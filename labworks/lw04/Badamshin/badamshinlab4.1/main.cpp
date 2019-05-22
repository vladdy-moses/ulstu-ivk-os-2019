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
    mknod(name, S_IFIFO | 0666, 0);
    fd = open(name, O_WRONLY);
    write(fd,"Bye,Bye,American pie",30);
    close(fd);
    int a;
    cin >> a;

    return 0;
}
