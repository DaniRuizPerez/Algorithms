clean: a.out
	rm lista.o

a.out: Prim.c lista.o lista.h
	gcc -g Prim.c lista.o -lm

lista.o: lista.c lista.h
	gcc -c lista.c

