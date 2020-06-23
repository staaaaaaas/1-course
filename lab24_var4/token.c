#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "token.h"


bool is_operator (int st){ // Проверятет на оператор;
	switch (st){
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return true;
		default:
			return false;
	}
}


bool is_value (int a){ // Проверяет на число;
	return ((a - '0' < 10) && (a - '0' > -1));
}


bool is_char (int c){ // Проверяет на символ (переменную);
	 return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c<= 'z'));
}


bool is_bracket (int c){ // Проверяет на скобку;
	return (c == '(' || c == ')');
}


int token_priority (Token token){ // Расставляет приоритеры операторов;
	switch (token.value){
		 case '+':
   		 case '-':
			return 0;
		case '*':
		case '/':
			return 1;
		case '^':
			return 2;
		default:
			return -1;

    	}

}


int priority (Token token1, Token token2){
	 return token1.value == '^' && token2.value == '^' ? -1: token_priority(token1) - token_priority(token2);
}


bool is_right(Token token){
	return token.type == TOKEN_OP && token.value != '^';
}


Token read_token(){ //Считывает токен;
	int c = getchar();
	while (isspace(c) && c != EOF && c != '\n' && !is_operator(c) && !is_value(c) && !is_char(c) &&  !is_bracket(c)){
		 c = getchar();
	}
	Token token;	
	if (is_operator(c)){
		token.type = TOKEN_OP;
		token.value = c;
	}
	else if (is_value(c)){
        	token.type = TOKEN_NUM;
		ungetc(c, stdin);
		scanf("%d", &token.value);
	}
	else if (is_char(c)){
		token.type = TOKEN_CHAR;
		token.value = c;
	}
	else if (c == '('){
        	token.type = TOKEN_LBR;
        	token.value = c;
	}
	else if (c == ')'){
		token.type = TOKEN_RBR;
       		token.value = c;
 	}
	else{
        	token.type = TOKEN_NONE;
       		token.value = 0;
	}
	return token;

}


void print_token(Token token){ // Печатает токин на стандартный вывод;
	switch(token.type){
		case TOKEN_OP:
			printf(" %c ", token.value);
		break;
		case TOKEN_NUM:
       			if (token.value < 0){
				printf("(");
			}
			printf("%d", token.value);
			if (token.value < 0){
				printf(")");
			}
       		break;
   		case TOKEN_CHAR:
       	 		printf("%c", token.value);
        	break;
   		case TOKEN_UNARY_MINUS:	
        		printf("(-%c)", token.value);
       		break;
    		default:

        	break;

    	}
}
