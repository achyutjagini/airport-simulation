CC=gcc
CFLAGS=-c -Wall

all: start
start: client.o server.o
	$(CC) client.o server.o
client.o: client.c
	$(CC) $(CFLAGS) client.c
server.o: server.c
	$(CC) $(CFLAGS) server.c
clean: 
	rm -rf *o a.out a.exe
	echo Thanks, By Arvind Krishna