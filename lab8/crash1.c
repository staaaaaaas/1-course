#include <stdio.h>
#include "function.h"

int max(int a, int b) {
 if(a>=b){
  return(a);
 }
 else{
  return(b);
 }
}
int const M=10;
int main() {
 int a,b,m;
 scanf("%d",&a);
 scanf("%d",&b);
 m=max(a,b)%M;
 printf("%d", m);
 printf("\n");
}


