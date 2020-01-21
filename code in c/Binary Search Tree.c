#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode{
	int data;
	Tree left;
	Tree right;
};
 
Tree InsertTree(int t,Tree T){
 	if (!T){
 		T=(Tree)malloc(sizeof(struct TreeNode));
 		T->left=NULL;
		T->right=NULL;
 		T->data=t;
	}
	else{
		if (t>T->data)
 			T->right=InsertTree(t,T->right);
 		else
 			T->left=InsertTree(t,T->left);
	}
	return T;
 
}

void FreeTree(Tree T){
	if (T->left)
		FreeTree(T->left);
	if (T->right)
		FreeTree(T->right);
	free(T);
}

int Check(Tree T,Tree CT){
	if (T==NULL && CT==NULL) 
		return 1;
	if ((T==NULL && CT!=NULL)||(T!=NULL && CT==NULL)) 
		return 0;
	if (T->data!=CT->data) 
		return 0;
	else 
		return (Check(T->left,CT->left) && Check(T->right,CT->right));
}
 
int main(){
	int N,L;
	int i,j,t;
	Tree T,CT;
	while(1){
		scanf("%d",&N);
		if (N==0) return 0;
		else{
			T=NULL;
			scanf("%d",&L);
			for (i=0;i<N;i++){
				scanf("%d",&t);
				T=InsertTree(t,T);
			}
			for (j=0;j<L;j++){
				CT=NULL;
				for (i=0;i<N;i++){
					scanf("%d",&t);
					CT=InsertTree(t,CT);
				}
				if (Check(T,CT)) printf("Yes\n");
				else printf("No\n");
				FreeTree(CT);
			}	
		}
		FreeTree(T);
	}
}
