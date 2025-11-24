CC=gcc
CFLAGS=-fno-common -std=c11 -g -Wall -Werror -fsanitize=address -lpng -lm

all: main.o text.o commands.o
	$(CC) $(CFLAGS) main.o text.o commands.c -o cw

commands.o:
	$(CC) commands.c $(CFLAGS) -c

text.o: text.c
	$(CC) text.c $(CFLAGS) -c

main.o: main.c
	$(CC) main.c $(CFLAGS) -c

clear:
	rm -rf *.o cw
