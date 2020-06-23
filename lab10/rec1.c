#include <stdio.h>

int f2 ( int a);

int f1 (int a){
 a--;
 if (a>0){
  return f2(a) ;
 }
 printf("%d",a);
}

int f2 (int a){
 a= a/2;
 if (a>2){
  return f1(a);
 }
 printf("%d",a);
}

iut main(){
 int a=15;
 int b;
 b=f1(a);
 printf("%d",b);
 printf("\n");
}
