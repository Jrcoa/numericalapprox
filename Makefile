CC=gcc
CFLAGS=-Wall -Wpedantic
all: approx

approx: approximator.c incrementor.c
	$(CC) $(CFLAGS) -c approximator.c incrementor.c
	$(CC) $(CFLAGS) approximator.o incrementor.o -o approx
