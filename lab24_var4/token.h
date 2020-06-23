#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED


#include <stdbool.h>


typedef enum{
	TOKEN_NONE,
	TOKEN_OP,
	TOKEN_UNARY_MINUS,
	TOKEN_NUM,
	TOKEN_CHAR,
	TOKEN_LBR,
	TOKEN_RBR,
}TOKEN;


typedef struct{
	TOKEN type;
	int value;
}Token;


int token_priority(Token token);


int priority(Token token1, Token token2);


bool is_right(Token token);


Token read_token();


void print_token(Token token);


#endif // TOKEN_H_INCLUDED
