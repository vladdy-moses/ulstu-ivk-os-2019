#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
  {
    printf("Лабораторная работа №3.5\n");
    printf("Выполнил студент группы ИСТбд-21 Алексеенко Д.В.\n");
    if (fork()==0)
        execle("/bin/cat", "/bin/cat", "main.c", envp);///Аргумент envp содержит переменные окружения,
            ///установленные в операционной системе для данного пользователя
        ///Переменные окружения можно взять те же, что передаются в функцию main()
    else printf("%s","Что-то пошло не так...");
    return 0;

  }
