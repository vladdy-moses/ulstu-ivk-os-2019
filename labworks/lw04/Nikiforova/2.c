#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 3.2\n");

    int child[2],parent[2],res;
    size_t size;
    char strPARENT[6], strCHILD[6];
    //Создание каналов
    pipe(child);//родитель, чтение потомком
    pipe(parent);//потомок, чтение родителем

    res=fork();//порождаем новый процесс
    if(res>0)//работает родительский процесс
    {
        printf("Работа родительского процесса\n");
        size=write(parent[1],"Parent",6);//запись строки в поток
        close(parent[1]);//закрываем входной поток и завершаем работу родителя
        size=read(child[0],strCHILD,6);//Чтение строки из канала
        close(child[0]);
        printf("Полученная строка из потока(родителем): %s\n",strCHILD);
    }
    else
    {//работает порожденный процесс
        printf("Работа дочернего процесса\n");
        size=read(parent[0],strPARENT,6);//Чтение строки из канала
        close(parent[0]);//выходной поток данных не понадобится
        printf("Полученная строка из потока(ребёнком): %s\n",strPARENT);  //Печать прочитанной строки
        size=write(child[1],"Child!",6);//запись строки в поток
        close(child[1]);//закрыть входной поток и завершить работу
    }
    return 0;
}




