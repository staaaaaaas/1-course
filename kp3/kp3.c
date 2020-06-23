#include <stdio.h>
#include <math.h>
#define abs(x) ( (x) >= 0 ? (x) : (-x) )
	
double epsilon(){
	double a=1;
	while (1+a/2>1){
		a=a/2;
	}
	return(a);
}


double factorial(double n){
	 if (n == 0)
		return 1;
   	 else
        	return factorial(n - 1) * n;
}

		 
int main(){
	double ex=2.71828182845904523536;
	double e,k;
	k=100000;
	e=epsilon();
  	printf("k=%lf\n", k);
	printf("Mashinnoe epsilon = %e\n", e);
	e=e*k;
	double a=0.0, b=1.0;
	int n,i=0;
	printf("Vvedite n\n");
        scanf("%d",&n);
        printf(" Tablica znachenii\n");
        printf("|  x  |  Summa ryada  |znachenie f(x) |    raznica    |   iteracii    |\n");
	double x;
	x=a;
	while (i<=n){
		double function;
                function= (1+x)*(pow(ex,-1.0*x));
		double s=1.0;
        	int it=1;
		double tay =100.0;
		while (!((s<=(function+e) && s>(function-e)))){
        		if (it%2==0)
                        	tay=-1*( (it-1) * (pow(x,it)) ) / (factorial(it));
        		else
                        	tay=( (it-1) * (pow(x,it)) ) / (factorial(it));
			s=s+tay;
			it++;
	        }
		double r;
		r=function-s;
        	printf("|%5.2lf|%15.13lf|%15.13lf|%15.13lf|%15d|\n", x, s, function, abs(r), it);
		x+=(b-a)/n;
		i++;
	}
}
