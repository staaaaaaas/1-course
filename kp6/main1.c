#include<stdio.h>
#include<string.h>
#include"students.h"


int main(int argc, char *argv[]){
	FILE *fIn,*fOut;///
	if (argc==1){
		if ((fIn=fopen("input.txt","r"))==NULL){
			printf("Cannot input 1");
			return 1;
		}
		if ((fOut=fopen("Base.dat","wb"))==NULL){
			printf("Cannot output");
			return 1;
		}
	}
	else
		if (argc==2){
			puts(argv[1]);
			if ((fIn=fopen(argv[1],"r"))==NULL){
				printf("Cannot input 2");
				return 1;
			}
			if ((fOut=fopen("Base.dat","wb"))==NULL){
				printf("Cannot output");
				return 1;
			}

		}
		else{
			puts(argv[1]);
			puts(argv[2]);
			puts(argv[3]);
			if ((fIn=fopen(argv[1],"r"))==NULL){
				printf("Cannot input 3");
				return 1;
			}
			if ((fOut=fopen(argv[2],"wb"))==NULL){
				printf("Cannot output");
				return 1;

			}		

		}
	int l=sizeof(student);
	int n=-1;
	while (!feof(fIn)){
		fscanf(fIn,"%s %s %c %d %d %d %lf %lf %lf",
		student.fam,
		student.name,
		&student.gender,
		&student.group,
		&student.markzach1,
		&student.markzach2,
		&student.mark_informatics,
		&student.mark_mathan,
		&student.mark_descrmat);
		fwrite(&student,sizeof(student),1,fOut);
		n++;
	}
	fclose(fIn);
	fclose(fOut);
	printf("Number of students=%d\n",n);
	if(argc<3){
		if ((fIn=fopen("Base.dat","rb"))==NULL){
			printf("Cannot input");
			return 1;
		}
		if ((fOut=fopen("output.txt","w"))==NULL){
			printf("Cannot output");
			return 1;
		}
	}
	else if(argc==3){
		if ((fIn=fopen(argv[2],"rb"))==NULL){
			printf("Cannot input");
			return 1;
		}
		if ((fOut=fopen("output.txt","w"))==NULL){
			printf("Cannot output");
			return 1;
		}
	} 
	else{
		if ((fIn=fopen(argv[2],"rb"))==NULL){
			printf("Cannot input");
			return 1;
		}
		if ((fOut=fopen(argv[3],"w"))==NULL){
			printf("Cannot output");
			return 1;
		}
	}
	printf("============================================================================\n");
	printf("| F Name | Name | Pol | Number |Zach1|Zach2|Ekz1|Ekz2|Ekz3|\n");
	printf("============================================================================\n");
	fprintf(fOut,"All in Base:\n");
	fprintf(fOut,"============================================================================\n");
	fprintf(fOut,"| Familija | Iniciali | Pol | Number |Zach1|Zach2|Ekz1|Ekz2|Ekz3|\\n");
	fprintf(fOut,"============================================================================\n");
	while(!feof(fIn)){
		student1=student;
		fread(&student,l,1,fIn);
		if (strcmp(student.fam,student1.fam)){
			fprintf(fOut,"| %-11s | %-10s | %-2c | %-5d | %-3d | %-3d | %-2lf | %-2lf | %-2lf |\n",
			student.fam,
			student.name,
			student.gender,
			student.group,
			student.markzach1,
			student.markzach2,
			student.mark_informatics,
			student.mark_mathan,
			student.mark_descrmat);
			printf("| %-11s | %-10s | %-2c | %-5d | %-3d | %-3d | %-3lf | %-3lf | %-3lf |\n",
			student.fam,
			student.name,
			student.gender,
			student.group,
			student.markzach1,
			student.markzach2,
			student.mark_informatics,
			student.mark_mathan,
			student.mark_descrmat);

		}
	}
	fprintf(fOut,"============================================================================\n");
	printf("============================================================================\n");
	return 0;
} 
