#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define AUTHOR "Нгуен Хыу Ан"
#define GROUP "ИСТбд-21"
#define LAB_NUM 5

/**
 *	#include <sys/types.h>
 *	#include <sys/ipc.h>
 *      
 *      Функция для генерации ключа System V IPC
 *	key_t ftok(const char *pathname, char proj_id);
 *
 *	Параметры:
 *	  const char *pathname - указатель на строку пути до существующего файла. Также процесс должен иметь право на чтение этого файла. 
 *	  			Этот файл не будет использоваться для передачи информации; информация будет храниться в адр. пространстве ОС.
 *	  			Он нужен только для генерации ключа key_t. Также указанный файл должен сохранять своё положение на диске
 *	  			до тех пор, пока все процессы, участвующие во взаимодействии, не получат ключ System V IPC.
 *	  char proj_id - из man-а - the least significant 8 bits of proj_id (which must be nonzero) to generate a key_t type 
 *
 **/

/**
 *
 * 	#include <sys/shm.h>
 *
 * 	int shmget(key_t key, size_t size, int shmflg);
 *
 * 	Эта функция создаёт область разделяемой памяти с определённым ключом или доступа к ключу к уже существующей области.
 *
 * 	Параметры:
 * 		key_t key - ключ System V IPC
 * 		size_t size - размер сегмента разделяемой памяти в байтах
 *		int shmflag - возможные флаги-константы:
 *					IPC_CREAT - если сегмент не существует, создаём
 *					IPC_EXCL - используется вместе с IPC_CREAT. Если существует -> доступ к сегменту не производится
 *							и константируется ошибочная ситуация
 * 	Возвращает: дескриптор разделяемой памяти связанный с ключом key
 * 			успешно - положительное значение
 * 			не успешно - значение -1 и устанавливает errno
 *
 * 	#include <sys/shm.h>
 *
 * 	void *shmat(int shmid, const void *shmaddr, int shmflg);
 *
 * 	Эта функция включает/вносит/attach сегмент разделяемой памяти связанный с дескриптором области разделяемой памяти shmid в
 * 	адресное пространство вызываемого процесса.
 * 	Параметры:
 * 		int shmid - дескриптор области разделяемой памяти
 * 		const void *shmaddr - если NULL -> система сама разместит сегмент в первое попавшийся доступное адресное пространство
 * 		int shmflag - если 0 -> доступны операции записи и чтения
 * 				если SHM_RDONLY -> только для чтения
 *
 * 	Возвращает:
 * 		после успешного завершения функции, shmat() увеличит на единицу значение shm_nattch в структуре данных связанный с ID 
 * 		разделяемой памяти присоединённый сегмент разделяемой памяти и вернёт адрес сегмента.
 * 		В другом случае, если сегмент разделяемой памяти не был внесён в адресное пространство, то вернёт -1.
 *
 * 	После окончания использования разделяемой памяти используем системную функцию:
 * 		int shmdt(const void *shmaddr);
 * 	Эта функция выносит/detaches сегмент разделяемой памяти расположенный по адресу, взятый из параметра shmaddr, из адресного
 * 	пространства вызываемого процесса.
 * 	В качестве параметра - адрес сегмента разделяемой памяти.	
 **/

void print_author_and_group() {
    printf("Лабораторная работа №%d\n Выполнил студент %s группы %s \n\n", LAB_NUM,AUTHOR, GROUP);
}

int main() {
    char *str; /* Указатель на разделяемую память */
    int shmid; /* IPC дескриптор для области разделяемой памяти */
    char pathname[] = "task1.c";
    key_t key; /* IPC ключ */
    FILE *f;
    
    print_author_and_group();
    
    /* Создаём ключ */
    if((key = ftok(pathname,0)) < 0){
        printf("Can\'t generate key\n");
        exit(-1);
    }

    f = fopen("task1.c", "r");
    fseek(f, 0, SEEK_END);
    long SIZE = ftell(f);
    rewind(f);

    /* Создаём разделяемую память */
    if ((shmid = shmget(key, SIZE, 0666|IPC_CREAT|IPC_EXCL)) < 0) {
        if(errno != EEXIST){
            printf("Can\'t create shared memory\n");
            exit(-1);
        } else {
            if((shmid = shmget(key, SIZE, 0)) < 0){
                printf("Can\'t find shared memory\n");
                exit(-1);
            }
        }
    }

    if((str = (char *)shmat(shmid, NULL, 0)) == (char *)(-1)){
        printf("Can't attach shared memory\n");
        exit(-1);
    }


    fread(str, 1, SIZE, f);
    fclose(f);

    if (shmdt(str) < 0){
        printf("Can't detach shared memory\n");
        exit(-1);
    }
    return 0;

}
