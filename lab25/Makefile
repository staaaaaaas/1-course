all: lab26

lab26: vector.o queue.o main.o
	gcc vector.o queue.o main.o -o lab26

vector.o: vector.c vector.h
	gcc -c vector.c

queue.o: queue.c queue.h
	gcc -c queue.c

main.o: main.c queue.h vector.h 
	gcc -c main.c

clean:
	rm -rf *.o lab26
