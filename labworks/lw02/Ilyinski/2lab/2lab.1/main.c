#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Ильинский М.В. группа ИСТбд-22 лаб.раб. №2");
    int fd = 0;//переменная файлового дискриптора
    fd = open("txt1_2lab.txt", O_CREAT|O_WRONLY, 722);
    char * atxt = "Hello world";
    write(fd,atxt, 11);
    close(fd);
    return 0;
}
