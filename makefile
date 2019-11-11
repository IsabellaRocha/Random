ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o randfile.o
	$(CC) -o program main.o randfile.o

main.o: main.c randfile.h
	$(CC) -c main.c

randfile.o: randfile.c randfile.h
	$(CC) -c randfile.c

run:
	./program
