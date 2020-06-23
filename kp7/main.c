#include <stdio.h>
#include "vector.h"

int abs (a){
	if (a >= 0){
		return a;
	}
	else{
		return -a;
	}	
}


int main(int argc, char** argv){
	int n,m;
        int s;
	FILE* file;
	file = fopen("matrix1","r");
	fscanf(file,"%d",&n);
	fscanf(file,"%d",&m);
	s= n*m;
        vector* vec = create_vector (s);
	int M[n][m];
        for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                        fscanf (file,"%d", &M[i][j]);
                }
        }
	int f=0; int  k=0;
	for (int i=0; i<n; i++){	
		for(int j=0; j<m; j++){
			if (M[i][j] != 0){
				f=1;
			}
		}
		if (f==1){
			save_vector (vec, k, i);
			k++; 
			for(int j=0; j<m; j++){
	               		if (M[i][j] != 0){
					save_vector (vec, k, j);
					k++;
					save_vector(vec, k, M[i][j]);
					k++;
				}
			}
			save_vector (vec, k, -1);
                	k++;
			f=0;
		}
	}
	printf("ENTERED MATRIX IN VECTOR:  ");
	print_vector (vec);
	printf("\n");
	int max = load_vector (vec, 2);

	int p=0;
	vector* maxstr = create_vector(s);
	save_vector(maxstr,p,load_vector (vec, 0));
	int i=3; int c=2;
	while (i <= vec->size){	 
		c++;
		if (load_vector (vec, i) != -1){
			if (abs (load_vector (vec, i+1) > abs(max))){
				max = load_vector (vec, i+1);
				p=0;
				fill_null (maxstr, p, maxstr->size);
				save_vector(maxstr,p, i-c);
			}
			else{
				if (abs (load_vector (vec, i+1) == abs(max))){
					p++;
					if (load_vector(maxstr, p-1) != i-c){
						save_vector(maxstr,p, i-c);
					}
					else{
						p--;
					}
				}
			}
			i++;
		}
		else{
			if ((load_vector (vec, i) == -1) && (load_vector (vec, i+1) == 0)){
				break;
			}
			else{
				c=0;
				i=i+2;	
			}
		}
	}
	save_vector (maxstr, p+1, -1);
	p=0;
	int st = 0;
	while (load_vector (maxstr, p) != -1){
		st = load_vector(maxstr, p);
		st += 2;
		while (load_vector (vec, st) != -1){
			save_vector (vec, st, load_vector(vec, st) * max);
			st++;
			if (load_vector(vec,st) == -1){
				break;
			}
			st++;
		}
		p++;
	}
		
	printf("MAX:");			
	printf("%d\n",max);
	printf("RESULT MATRIX IN VECTOR:   "); 
	print_vector (vec);
        printf("\n");
	destroy_vector (vec); 
	destroy_vector (maxstr); 
}	

					
				






