#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[], char *envp[])
{
    cout <<"Бадамшин Т.И. Псбд-21 \n Лабраторная работа №3 \n Управление процессами";
    pid_t  pidone,pidtwo;
    int a=0;
    pidone=fork(); ///создаем новый процесс
    switch(pidone){ ///swich используем для разделения логики для процессов
    case -1:cout <<"ошибка";
    break;
    case 0:cout << "дочерний процесс \n";
    execle("/bin/cat", "/bin/cat", "/home/student/Documents/text", 0, envp); ///загружаем программу в системный процесс
    break;
    default :cout <<"родительский процесс \n";
    break;
    }

    cout <<pidone<<endl; ///распечатываем значение  PID
    for(a=0;a<sizeof(envp);a++){
    cout << envp[a]<<endl; ///распечатываем переменные окружения
    }



    return 0;
}
