#include <stdio.h>

int max(int a, int b) {
 if(a>=b){
  return(a);
 }
 else{
  return(b);
 }
}
int f(int a){
 if (a>5){
  return g(a);
 }
 else{
  return 0;
 }
}
int g(int a){
 if (a<10){
  return 1;
 }
 else{
  return (a);
} 
int const M=10;
int main() {
 int a,b,m;
 scanf("%d",&a);
 scanf("%d",&b);
 m=max(a,b)%M;
 printf("%d", m)
 printf("\n");
}

