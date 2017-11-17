CC = gcc
CCFLAGS = -w -Wall -g

all : test_iftun

test_iftun: test_iftun.c iftun.o
	$(CC) $(CCFLAGS) test_iftun.c -o test_iftun iftun.o
	
iftun.o : iftun.c
	$(CC) $(CCFLAGS) -c iftun.c

clean:
	- rm *.o
	- rm test_iftun
