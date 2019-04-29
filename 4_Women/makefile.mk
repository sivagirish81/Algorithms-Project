a.out: client.o list.o state.o
	gcc -g client.o list.o state.o
client.o: client.c list.h state.h
	gcc -c -g client.c
list.o: list.c list.h state.h
	gcc -c -g list.c
state.o: state.c state.h
	gcc -c -g state.c