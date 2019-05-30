#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 3.1\n");

    int fd[2],res;
    size_t size;
    char resstring[14];
    //Создание канала
    int pr=pipe(fd);
    if (pr==-1)
    {
        printf("Error");
    }
    if (pr==0)
    {
        res=fork();//порождаем новый процесс
        if(res>0)//работает родительский процесс
        {
            close(fd[0]);//входной поток данных не понадобится
            size=write(fd[1],"Hello, world!",14);//запись строки в поток
            close(fd[1]);//закрываем входной поток и завершаем работу родителя
            printf("Parrent exit");
        }
        else
        {//работает порожденный процесс
            close(fd[1]);//выходной поток данных не понадобится
            size=read(fd[0],resstring,14);//Чтение строки из канала
            printf("%s\n",resstring);  //Печать прочитанной строки
            close(fd[0]);//закрыть входной поток и завершить работу
        }

    }
    //Запись всей строки вместе с признаком конца строки в канал



    return 0;
}
