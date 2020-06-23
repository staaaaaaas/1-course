#include <stdio.h>
#include <math.h>

int count;

double eps(){
        double a=1;
        while (1+a/2>1){
                a=a/2;
        }
        return(a);
}

double F1 (double x){
        return(acos(x)-sqrt(1-0.3*pow(x,3)));
}

double f1 (double x){
        return(cos(sqrt(1-0.3*pow(x,3))));
}

double F2 (double x){
        return(3*x-4*log(x)-5);
}

double f2 (double x){
        return((4*log(x)+5)/3);
}

double der1 (double(*F)(double),double x){
        double dx=pow(2,-26);
        return(((*F)(x+dx)-(*F)(x-dx))/(2*dx));
}

double der2 (double(*F)(double),double x){
       double dx=pow(2,-13);
	return(((*F)(x+dx)-2*(*F)(x)+(*F)(x-dx))/(pow(dx,2)));
}
	
double dih (double(*F)(double),double a, double b){
        double x,e=eps();
        int f,k=0;
	if ((*F)(a)*(*F)(b)<0){
		f=0;
        	while (fabs(a-b)>e){
                	x=(a+b)/2.0;
                	if ((*F)(a)*(*F)(x)<0){
                        	b=x;
                	}
                	else{
                        	a=x;
			}
                	k++;
        	}
	}
	else{
		f=1;
	}
	if (f==0){
		count=k;
        	return(x);
	}
	else{
		return(a-1);
	}
}

double itter (double(*F)(double),double a, double b){
        double x,x2,e=eps();
        int f,k=0;
        x=(a+b)/2.0;
        x2=a;
        while (fabs(x-x2)>e){
		if (fabs(der1((*F),x))<1){
			f=0;
                	x2=x;
                	x=(*F)(x);
               		k++;
		}
		else{
			f=1;
			break;
		}
        }
	if (f==0){
		count=k;
       		return(x);
	}
	else{
		return(a-1);
	}
}

double newton (double(*F)(double),double a,double b){
        double x,x2,e=eps(),dr1,dr2;
        int f,k=0;
        x=(a+b)/2.0;
        x2=a;
        while (fabs(x-x2)>e){
		dr1=der1((*F),x);
		dr2=der2((*F),x);
		if (fabs((*F)(x)*dr2)<pow(dr1,2)){
			f=0;
                	x2=x;
               		x=x-(*F)(x)/dr1;
                	k++;
		}
		else{
			f=1;
			break;
		}
        }
	if (f==0){
		count=k;
		return(x);
	}
	else{
		return(a-1);
	}
}

int main(){
	double a1,b1,a2,b2;
	printf("Mashinnoe eps = ");
	printf("%e\n",eps());
	printf("vvedite otrezok var22\n");
	scanf("%lf%lf",&a1,&b1);
	printf("vvedite otrezok var23\n");
	scanf("%lf%lf",&a2,&b2);
	printf("                        Tablica znacheniy                         \n");
	printf("|var|  metod dihotomii   |  metod itteraciy   |   metod newtona    |\n");
	printf("|___|    koren'    |itter|shojd| koren' |itter|shojd| koren' |itter|\n");
	printf("|22 |");
	if (dih(F1,a1,b1)==a1-1){
                printf("     no       |  -  |");
        }
        else{
                printf("   %lf   |",dih(F1,a1,b1));
                printf(" %d  |",count);
        }
	if (itter(f1,a1,b1)==a1-1){
		printf(" no  |   -    |  -  |");
	}
	else{
		printf(" yes |");
		printf("%lf|",itter(f1,a1,b1));
		printf(" %d  |",count);
	}
	if (newton(F1,a1,b1)==a1-1){
                printf(" no  |   -    |  -  |\n");
        }
        else{
                printf(" yes |");
                printf("%lf|",newton(F1,a1,b1));
                printf("  %d  |\n",count);
        }
	printf("|23 |");
        if (dih(F2,a1,b1)==a2-1){
                 printf("     no       |  -  |");
        }
        else{
                printf("   %lf   |",dih(F2,a2,b2));
                printf(" %d  |",count);
        }
        if (itter(f2,a2,b2)==a2-1){
                printf(" no  |   -    |  -  |");
        }
        else{
                printf(" yes |");
                printf("%lf|",itter(f2,a2,b2));
                printf(" %d  |",count);
        }
        if (newton(F2,a2,b2)==a2-1){
                printf(" no  |   -    |  -  |\n");
        }
        else{
                printf(" yes |");
                printf("%lf|",newton(F2,a2,b2));
                printf("  %d  |\n",count);
        }
}

