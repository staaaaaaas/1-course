#include <stdio.h>
 
int main(){
 int n;
 scanf("%d",&n);
 int mas[n] [n];
 for(int i=0; i<n; ++i){
  for(int j=0; j<n; ++j){
   scanf("%d", &mas[i] [j]);
  }
 }
 int t=0;
 int l=0;
 int b=n-1;
 int r=n-1;
 while ((t!=b)&&((l-1)!=r)){
  for(int i=t; i<=b; ++i){
   printf("%d ",mas[i] [l]);
  }
  ++l;
  for(int i=l; i<=r; ++i){
   printf("%d ", mas[b] [i]);
  }
  --b;
  for(int i=b; i>=t; --i){
   printf("%d ", mas[i] [r]);
  }
  --r;
  for(int i=r; i>=l; --i){
   printf("%d ",mas[t] [i]);
  }
  ++t;
 }
 if (n%2==1){
  printf("%d ", mas[n/2] [n/2]);
 }
}

