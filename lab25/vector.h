#include <stdbool.h>





typedef struct{
	int * values;
	int capacity;
	int length;
	int begin;
} vector;


vector * create_vector();


bool is_empty_vector (vector *v);


int get_value_vector (vector *v, int i);


void set_value_vector (vector *v, int i, int value);


bool add_vector (vector *v, int i, int value);


void delete_el_vector (vector *v, int i);


void print_vector (vector *v);


void destroy_vector (vector * v);

