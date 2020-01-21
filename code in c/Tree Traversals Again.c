#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxsize 100
#define Error -1
typedef enum{push,pop} Operation;
typedef int ElementType;
int first=1; //控制输出格式 

struct TreeNode{
	ElementType Left;
	ElementType Right;
}Tree[Maxsize];

typedef struct PtrToNode *Stack;
struct PtrToNode{
	ElementType Data[Maxsize];
	int top;
};

Operation GetOp(){
	char Push[]="Push";
	char Pop[]="Pop";
	char s[100];
	scanf("%s",s);
	
	if (strcmp(Push,s)==0) return push;
	if (strcmp(Pop,s)==0) return pop;
}

int Push (Stack s,ElementType x){
	if (s->top==Maxsize-1)
		return Error;
	else
		s->top++;
		s->Data[s->top]=x;
		return 1;
}

ElementType Pop(Stack s){
	if (s->top==-1)
		return Error;
	else
		s->top--;
		return(s->Data[s->top+1]);
}

void PostorderTraversal(int t){

	if (t!=Error){
		PostorderTraversal(Tree[t].Left);
		PostorderTraversal(Tree[t].Right);
		if (first==1){
            printf("%d",t);
            first=0;
        }
		
		else
			printf(" %d",t);
	}
}

int main(){
	int N,x;
	scanf("%d",&N);
	int root=-1,node;
	int i,flag=1;	//flag变量左右儿子标志，1为左儿子，2为右儿子 

	Stack s=(Stack)malloc(sizeof(struct PtrToNode));
	s->top=-1;
	for (i=0;i<Maxsize;i++){
		Tree[i].Left=-1;
		Tree[i].Right=-1;
	}
	i=0;
	while(i<2*N){
		switch(GetOp()){
		case push:
			scanf("%d",&x);
			if(root==-1)
				root=x;
			else{
				if(flag==1)
					Tree[node].Left=x;
				else
					Tree[node].Right=x;
			}
			node=x;
			flag=1;
			Push(s,x);
			break;
		case pop:
			node=Pop(s);
			flag=2;
			break;
		}
		i++;
	}
	PostorderTraversal(root);
	
	return 0;
}
