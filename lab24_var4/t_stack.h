#ifndef T_STACK_H_INCLUDED
#define T_STACK_H_INCLUDED


#include <stdbool.h>
#include "token.h"


typedef struct stack_element{
	struct Stack_element * next;
	Token token;
} stack_element;


typedef struct{
    	stack_element * top;
}t_stack;




t_stack * ts_create ();


bool ts_is_empty (t_stack * ts);


Token top_token_stack (t_stack * ts);


void ts_push (t_stack * ts, Token t);


Token ts_pop (t_stack * ts);


void ts_destroy (t_stack * ts);	


#endif // T_STACK_H_INCLUDED
