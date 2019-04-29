a.out: client.o implementation.o
	gcc client.o implementation.o
client.o: client.c header.h
	gcc -c client.c
implementation.o: implementation.c header.h
	gcc -c implementation.c
