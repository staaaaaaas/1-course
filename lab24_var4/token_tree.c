#include "token_tree.h"
#include <stdlib.h>
#include <stdio.h>

token_tree* create_token_tree(){
    	token_tree * tt = (token_tree*)malloc(sizeof(token_tree));
    	tt -> root = NULL;
    	return tt;
}


bool is_empty_token_tree (token_tree * tt){
    	return tt -> root == NULL;
}


bool add_to_token_tree (token_tree * tt, Token token, int place){
    	node *t_node = (node*)malloc(sizeof(node));
    	if (!t_node){
		return false;
	}
    	t_node -> token = token;
    	t_node -> left = NULL;	
   	t_node -> right = NULL;
    	if (place == -1){
		tt -> root = t_node;
	}
    	else{
        	node ** place_node = &(tt -> root);
        	int a = 10;
       		do{
            		if (place % a == 0){
                		place_node = &(*place_node) -> right;
            		}
            		else{
                		place_node = &(*place_node) -> left;
            		}
            		place -= place % a;
            		a *= 10;
        	} while (place > 0);
        	*place_node = t_node;
   	}
    	return true;
}


void add_tt_to_tt (token_tree * tree1, token_tree * tree2, int place){
    	switch(place){
    		case 0:
        		tree1->root->right = tree2->root;
        	break;
    		case 1:
        		tree1->root->left = tree2->root;
        	break;
    		default:
       			 tree1->root = tree2->root;
	}
}


void print_nodes (node * t_node){
    	bool bracket = false;
    	if (t_node -> left != NULL){
        	if (t_node -> left -> token.type == TOKEN_OP)
            		if (priority (t_node -> token, t_node -> left -> token) > 0)
               			 bracket = true;
        	if (bracket) printf("(");
        	print_nodes(t_node -> left);
        	if (bracket) printf(")");
   	 }
    	print_token(t_node -> token);
    	if (t_node -> right != NULL){
        	bracket = false;
        	if (t_node -> right -> token.type == TOKEN_OP)
            		if (priority (t_node -> token, t_node -> right -> token) > 0)
                		bracket = true;
       	 	if (bracket) printf("(");
       	 	print_nodes(t_node->right);
        	if (bracket) printf(")");

    	}	
}


void print_token_tree(token_tree * tt){
    print_nodes(tt->root);
}

void destroy_node (node * t_node){
    	if(t_node->left){
		destroy_node (t_node->left);
	}
    	t_node->left = NULL;
    	if(t_node->right){
	 	destroy_node(t_node->right);
	}
    	t_node->right = NULL;
    	free(t_node);
}



void destroy_token_tree (token_tree * tt){
    	destroy_node (tt->root);
    	free(tt);
}
