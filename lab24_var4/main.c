#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "token.h"
#include "t_queue.h"
#include "t_stack.h"
#include "token_tree.h"
#include "token_tree_stack.h"


bool Dijkstra_sort_station (t_queue * output_queue){
    	Token tok = read_token();
    	t_stack * op_stack = ts_create();
    	int prev_type = TOKEN_NONE;
    	bool unary = false;
   	while (tok.type != TOKEN_NONE){
        	switch(tok.type){
        		case TOKEN_NUM:
            			if(unary){
                			tok.value *= -1;
                			unary = false;
           			}
         			if (prev_type == TOKEN_NUM ||	
                		prev_type == TOKEN_CHAR ||
               			prev_type == TOKEN_UNARY_MINUS ||
                		prev_type == TOKEN_RBR){
                			return false;
				}
            			tq_push (output_queue, tok);
            		break;
        		case TOKEN_CHAR:
            			if (unary){
                			tok.type = TOKEN_UNARY_MINUS;
                			unary = false;
           			}
            			if (prev_type == TOKEN_NUM ||
                		prev_type == TOKEN_CHAR ||
                		prev_type == TOKEN_UNARY_MINUS){
                			return false;
				}
           			tq_push (output_queue, tok);
           		break;
        		case TOKEN_OP:
            			if (tok.value == '-' &&
                		(prev_type == TOKEN_NONE ||
                 		prev_type == TOKEN_LBR ||
                		prev_type == TOKEN_OP)){
                    			unary = true;
                    			break;
            			}
            			if(prev_type == TOKEN_OP ||
               			prev_type == TOKEN_LBR){
					return false;
				}
            			while (!ts_is_empty (op_stack) && top_token_stack (op_stack).value != '('){
                			Token op = top_token_stack (op_stack);
                			if ((is_right (tok) && priority (tok, op) < 0) ||
                    			(!is_right (tok) && priority (tok, op) <= 0)){
                        			tq_push (output_queue, ts_pop (op_stack));
                			}
                			else{
						break;
					}
            			}
            			ts_push (op_stack, tok);
            		break;
        		case TOKEN_LBR:
           	 		if (prev_type == TOKEN_NUM ||
                		prev_type == TOKEN_CHAR ||
                		prev_type == TOKEN_UNARY_MINUS){
               	 			return false;
				}
            			ts_push (op_stack, tok);
            		break;
        		case TOKEN_RBR:
            			if(prev_type == TOKEN_OP){
					return false;
				}
            			while (!ts_is_empty (op_stack) && top_token_stack (op_stack).value != '('){
              		 		tq_push (output_queue, ts_pop (op_stack));
            			}
            			if (ts_is_empty(op_stack)){
                			return false;
				}
            			else if (top_token_stack (op_stack).value == '('){
                			ts_pop (op_stack);
				}
            		break;

        		default:
            		break;

        	}
		prev_type = tok.type;
        	tok = read_token();
   	 }
   	 while (!ts_is_empty (op_stack)){
        	if (top_token_stack (op_stack).value == '('){
            		return false;
		}
       		tq_push (output_queue, ts_pop (op_stack));
    	}
    	return true;
}


void make_tree (t_queue *token_queue, token_tree * t_tree){
    	token_tree_stack * t_t_stack = tts_create();
    		while (!tq_is_empty (token_queue)){
        		Token token = tq_pop (token_queue);
        		token_tree *t_t = create_token_tree();
        		if (token.type == TOKEN_NUM ||
            		token.type == TOKEN_CHAR ||
           		token.type == TOKEN_UNARY_MINUS){
            			add_to_token_tree (t_t, token, -1);
            			tts_push (t_t_stack, t_t);
        		}
			else if(token.type == TOKEN_OP){
            			add_to_token_tree(t_t, token, -1);
            			if (!tts_is_empty (t_t_stack)){
                			add_tt_to_tt (t_t, tts_pop (t_t_stack),0);
				}
            			if (!tts_is_empty (t_t_stack)){
                			add_tt_to_tt (t_t, tts_pop (t_t_stack),1);
				}
           			 tts_push (t_t_stack, t_t);
        		}
    		}
    	add_tt_to_tt(t_tree, tts_pop (t_t_stack), -1);
}



int main(){
	printf("Enter the expression\n");
	t_queue * tq2 = tq_create();
    	if (!Dijkstra_sort_station (tq2)){
        	tq_destroy (tq2);
        	printf("Error\n");
        	return 1;
    	}
    	token_tree * tt = create_token_tree();
    	printf("Your expression in Poland\n");
    	tq_print(tq2);
    	printf("\n");
    	make_tree(tq2, tt);
    	printf("Your token tree\n");
    	print_token_tree(tt);
	printf("\n");
    	return 0;

}
