#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "list.h"


Iter* CreateNode (int val){
	Iter *res = (Iter*)malloc(sizeof(Iter));
 	res->value = val;
  	res->next = NULL;
  	return res;
}


List* CreateList(){
	List *list = (List*)malloc(sizeof(List));
  	list->head = NULL;	
  	list->last = NULL;
  	list->size = 0;
  	return list;
}


void AddNode (List* list, int val){ //Insert to the end
	Iter* node = CreateNode(val);
  	if(list->head == NULL){
    		list->head = node;
		list->size++;
  	}
  	else{
		list->last->next = node;
    		list->last = node;		
    		list->size++;
  	}
}


void Insert (List* list, int index, int val){ //Itsert to the place
	if (index > list->size){
    		index = list->size;
	}
  	if(index == 0){	
    		Iter *node = CreateNode(val);
    		if(list->head == NULL){
      			list->head = node;
    		}
    		else{
      			node->next = list->head;
      			list->head = node;
    		}
   		 list->size++;
  	}	
  	else{
    		Iter *node = CreateNode(val);
    		Iter *current = list->head;
    		for(int i = 0; i < index-1 && current->next != NULL; i++){
      			current = current->next;
		}
      		node->next = current->next;
      		current->next = node;
      		list->size++;
  	}	
}


void PrintList (List* list){
	Iter *iter = NULL;
  	if(list->size == 0)
  		printf("List is empty\n");
  	else{
    		printf("List:\n");
    		iter = list->head;
    		while(iter!= NULL){
      			printf("%d",iter->value);
      			iter = iter->next;
    		}
		printf("\n");
  	}
}


Iter* Prev (Iter* iter, List* list){
	if (iter == list->head){
		return NULL;
	}
	Iter *tmp = list->head;
	while (tmp != list->last && tmp->next != iter){
		tmp = tmp->next;	
	}
	return tmp;
}


int DeleteNode (List* list, Iter* iter){
	if (list->size == 0){
    		return 0;
  	}
  	if (iter == NULL){
    		return 0;
  	}
  	if (list->size == 1){
    		free(iter);
    		list->head = list->last = NULL;
  	}
  	else if (iter == list->head){
		list->head = list->head->next;
		free(iter);
	}
	else if (iter == list->last){
		list->last = Prev(iter, list);
		free(iter);
		list->last->next = NULL;
	}
	else{
		Prev(iter, list)->next = iter->next;
		free(iter);
	}
	list->size--;
	return 0;
}


Iter* Search(List* list, int val){
	Iter* iter = list->head;
	if (list->size == 0)
		return NULL;
	while (iter != NULL){
		if (iter->value == val){
			return iter;
		}
		iter = iter->next;
	}
	return NULL;	
}


int Size (List *list){
	return list->size;
}

