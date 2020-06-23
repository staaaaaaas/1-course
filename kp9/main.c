#include <stdio.h>


#include "sort.h"


int main(){
	int choice;
	double key;
	printf("Sorting...\n");
	simple_merging_sort ();
	printf("Sorted\n");
	printf("Ether your choice : 1-Find element 0-Finish the programm\n");
	while (1){
		scanf("%d", &choice);
		if (choice == 0){
			printf("The programm has been finished\n");
			break;
		}
		else if (choice == 1){
			scanf("%lf", &key);
			bin_search (key);
		}
		else{
			printf("Wrong input, enter again\n");
		}
	}
	return 0;
}


	
