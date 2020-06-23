all: kp8

kp8: list.o main.o
	gcc list.o main.o -o kp8

list.o: list.c list.h
	gcc -c list.c

main.o: main.c list.h
	gcc -c main.c

clean: 
	rm -rf *.o 



