#include <stdlib.h>
#include <stdio.h>

#include "queue.h"





queue * create_queue(){
    	queue *q = (queue*)malloc(sizeof(queue));
    	q -> array = create_vector();
    	return q;
}


int get_size_queue (queue *q){
    	return q -> array -> length;
}


int get_top_queue (queue *q){
    	return get_value_vector (q -> array, 0);
}


bool is_empty_queue (queue *q){
    	return is_empty_vector (q -> array);
}


bool push_back_queue (queue *q, int value){
    	return add_vector (q -> array, q -> array-> length, value);
}


int pop_queue (queue *q){
    	int val = get_value_vector (q->array, 0);
    	delete_el_vector (q -> array, 0);
   	return val;
}


void print_queue (queue * q){
    	print_vector (q -> array);
}


void destroy_queue (queue *q){
    	destroy_vector (q -> array);
    	free(q);
}

