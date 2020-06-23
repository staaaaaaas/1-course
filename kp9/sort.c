#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "sort.h"


double eps(){
        double a=1;
        while (1+a/2>1){
                a=a/2;
        }
        return(a);
}


int count_str (){
	FILE *f;
	double key_1;
	char val_1[Max];
	int kol = -1;
	if ( (f = fopen("sort","r")) == NULL )
    		printf("\nИсходный файл не может быть прочитан...");
  	else {
    		while ( !feof(f) ) {
      			fscanf(f,"%lf%s",&key_1,val_1);
      			kol++;
    		}
    	fclose(f);
  	}
	return kol;
}
	

void simple_merging_sort (){
	double key_1, key_2;
	char val_1[Max], val_2[Max];
  	int k, i, j, kol, flag;
  	FILE *f, *f1, *f2;
  	kol = 0;
  	if ( (f = fopen("sort","r")) == NULL )
    		printf("\nИсходный файл не может быть прочитан...");
  	else{
		kol = count_str ();
	}
  	k = 1;
  	while ( k < kol ){
    		f = fopen("sort","r");
    		f1 = fopen("smsort_1","w");
    		f2 = fopen("smsort_2","w");
    		if ( !feof(f) )
			fscanf(f,"%lf%s",&key_1,val_1);
    		while ( !feof(f) ){
      			for ( i = 0; i < k && !feof(f) ; i++ ){
        			fprintf(f1,"%lf %s\n",key_1,val_1);
        			fscanf(f,"%lf%s",&key_1,val_1);
      			}
      			for ( j = 0; j < k && !feof(f) ; j++ ){
        			fprintf(f2,"%lf %s\n",key_1, val_1);
        			fscanf(f,"%lf%s",&key_1,val_1);
      			}
    		}
    		fclose(f2);
    		fclose(f1);
    		fclose(f);

    		f = fopen("sort","w");
    		f1 = fopen("smsort_1","r");
    		f2 = fopen("smsort_2","r");
    		if ( !feof(f1) )
			fscanf(f1,"%lf%s",&key_1, val_1);
    		if ( !feof(f2) )
	 		fscanf(f2,"%lf%s",&key_2, val_2);
    		while ( !feof(f1) && !feof(f2) ){
      			i = 0;
      			j = 0;
      			while ( i < k && j < k && !feof(f1) && !feof(f2) ) {
        			if ( key_1 < key_2 ) {
          				fprintf(f,"%lf %s\n",key_1, val_1);
          				fscanf(f1,"%lf%s",&key_1, val_1);
          				i++;
        			}
        			else {
          				fprintf(f,"%lf %s\n",key_2, val_2);
          				fscanf(f2,"%lf%s",&key_2, val_2);
          				j++;
        			}
      			}
      			while ( i < k && !feof(f1) ) {
       				fprintf(f,"%lf %s\n",key_1,val_1);
        			fscanf(f1,"%lf%s", &key_1,val_1);
        			i++;
      			}
      			while ( j < k && !feof(f2) ) {
        			fprintf(f,"%lf %s\n",key_2, val_2);
        			fscanf(f2,"%lf%s",&key_2, val_2);
        			j++;
      			}
    		}
    		while ( !feof(f1) ) {
      			fprintf(f,"%2f %s\n",key_1,val_1);
     			fscanf(f1,"%lf%s",&key_1, val_1);
    		}
    		while ( !feof(f2) ) {
      			fprintf(f,"%2f %s\n",key_2, val_2);
      			fscanf(f2,"%lf%s", &key_1,  val_1);
    		}
    		fclose(f2);
    		fclose(f1);
    		fclose(f);
    		k *= 2;
 	}
  	remove("smsort_1");
  	remove("smsort_2");
}


void bin_search (double key){
	FILE *f=fopen("sort","r");
	char val[Max];
	int left = 0;
	int right = count_str();
	int kol = right;
	int search = -1;
	int midd;
	double key_2;
	double epsilon = eps();
	while (left <= right){
		int mid = (left + right)/2;
		if (mid == 0){
			rewind(f);
			fscanf (f,"%lf%s",&key_2, val);
			if (fabs(key - key_2) <= epsilon){
				search=1;
				printf("%2f %s\n", key_2, val);
			}
			break;
		}	
		rewind(f);
		for (int i = 0; i < mid; i++){
			fscanf (f,"%lf%s",&key_2, val);
		}
		if (fabs(key - key_2) <= epsilon){
			search=1;
			printf("%2f %s\n", key_2, val);
			break;
		}
		else if (key < key_2){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	fclose(f);
	if (search == -1){
		printf("Not found\n");
	}
	return;
}
