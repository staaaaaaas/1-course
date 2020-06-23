#include <stdio.h>

int main(){
 int n;
 scanf("%d",&n);
 int a[n] [n];
 for(int i=0; i<n; i++){
  for(int j=0; j<n; j++){
   scanf("%d", &a[i] [j]);
  }
 }
 int max,k;
 int s=0;
 max= a[0] [0];
 k=0;
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   if (a[i][j]>max){
    max=a[i][j];
    k=i;
   }
  }
 }
 for(int j=0;j<n;j++){
  s=s+a[k] [j] ;
 }
 printf("%d\n",s);
}
