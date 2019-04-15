#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define AUTHOR "Нгуен Х.А."
#define GROUP "ИСТбд-21"

void print_author_and_group() {
    printf("Лабораторная работа №4\n Выполнил студент %s\n группы %s \n\n", AUTHOR, GROUP);
}

int main() {
    int file_descriptors[2], fork_result, check_pipe;
    char res_string[16];
    
    print_author_and_group();

    /**
     * #include <unistd.h>
     * int pipe(int *fd);
     * 
     * Pipe (канал, труба) - область памяти, недоступная пользовательским
     * процессам. Нужна она для передачи информации между процессами, либо 
     * внутри процесса. 
     *
     * Параметры: указатель на массив из двух целочисленных переменных *fd.
     * 		  если процесс завершился нормально - fd[0] будет занесён
     * 		  	файловый дескриптор, соотв. входному потоку данных
     * 		  	(чтение)
     * 		  	fd[1] - выходной поток данных (запись) 
     * 
     * Возвращаемые значения: 0 - если норм. завершение
     * 			      -1 - !норм. завершение
     */
    
    /* Создаём канал (новый процесс также сделает, наверно) */
    check_pipe = pipe(file_descriptors);
    /* Проверяем результат создания канала */
    if (check_pipe == -1) exit(1); // если -1 - выход

    /* Создаём новый процесс */
    fork_result = fork(); 

    switch(fork_result) {
        case -1:
            exit(1);	
            break;
        case 0:
            // Если потомок
            read(file_descriptors[0], res_string, 16);
	    // Т.к. файловый дескриптор общий, нужно подождать
            write(file_descriptors[1], "Hi, I'm child!", 16);
            printf("Child get message - %s\n", res_string);
            break;
        default:
            // Если родитель
            write(file_descriptors[1], "Hi, I'm parent!", 16);
	    sleep(1);
            read(file_descriptors[0], res_string, 16);
            printf("Parent get message - %s\n", res_string);
            break;	    
    }

    // Закрываем каналы ввода и вывода
    close(file_descriptors[1]);
    close(file_descriptors[0]);

    return 0;
}
