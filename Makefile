CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -O3 -IInclude

main: main.c
	$(CC) $(CFLAGS) main.c Include/functions.c -o main

run:
	./main
