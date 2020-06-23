#include <stdio.h>

int abs(int a){
 if (a<0){
  return(-a);
 }
 else{
  return a;
 }
}

int mod (int a,int b){
  if ((a<0)&&(a%b!=0)){
  return abs(b)+a%abs(b);
  }
 else{
  return a%b;
 }
}



int max(int a, int b, int c){
 if ((a>b)&&(a>c)){
  return(a);
 }
  else if ((b>a)&&(b>c)){
   return(b);
  }
   else return (c);

}
int min(int a,int b,int c){
 if ((a<b)&&(a<c)){
  return(a);
 }
  else if ((b<a)&&(b<c)){
   return(b);
  }
   else return (c);
}
 
int const i=6,j=27,l=-15, r=10, ic1=-10, ic2=-20,jc1=-10,jc2=-20;


int main(){
 int in, jn, ln, rn, ic1n, ic2n, jc1n, jc2n, inn,jnn;
 in=i; jn=j; ln=l; rn=r; ic1n=ic1; ic2n=ic2; jc1n=jc1; jc2n=jc2;
 int k;
 for (k=0; k<51; ++k){ 
  if ((((in-ic1n)*(in-ic1n)+(jn-jc1n)*(jn-jc1n))<=r*r)
  &&(((in-ic2n)*(in-ic2n)+(jn-jc2n)*(jn-jc2n))<=r*r)){
   printf("DETECTED\n");
   printf("%d",k);
   printf("\n");
   printf("%d",in);
   printf("\n");
   printf("%d",jn);
   printf("\n");
   printf("%d",ln);
   printf("\n");
   break;
  }
  inn=in;
  jnn=jn;
  in=mod((inn*inn*inn-jnn*jnn*jnn+ln*ln*ln-k),20);
  jn=mod((min(inn*jnn*jnn-k,inn*inn*ln-k,jnn*ln*ln-k)),30);
  ln=mod((max(inn*jnn*jnn-k,inn*inn*ln-k,jnn*ln*ln-k)),30);
 }
 if (k==51){
  printf("NOT DETECTED\n");
 }
}
