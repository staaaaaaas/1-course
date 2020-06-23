#include <stdio.h>

int abs(int a){
 if (a<0){
  return(-a);
 }
 else{
  return a;
 }
}


int task (int a){
 int p1, p2, p3, max1, max2, res1, res2, res3;
 max1=-1;
 while( a/100 != 0){
     max2=abs((a%10))+abs(((a/10)%10))+abs(((a/100)%10));
    if (max2>=max1){
	    max1=max2;
	    res1=abs(a%10);
            res2=abs((a/10)%10);
            res3=abs((a/100)%10);
    }
    a=a/10;
 }
 printf("%d",res3);
 printf("%d",res2);
 return res1;
 printf("\n");
}

int main() {
 int a;
 while (1==scanf("%d",&a)){
   if (a/100==0){
    printf("error\n");
   }
   else{
   printf("%d",task(a));
   printf("\n");
   }
 }
} 





