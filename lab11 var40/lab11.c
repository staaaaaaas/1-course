#include <stdio.h>
#include <ctype.h>

void dv(int * a){
     int  k=1;
     int d=1;
     int a1,k1;
     a1=*a;
     while ((a1 / 10)!=0){
	++k;
        a1=a1/10;
     }
     k1=k;
     for (int i=k; i>=1;--i){
      for(int j=0; j<k1-1;j++){
       d=d*10;
      }
      if ((*a/d)==0) printf("0 ");
      if ((*a/d)==1) printf("1 ");
      if ((*a/d)==2) printf("10 ");
      if ((*a/d)==3) printf("11 ");
      if ((*a/d)==4) printf("100 ");
      if ((*a/d)==5) printf("101 ");
      if ((*a/d)==6) printf("110 ");
      if ((*a/d)==7) printf("111 ");
      *a=*a%d;
      d=1;
      k1--;
    }
} 
int main(){
    int c,f;
    int st=0;
    int dgt=0;
    
    while ((c = getchar()) != EOF){	 
        switch(st){
            case 0:
		if (isspace(c)||ispunct(c)){
		    st=0;
 		}
		else{
                    if(c>='0'&&c<='7'){ 
                    dgt=dgt*10+(c-'0');
		    st=1;
                    }
                    else{ 
                     st=2;
                    }
		}
	    break;
            case 1:
                if (c>='0' && c<='7'){
                    dgt=dgt*10+(c-'0');
                    st=1;
		}
		else{
                    if( isspace(c)|| ispunct(c)){ 
		 	dv(&dgt);
                        printf("%c\n",dgt);
                        dgt=0;
                        st=0;                   
                    }  
                    else{
                        st=2;
  	       	    }
		}
                 
            break;
            case 2:
                if (isspace(c)||ispunct(c)){
                    dgt=0;
                    st=0;
		}
                else
                    st=2;
            break;
	}
    }
}


            
