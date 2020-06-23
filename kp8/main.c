#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "list.h"


void do_task (List *list, int k){
	Iter *iter = list->last;
	Iter *itdelete;
	Iter *stop = list->head;
	int d;
	d = list->size - k;
	int count = 1;
	if (list->size < k){
		printf (" ERROR: K > CAPACITY\n");
		return;
	}
	while (count < d  && stop -> next != NULL){
                stop = stop -> next;
                count++;
        }
	while (iter != stop){
		itdelete = Prev (iter, list);
		DeleteNode (list, iter);
		iter = itdelete;
	}
	if (iter == stop && stop == list -> head){
		DeleteNode (list, iter);
	}
}


void menu(){
	printf("Please,enter your choice:\n"
		"p to print list.\n"
		"i to insert an element to the list\n"
		"d to delete an element from the list.\n"
		"t to do task.\n"
		"s to see the size of the list.\n"
		"f to finish the programm\n");
}


int main(){
	List *l = CreateList();
	char choice;
	menu();
	do{
		int el;
        	int index;
		int k;
		scanf("%c", &choice);
		if (choice == 'p' || choice == 'i'  
		|| choice == 'd' || choice == 't' || choice == 's'
		|| choice == 'f' || choice == 'a'){
			switch (choice){
				case 'f':
					printf("The programm has been finished\n");
					break; 
				case 'p':
					PrintList(l);
					break;
				case 'i':
					scanf("%d", &index);
					scanf("%d", &el);
					Insert(l,index,el);
					break;
				case 'd':
					scanf("%d", &el);
					Iter *el_it = Search(l, el);
					if (el_it){
						DeleteNode(l,el_it);
					}
					else{
						printf("Not found\n");
					}
					break;
				case 's':
					printf("Size: ");
					printf("%d\n", Size(l));
					break;
				case 't':
					scanf("%d",&k);
					do_task (l, k); 
					break;
			}
		}
	}while (choice != 'f');
}
		 
