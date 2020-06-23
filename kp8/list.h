#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct ITER{
  	struct ITER* next;
  	int value;
}Iter;


typedef struct LIST{
  	Iter* head;
  	Iter* last;
  	int size;
}List;


Iter* CreateNode (int val);


List* CreateList();


void AddNode (List* list, int val);


void Insert (List* list, int index, int val);


void PrintList (List* list);


Iter* Prev (Iter* iter, List* list);


int DeleteNode (List* list, Iter* iter);


Iter* Search (List* list, int val);
	

int Size (List* list);



