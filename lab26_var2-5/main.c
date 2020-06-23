#include <stdio.h>

#include "queue.h"

#define MIN(a, b) (a > b ? b : a)	




queue * merger_of_queues (queue *q1, queue *q2){
    	queue * q3 = create_queue();
    	while (!is_empty_queue (q1) || !is_empty_queue (q2)){
        	if (is_empty_queue (q1)){
			push_back_queue (q3, pop_queue (q2));
		}
        	else if (is_empty_queue (q2)){
	 		push_back_queue (q3, pop_queue (q1));
		}
        	else{
            		int min = MIN(get_top_queue (q1), get_top_queue(q2));
            		push_back_queue (q3, min);
            		if (min == get_top_queue (q1)){
				pop_queue (q1);
			}
            		else{
				pop_queue (q2);
			}

        	}	

   	 }	
    	return q3;
}


void sort_queue (queue **q){
    	if (get_size_queue (*q) < 2){
		return;
	}
    	queue * q1 = create_queue();
    	queue * q2 = create_queue();
    	while (!is_empty_queue (*q)){
        	push_back_queue (q1, pop_queue (*q));
        	if (!is_empty_queue (*q)){
			push_back_queue (q2, pop_queue (*q));
		}
    	}
    	sort_queue (&q1);
    	sort_queue (&q2);
    	*q = merger_of_queues (q1, q2);
    	destroy_queue (q1);
   	destroy_queue (q2);
}


int main(){
    	queue *q = create_queue();
    	int size;
	printf ("ENTER THE SIZE OF QUEUE\n");
    	scanf ("%d", &size);
    	for (int i = 0; i < size; i++){
        	int val;
        	scanf ("%d", &val);
        	push_back_queue (q, val);

    	}
	printf ("INITIAL QUEUE: \n");
	print_queue (q);
    	sort_queue (&q);
	printf ("RESULT QUEUE: \n");	
    	print_queue (q);
   	destroy_queue (q);
}
