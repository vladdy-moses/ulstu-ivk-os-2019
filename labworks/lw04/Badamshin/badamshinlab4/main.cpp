#include <iostream>
#include <unistd.h>
#include <sys/types.h>


using namespace std;

int main()
{
    cout <<"Бадамшин Т.И. Псбд-21 \n Лабраторная работа №4 \n Потоковое межпроцессное взаимодействие\n";
    ///канал pipe
    int fd[2];
    pipe(fd);///создание канала
    char instring[]="Bye,bye,american pie";///строка на вход
    char outstring[sizeof(instring)];///строка на выход
    int result = fork();///создать новый процесс

    switch(result){
    case -1:cout<<"ошибка";
    break;
    case 0:close(fd[1]);
    read(fd[0],outstring,sizeof(instring));///прочитать из канала
    cout<<outstring;
    close(fd[0]);
    break;
    default:close(fd[0]);
    write(fd[1],instring,sizeof(instring));///записать в канал
    close(fd[1]);



    }








    return 0;
}
