all: kp6

kp6: vector.o main.o
	gcc vector.o main.o -o kp6

vector.o: vector.c vector.h
	gcc -c vector.c

main.o:	main.c vector.h
	gcc -c main.c

clean: 
	rm -rf *.o 


