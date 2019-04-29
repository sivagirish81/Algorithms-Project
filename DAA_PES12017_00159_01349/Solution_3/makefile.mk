a.out: client_list.o list.o state.o
	gcc -g client_list.o list.o state.o
client_list.o: client_list.c list.h state.h
	gcc -c -g client_list.c
list.o: list.c list.h state.h
	gcc -c -g list.c
state.o: state.c state.h
	gcc -c -g state.c