#include<stdio.h>
#include<stdlib.h>

typedef  struct treenode *tree;
struct treenode{
	int v;
	tree left,right;
	int flag;
};

tree maketree(int n);
tree insert(tree t,int V);
tree newnode(int V);
int check(tree t,int V);
int judge(tree t,int n);
void resetT(tree t);
void freetree(tree t);

int main(){
	int n,l,i;
	tree t;
	
	scanf("%d",&n);
	while(n){
		scanf("%d",&l);
		t=maketree(n);
		for (i=0;i<l;i++){
			if (judge(t,n)) printf("Yes\n");
			else printf("No\n");
			resetT(t);
		}
		freetree(t);
		scanf("%d",&n);
	}
	return 0;
}

tree maketree(int n){
	tree t;
	int i,V;
	scanf("%d",&V);
	t=newnode(V);
	for (i=1;i<n;i++){
		scanf("%d",&V);
		t=insert(t,V);
	}
	return t;
}

tree insert(tree t,int V){
	if (!t) t=newnode(V);
	else{
		if (V>t->v)
			t->right=insert(t->right,V);
		else
			t->left=insert(t->left,V);
	}
	return t;
}

tree newnode(int V){
	tree t=(tree)malloc(sizeof(struct treenode));
	t->v=V;
	t->left=t->right=NULL;
	t->flag=0;
	return t;
}

int check(tree t,int V){
	if (t->flag){
		if (V<t->v) return check(t->left,V);
		else if (V>t->v) return check(t->right,V);
		else return 0;
	}
	else{
		if (V==t->v){
			t->flag=1;
			return 1; 
		}
	else return 0;
	}
}

int judge(tree t,int n){
	int i,V,flag=0;
	scanf("%d",&V);
	if (V!=t->v) flag=1;
	else t->flag=1;
	for (i=1;i<n;i++){
		scanf("%d",&V);
		if ((!flag)&&(!check(t,V))) flag=1;
	}
	if (flag) return 0;
	else return 1;
}

void resetT(tree t){
	if (t->left) resetT(t->left);
	if (t->right) resetT(t->right);
	t->flag =0;
}

void freetree(tree t){
	if (t->left) freetree(t->left);
	if (t->right) freetree(t->right);
	free(t);
}
