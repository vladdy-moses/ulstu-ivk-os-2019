/*Лабораторная работа № 4 Часть 1
Потоковое межпроцессное взаимодействие
Выполнила студентка гр. ИСТбд-22  Аносова Е.Р.*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fdFromParentToChild[2], fdFromChildToParent[2], result, pres1, pres2;
    size_t size;
    char resstringForParent[17], resstringForChild[15];

    printf("Лабораторная работа № 4 Часть 1\
            \n Потоковое межпроцессное взаимодействие \
            \n Выполнила студентка гр. ИСТбд-22  Аносова Е.Р.");

    pres1 = pipe(fdFromChildToParent); /*Cоздание канала*/
    pres2 = pipe(fdFromParentToChild);

    if (pres1 == -1) /*Проверка на успешность*/
    {
        printf ("Канал не был создан \n");
    }
    else
    {
        printf("Канал создан успешно \n");
    }
    if (pres2 == -1) /*Проверка на успешность*/
    {
        printf ("Канал не был создан \n");
    }
    else
    {
        printf("Канал создан успешно \n");
    }

    result = fork();/*Порождаем новый процесс*/

    if (result == 0)
    {
        /*Работает порожденный процесс*/
        printf("Работает дочерний процесс\n");
        close(fdFromChildToParent[0]); /*Выходной поток данных не понадобиться*/
        close(fdFromParentToChild[1]);
        printf("Дочерний процесс начинает читать строку от родителя\n");
        size = read (fdFromParentToChild[0], resstringForChild, 17); /*Чтение строки из канала */
        if (size < 0)
        {
            printf("Чтение не удалось\n");
        }
        printf("Чтение прошло успешно\n");
        printf("%s \n", resstringForChild); /*Печать прочитанной строки */
        printf("Дочерний процесс записывает сообщение\n");
        size = write (fdFromChildToParent[1], "Hello, parent!", 15);
        if (size == -1)
        {
            printf("Запись не удалась\n");
        }
        printf("Запись прошла успешно\n");
        close(fdFromChildToParent[0]); /* Закрываем входной поток и завершаем работу дочернего процесса*/
        close (fdFromParentToChild[1]);
        printf("Дочерний процесс завершает работу\n");
    }
    else if (result > 0) /*Работает родительский процесс*/
    {
        printf("Работает родительский процесс\n");
        close (fdFromParentToChild[0]); /*Входной поток данных не понадобиться*/
        close (fdFromChildToParent[1]);
        printf ("Начало записи строки \n");
        size = write (fdFromParentToChild[1], "Hello, child!", 17); /*Запись строки в поток*/
        if (size == -1)
        {
            printf("Запись не удалась\n");
        }
        printf ("Конец записи строки \n");
        printf ("Ожидание получения строки от дочернего процесса\n");
        size = read (fdFromChildToParent[0], resstringForParent, 15);
        if (size < 0)
        {
            printf("Чтение не удалось\n");
        }
        printf ("Чтение прошло успешно\n");
        printf ("%s \n", resstringForParent);
        close (fdFromParentToChild[1]); /*Закрываем выходной поток данных и завершаем работу родителя*/
        close (fdFromChildToParent[0]);
        printf("Завершение процесса родительского процесса \n ");

    }
    else
    {
        printf("Процесс не был создан. Ошибка! \n");
    }
    return 0;
}

