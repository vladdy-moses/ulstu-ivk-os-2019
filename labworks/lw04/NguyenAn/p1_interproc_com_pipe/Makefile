CC=gcc
CFLAGS=-std=gnu99

all:
	$(CC) $(CFLAGS) ./task1/main.c -o ./task1/main.out
	$(CC) $(CFLAGS) ./task2/main.c -o ./task2/main.out
	$(CC) $(CFLAGS) ./task3/main.c -o ./task3/main.out

clean:
	find . -name \*.o -type f -delete

delete:
	find . -name \*.out -type f -delete
