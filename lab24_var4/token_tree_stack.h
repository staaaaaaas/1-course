#ifndef TOKEN_TREE_STACK_H_INCLUDED
#define TOKEN_TREE_STACK_H_INCLUDED


#include <stdbool.h>

#include "token_tree.h"


typedef struct ts_element{
    	struct ts_element * next;
    	token_tree * t_tree;
} ts_element;


typedef struct{
    	ts_element *top;
} token_tree_stack;




token_tree_stack * tts_create();


bool tts_is_empty (token_tree_stack * tts);


bool tts_push (token_tree_stack * tts, token_tree * tt);


token_tree * tts_pop (token_tree_stack * tts);


void tts_destroy (token_tree_stack * tts);


#endif // TOKEN_TREE_STACK_H_INCLUDED



