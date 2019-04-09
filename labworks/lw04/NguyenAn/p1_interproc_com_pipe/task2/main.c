#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define AUTHOR "Нгуен Х.А."
#define GROUP "ИСТбд-21"

void print_author_and_group() {
    printf("Лабораторная работа №4\n Выполнил студент %s\n группы %s \n\n", AUTHOR, GROUP);
}

void close_fd(int file_descriptor[2]){
    close(file_descriptor[0]);
    close(file_descriptor[1]);
}

int main() {
    int parent_fd[2], child_fd[2], fork_result, check_pipe_parent, check_pipe_child;
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
    
    /* Создаём каналы */
    check_pipe_parent = pipe(parent_fd);
    check_pipe_child = pipe(child_fd);
	
    /* Проверяем результат создания канала */
    if (check_pipe_parent == -1 | check_pipe_child == -1) exit(1); // если -1 - выход

    /* Создаём новый процесс */
    fork_result = fork(); 

    switch(fork_result) {
        case -1:
            exit(1);	
            break;
        case 0:
            // Если потомок
            read(child_fd[0], res_string, 16);
            write(parent_fd[1], "Hi, I'm child!", 16);
            printf("Child get message - %s\n", res_string);
            break;
        default:
            // Если родитель
            write(child_fd[1], "Hi, I'm parent!", 16);
            read(parent_fd[0], res_string, 16);
            printf("Parent get message - %s\n", res_string);
            break;	    
    }

    // Закрываем каналы ввода и вывода
    close_fd(child_fd);
    close_fd(parent_fd);

    return 0;
}
