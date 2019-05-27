#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

///Алиуллин Азат. ИСТбд-21. Лабараторная работа 2.
int main()
{
    int fd = 0;
    fd = open("txt2_1.txt", O_CREAT|O_WRONLY, 777);
    char * atxt = "TEXT FILE 2 FROM CODE";
    write(fd,atxt, 21);
    close(fd);
    return 0;
}
