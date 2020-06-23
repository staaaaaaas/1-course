all: kp9

kp9: sort.o main.o
	gcc sort.o main.o -lm -o kp9

sort.o: sort.c sort.h
	gcc -c  sort.c

main.o: main.c sort.h
	gcc -c main.c

clean: 
	rm -rf *.o 


