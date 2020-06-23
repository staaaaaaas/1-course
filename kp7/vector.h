#include <stdbool.h>
#include <stdlib.h>


typedef struct{
	int* data;
	int size;
	int max;
} vector;


vector* create_vector (int sz);


bool is_empty_vector (vector* v);


int size_vector (vector* v);


int load_vector (vector* v, int i);


void save_vector_matrix (vector* v, int i, int* t);


void save_vector (vector* v, int i, int t);


void resize_vector (vector* v, int sz);


bool is_equal_vectors (vector* l, vector* r);


void destroy_vector (vector* v);
	

void fill_null (vector* v, int start, int stop);


void print_vector (vector* v);
