CC = gcc
CCFLAGS = -w -Wall -g

OBJ = iftun.o extremite.o

all : tunnel64d test_iftun test_extremite test_extremite_in test_extremite_out

test_iftun: test_iftun.c iftun.o
	$(CC) $(CCFLAGS) test_iftun.c -o test_iftun iftun.o

test_extremite: test_extremite.c $(OBJ)
	$(CC) $(CCFLAGS) test_extremite.c -o test_extremite $(OBJ)

test_extremite_in: test_extremite_in.c $(OBJ)
	$(CC) $(CCFLAGS) test_extremite_in.c -o test_extremite_in $(OBJ)

test_extremite_out: test_extremite_out.c $(OBJ)
	$(CC) $(CCFLAGS) test_extremite_out.c -o test_extremite_out $(OBJ)

tunnel64d: tunnel64d.c $(OBJ)
	$(CC) $(CCFLAGS) tunnel64d.c -o tunnel64d $(OBJ)


iftun.o : iftun.c
	$(CC) $(CCFLAGS) -c iftun.c

extremite.o : extremite.c
		$(CC) $(CCFLAGS) -c extremite.c

clean:
	- rm *.o
	- rm test_iftun
	- rm test_extremite
