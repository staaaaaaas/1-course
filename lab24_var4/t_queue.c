#include "t_queue.h"
#include <stdlib.h>

t_queue* tq_create(){
	t_queue *tq = (t_queue*)malloc(sizeof(t_queue));
	tq -> front = NULL;
	tq -> back = NULL;
	return tq;
}


bool tq_is_empty (t_queue *tq){
	return tq -> front == NULL;
}


bool tq_push (t_queue *tq, Token t){
	queue_element *p = (queue_element*)malloc(sizeof(queue_element));
	p -> token = t;
	p -> next = NULL;
  	if (tq_is_empty(tq)){
    		tq -> front = p;
   		tq -> back = p;
 	}
	else{
   		tq -> back -> next = p;
		tq -> back = p;
  	}
}


Token tq_pop (t_queue *tq){
	queue_element *front_el = tq -> front;
	Token t = front_el -> token;
  	tq -> front = front_el -> next;
	front_el = NULL;
    	free(front_el);
  	return t;
}


void tq_print (t_queue *tq){
    	queue_element *tq1, *tq2;
    	tq1 = tq -> front;
    	tq2 = tq1 -> next;
    	while (tq1 != NULL){
        	print_token (tq1->token);
        	tq1 = tq2;
        	if (tq1 != NULL){
            		tq2 = tq1->next;
    		}	
	}
}


void tq_destroy (t_queue *tq){
	while (!tq_is_empty (tq)){
    		tq_pop (tq);
  	}
  	free(tq);
}
