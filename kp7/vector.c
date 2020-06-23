#include <stdio.h>
#include "vector.h"


const int CAP=2;


void fill_null (vector* v, int start, int stop){
        for (int i = start; i != stop; ++i){
                v->data[i] = 0;
        }
}


vector* create_vector (int sz){
	vector* v = malloc(sizeof(vector));
	v->size = sz;
	v->max = CAP * v->size;
	v->data = malloc(sizeof(int) * v->size);
	fill_null (v, 0, v->size);
	return v;
}


bool is_empty_vector (vector* v){
	return v->size == 0;
}


int size_vector (vector* v){
	return v->size;
}


int load_vector (vector* v, int i){
	if ((i >= 0) && (i < v->size)){
		return v->data[i];
	}
}


void save_vector (vector* v, int i, int t){
	 if ((i >= 0) && (i < v->size)){
		v->data[i] = t;
	}
}


void resize_vector (vector* v, int sz){
	if (v->max > sz){
	}
	else{
		v->max = CAP * v->max;
		v->data = realloc (v->data, sizeof(int) * v->max);
	}
	v->size = sz;
}


bool is_equal_vectors (vector* l, vector* r){
	if (l->size != r->size){
		return false;
	}
	for (int i = 0; i < l->size; i++){
		if ( l->data[i] != r->data[i]){
			return false;
		}
	}
	return true;
}


void destroy_vector (vector* v){
	v->size = 0;
	free (v->data);
}


void print_vector (vector* v){
	for (int i=0; i <= v->size; i++){
                printf("%d", v->data[i]);
        }
}
