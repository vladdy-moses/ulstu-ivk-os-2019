#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define AUTHOR "Нгуен Хыу Ан"
#define GROUP "ИСТбд-21"

void print_author_and_group() {
    printf("Лабораторная работа №4\n Выполнил студент %s\n группы %s \n\n", AUTHOR, GROUP);
}

int main(int argc, char **argv) {
    int fd, mknod_res, csym;
    char res_str[32];
    const char *pathfile = "./file.fifo";

    print_author_and_group();  
    
    if (access(pathfile, F_OK) == -1) {
	(void)umask(0);
    	mknod_res = mknod(pathfile, S_IFIFO | 0666, (dev_t)0);
    	if (mknod_res == -1) {
	    printf("Создание FIFO - неудача.");
	    exit(1);
    	}
    }

    /**
     * Если FIFO открывается только для чтения, и флаг O_NDELAY не задан ->
     * то процесс, вызвавший mknod(), блокируется до тех пор пока другой процесс
     * не откроет его для записи.  
     **/
    printf("Файл открыт для чтения.");
    fd = open(pathfile, O_RDONLY);

    read(fd, res_str, 32); 
    printf("That process read some message - %s\n", res_str);

    printf("Канал FIFO закрыт.");
    close(fd);
    
    printf("Канал удалён.");
    remove(pathfile);

    return 0;
}
