#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "vector.h"

#define MIN_CAP 2
#define GROW 1.5
#define DECREASE 0.75





vector *create_vector(){
    	vector * v = (vector*)malloc(sizeof(vector));
    	v -> values = (int*)malloc(sizeof(int)*MIN_CAP);
    	v -> length = 0;
    	v -> begin = 0;
    	v -> capacity = MIN_CAP;
    	return v;
}


bool is_empty_vector(vector *v){
    	return v -> length == 0;
}


int get_value_vector (vector *v, int i){
    	return (i >= v -> length ? 0 : v -> values [(v -> begin + i) % v -> capacity]);
}


void set_value_vector (vector *v , int i, int value){
    	if (i < v -> length){
		v -> values [(v -> begin + i) % v -> capacity] = value;
	}
}


bool grow (vector *v){
    	v -> capacity = v -> capacity * 3 / 2 + 1;
    	v -> values = (int*)realloc(v -> values, sizeof(int)*v -> capacity);
    	if (!v->values){
		return false;
	}
    	return true;
}


void move_values (vector *v){
    	int i;
    	int cap = v -> length;
    	int begin = v -> begin;
    	v -> begin = v -> length;
    	for (i = 0; i < v->length; i++){
        	set_value_vector (v, i, v -> values [(begin + i) % cap]);
    	}
}

bool add_vector (vector *v, int i, int value){
    	if (i > v -> length || i < 0){
		return false;
	}
    	if (v -> length == v -> capacity){	
        	if (!grow (v)){
			return false;
		}
        	move_values (v);
        	return add_vector(v, i, value);
    	}	
    	v -> length++;
    	if (i == v -> length -1){
		set_value_vector (v, i, value);
	}
    	else if (i == 0){
        	if (v -> begin != 0){
            		v -> begin--;
		}
        	else{
            		v -> begin = v -> capacity - 1;
		}
        	set_value_vector(v, 0, value);
    	}
	else{
        	for (int k = 1; k < v -> length - i; k++){
            		set_value_vector (v, -k, get_value_vector (v, v -> length - k - 1));
        	}
        	set_value_vector (v, i, value);
    	}
    	return true;
}


void decrease (vector *v){
    	int cap = v -> capacity;
    	int begin = v -> begin;
    	v -> capacity = cap * 3 / 4;
    	if (begin >= v -> capacity){
		v -> begin = v -> capacity - (cap - begin);
	}
    	for (int i = 0; i < v -> length; i++){
        	int value = v -> values [(begin + i)%cap];
        	set_value_vector (v, i, value);
    	}
    	v -> values = (int*)realloc(v -> values, sizeof(int) * v -> capacity);
}

void delete_el_vector (vector *v, int i){
    	if (i < 0 || i > v -> length){
		return;
	}
    	if (i == v -> length - 1){
		v -> length--;
	}
    	else if (i == 0){
        	if (v -> begin == v -> capacity - 1){
 			v -> begin = 0;
		}
        	else{
			v -> begin++;
		}
        v -> length--;
    	}
	else{
        	for (int k = 0; k < v -> length - i; k++){
            		set_value_vector (v, k + i, get_value_vector (v, i + k + 1));
		}
        delete_el_vector (v, v -> length - 1);
    	}
    	if (v -> length == v -> capacity / 2 && v -> capacity > MIN_CAP){
        	decrease(v);
    	}
}


void print_vector (vector *v){
    	for (int i = 0; i < v -> length; i++){
        	printf("%d ", get_value_vector (v, i));
    	}
    	printf("\n");
}

void destroy_vector (vector * v){
    	v -> values = (int*)realloc(v -> values, 0);
    	v = NULL;
    	free(v);
}
