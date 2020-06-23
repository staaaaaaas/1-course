#include<stdio.h>
#include<string.h>
#include<math.h>
#include"students.h"

double eps(){
        double a=1;
        while (1+a/2>1){
                a=a/2;
        }
        return(a);
}

int main(int argc, char *argv[]){
	FILE *fIn,*fOut;
	int l=sizeof(student);
	int n=0;
	if(argc==1){
		if((fIn=fopen("Base.dat","rb"))==NULL){
			printf("Cannot input");
			return 1;
		}
		if((fOut=fopen("output.txt","w"))==NULL){
			printf("Cannot output");
			return 1;
		}
	}
	else if(argc==2){
		if((fIn=fopen(argv[1],"rb"))==NULL){
			printf("Cannot input");
			return 1;
		}
		if((fOut=fopen("output.txt","w"))==NULL){
			printf("Cannot output");
			return 1;
		}
	}
	else{
		if ((fIn=fopen(argv[1],"rb"))==NULL){
			printf("Cannot input");
			return 1;
		}
		if ((fOut=fopen(argv[2],"w"))==NULL){
			printf("Cannot output");
			return 1;
		}
	}

	double mid;
	double max = -1;
	double epsilon = eps();
	int array[10];	
	char gen;
	while(!feof(fIn)){
		student1=student;
		fread(&student,l,1,fIn);
		if (strcmp(student.fam,student1.fam )){
			mid = (student.mark_informatics + student.mark_mathan + student.mark_descrmat) / 3;
			if (mid > max){
				max = mid;
			}
		}
	}
	printf("%lf\n", max);
	rewind(fIn);
	for (int i = 0; i<10; i++){
        	array[i]=0;
        }	
	while(!feof(fIn)){
		student1=student;
		fread(&student,l,1,fIn);
		if (strcmp(student.fam,student1.fam)){
			gen = student.gender;
			if (gen == 'f' || gen == 'F'){
				mid = (student.mark_informatics + student.mark_mathan + student.mark_descrmat) / 3;
				if (fabs(max - mid) <= epsilon){
					array[student.group]++ ;
				}
			}
		}
	}
	max = -1;
	int result;
	for (int i = 0; i<10; i++){
		if (array[i] > max){
			max = array[i];
			result = i;
		}
	}
	printf("Group: ");
	printf("%d\n", result);
	return 0;
}	 
