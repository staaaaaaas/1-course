#include "t_stack.h"
#include <stdlib.h>
#include <stdbool.h>

t_stack *ts_create (){
	t_stack *ts = (t_stack*)malloc(sizeof(t_stack));
  	ts -> top = NULL;
  	return ts;
}


bool ts_is_empty (t_stack *ts){
	return ts -> top == NULL;
}


Token top_token_stack (t_stack * ts){
    	return ts -> top -> token;
}


void ts_push (t_stack *ts, Token t){
	stack_element *p = (stack_element*)malloc(sizeof(stack_element));
	p -> token = t;
  	p -> next = ts -> top;
  	ts -> top = p;
}


Token ts_pop (t_stack *ts){
	stack_element *elem = ts -> top;
  	Token t = elem -> token;
  	ts -> top = elem -> next;
  	free (elem);
  	return t;
}


void ts_destroy (t_stack *ts){
	while (!ts_is_empty (ts)){
    		ts_pop (ts);
  	}
  	free (ts);
}

