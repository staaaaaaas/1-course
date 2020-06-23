#ifndef TOKEN_TREE_H_INCLUDED
#define TOKEN_TREE_H_INCLUDED


#include <stdbool.h>
#include "token.h"


typedef struct node{
	struct node *left;
    	struct node *right;
    	Token token;
} node;


typedef struct{
    	node * root;
} token_tree;


token_tree *create_token_tree();


bool is_empty_token_tree(token_tree * tt);


bool add_to_token_tree(token_tree * tt, Token token, int place);


void add_tt_to_tt (token_tree * tree1, token_tree * tree2, int place);


void print_token_tree (token_tree *tt);


void destroy_token_tree(token_tree * tt);


#endif

