CC=gcc
NAME=parser

all: main

main: main.o help.o commands.o
	$(CC) -o $(NAME) main.c help.c commands.c

clean:
	rm -f $(NAME) *.o
