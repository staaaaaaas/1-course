all: lab24

lab24: token.o t_queue.o t_stack.o token_tree.o token_tree_stack.o main.o
	gcc  token.o t_queue.o t_stack.o token_tree.o token_tree_stack.o main.o -o lab24

token.o: token.c token.h
	gcc -c token.c

t_queue.o: t_queue.c t_queue.h
	gcc -c t_queue.c

t_stack.o: t_stack.c t_stack.h
	gcc -c t_stack.c

token_tree.o: token_tree.c token_tree.h
	gcc -c token_tree.c

token_tree_stack.o: token_tree_stack.c token_tree_stack.h
	gcc -c token_tree_stack.c

main.o: main.c token_tree_stack.h token_tree.h t_stack.h t_queue.h  token.h
	gcc -c main.c

clean:
	rm -rf *.o 

