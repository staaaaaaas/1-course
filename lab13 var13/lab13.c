#include <stdio.h>
#include <ctype.h>



int main(){
unsigned int set1= (1u<<'a'-'a'|1u<<'e'-'a'|1u<<'i'-'a'|1u<<'o'-'a'|1u<<'u'-'a'|1u<<'y'-'a');
unsigned int set2=(1u<<'A'-'A'|1u<<'E'-'A'|1u<<'I'-'A'|1u<<'O'-'A'|1u<<'U'-'A'|1u<<'Y'-'A');
unsigned int z,k,z1,k1,check1,check2;
int c;
int st=0;
 while (c=getchar()){
  if (c==EOF){
   if (set1==0 || set2==0){
     printf("NO\n");
    }
    else{
     printf("YES\n");
    }
    break;
  }
  switch(st){
   case 0:
    if (isalpha(c) || isspace(c)||ispunct(c)){
     if (isspace(c)||ispunct(c)){
      k1=0;
      k=0;
     }
     else{
      z=1u<<(c-'a');
      check1=set1 & z;
      check2=set2 &z;
      if (check1!=0){
        k=k|z;
        set1=set1 & ~z;
        z1=1u<<((c-32)-'a');
        k1=k1|z1;
        set2= set2 & ~z1;
      } 
      if (check2!=0){
         k1=k1|z;
         z1=1u<<((c+32)-'a');
         k=k|z1;
         set1=set1& ~z1;
         set2=set2 & ~z;
      }
      check1=0;z=0;
      check2=0;z1=0;
      st=0;
     }
    }
    else
     st=1;
    break;
    case 1:
      if (isspace(c)||ispunct(c)){
       set1=set1|k;
       set2=set2|k1;
       k=0;k1=0;
       st=0;
      }
      else{
       st=1;
      }
    break;
  }
 }
}


















