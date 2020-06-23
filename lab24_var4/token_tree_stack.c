#include "token_tree_stack.h"

#include <stdlib.h>

bool tts_is_empty (token_tree_stack * tts){
    	return tts -> top == NULL;
}


token_tree_stack *tts_create(){
    	token_tree_stack * tts = (token_tree_stack*)malloc(sizeof(token_tree_stack));
    	tts -> top = NULL;
    	return tts;
}


bool tts_push (token_tree_stack * tts, token_tree * tt){
    	ts_element * new_el = (ts_element*)malloc(sizeof(ts_element));
    	if (!new_el){
		return false;
	}
   	new_el -> next = tts -> top;
    	new_el -> t_tree = tt;
    	tts -> top = new_el;
    	return true;
}


token_tree * tts_pop (token_tree_stack * tts){
    	ts_element * ts_el = tts -> top;
    	token_tree * tt = ts_el -> t_tree;
    	tts -> top = tts -> top -> next;
    	free(ts_el);
    	return tt;
}


void tts_destroy (token_tree_stack * tts){
    	while (!tts_is_empty (tts)){
        	tts_pop (tts);
    	}
    	free(tts);
}

