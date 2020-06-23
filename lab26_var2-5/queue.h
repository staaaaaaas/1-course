#include <stdbool.h>

#include "vector.h"




typedef struct{
    	vector *array;
} queue;

queue * create_queue();


int get_size_queue (queue *q);


int get_top_queue (queue *q);


bool is_empty_queue (queue *q);


bool push_back_queue (queue *q, int value);


int pop_queue (queue *q);


void print_queue (queue *q);


void destroy_queue(queue *q);


