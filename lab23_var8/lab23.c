#include<stdio.h>
#include<stdlib.h>


typedef struct tnode{
	double val;
	struct tnode* l;
	struct tnode* r;
}tnode;


void tree_add (tnode ** t, double v){
        if((*t)==NULL){
                (*t)=(tnode*)malloc(sizeof(tnode));
                (*t)->l=NULL;
                (*t)->r=NULL;
                (*t)->val=v;
        }
	else if(v<(*t)->val){
               tree_add(&((*t)->l),v);
        }
	else if(v>(*t)->val){
                tree_add(&((*t)->r),v);
        }
	else if(v==(*t)->val){
		printf("INVALID ENTER\n");
	}
}


void showLine(char* c, int p, int s) {
    	int t=s; 
	for(int i=0; i<p; i++){
		printf(t&1 ? "|  " : "   "); 
		t/=2;
	} 
	printf("%s",c);
}
void showTree(tnode* wood, int p, int s) { // string s = string("")) {
   	if (wood == NULL) return;
	printf("%lf", wood->val); printf("\n");  
 	if (wood->l != NULL) {
       		showLine("|\n", p, s); showLine("L: ", p, s);
        	showTree(wood->l, p+1, s + ((wood->r == NULL ? 0 : 1)<<p)); 
    	}
    	if (wood->r != NULL) {        
        	showLine("|\n", p, s); showLine("R: ", p, s);
        	showTree(wood->r, p+1, s);
    	}
}


int count_nodes(tnode *t){
	if (t==NULL){
		return 0;
	}
	return (1 + count_nodes(t->l) + count_nodes(t->r));
}


tnode** find(tnode ** t, double v){
	if ((*t)==NULL) return NULL;
	if ((*t)->val < v) return find(&((*t)->r),v);
	if ((*t)->val > v) return find(&((*t)->l),v);
	return t;
}


void delete(tnode** t){
	if((*t)->r==NULL){
		tnode *tmp = (*t)->l;
        	free(*t);
       		(*t) = tmp;
	} 
	else if ((*t)->l == NULL) {
        	tnode *tmp = (*t)->r;
        	free(*t);
        	(*t) = tmp;
	}
	else{
		tnode** tmp = &(*t)->l;
       		while ((*tmp)->r != NULL){
        		tmp = &(*tmp)->r;
        	}    
        	(*t)->val = (*tmp)->val;
                delete(tmp);
	}
}


void delete_tree (tnode *t){
		if(t->l) delete_tree(t->l);
		if(t->r) delete_tree(t->r);
		delete(&t);
}

int main(){
	tnode *root = NULL;
	tnode** fordelete;
	int st;
	printf(" 1-exit\n 2-add_node\n 3-delete_node\n 4-print_tree\n 5-count_of_nodes\n 6-delete_tree\n");
	do{
		double val;
		printf("ENTER YOUR CHOISE\n");
		scanf("%d", &st);
		if (st>0 && st<7){
			switch (st){
				case 1:
					printf("THE PROGRAM HAS BEEN ENDED\n");
					break;
				case 2:
					printf("ENTER THE NODE\n");
					scanf("%lf", &val);
					tree_add(&root, val);
					break;
				case 3:
					if(!root){
						printf("ALL NODES HAVE BEEN DELETED OR NO BINARY TREE CREATED\n");
					}
					else{
						printf("ENTER NODE\n");
						scanf("%lf", &val);
						delete(find(&root, val));			
						if (!root){
							printf("YOU'VE DELETED THE BINARY TREE\n");
						}
					}
					break;
				case 4:
					if (!root){
						printf("NO BINARY TREE\n");
					}
					else{
						printf("BINARY TREE:\n");
						showTree(root,0,0);
					}
					break;
				case 5:
					printf("COUNT OF NODES:\n");
					printf("%d\n", count_nodes(root));
					break;
				case 6:
					if (!root){
						printf("NO BINARY TREE\n");
					}
					else{
						delete_tree(root);
						printf("DELETED\n");
					}
					break;
			}
		}
		else{
			printf("WRONG INPUT, START AGAIN\n");
			break;
		}
			
	}while (st!=1);
}
		
					
					
				
				
	
	

	





























