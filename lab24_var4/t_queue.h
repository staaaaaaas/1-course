#ifndef T_QUEUE_H_INCLUDED
#define T_QUEUE_H_INCLUDED



#include <stdbool.h>
#include "token.h"


typedef struct queue_element{
	struct queue_element * next;
    	Token token;
} queue_element;


typedef struct{
    	queue_element * front;
    	queue_element * back;
} t_queue;




t_queue * tq_create();


bool tq_is_empty (t_queue * tq);


bool tq_push (t_queue * tq, Token t);


Token tq_pop (t_queue * tq);


void tq_print (t_queue * tq);


void tq_destroy(t_queue *  tq);


#endif // T_QUEUE_H_INCLUDED
