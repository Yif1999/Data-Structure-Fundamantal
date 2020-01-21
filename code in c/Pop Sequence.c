#include<stdio.h>
#include<stdlib.h>

int M,N,K;
typedef struct Node *stack;
typedef struct Node{
	int *data;
	int top;
	int maxsize;
};

int push(stack s,int p);
int pop(stack s);
int stackcheck(int *t,stack s);

int main(){
	int i,j,*t;
	stack s=(stack)malloc(sizeof(struct Node));
	scanf("%d %d %d",&M,&N,&K);
	t=(int *)malloc(N*sizeof(int));
	s->data=(int*)malloc(M*sizeof(int));
	s->top=-1;
	s->maxsize=M;
	for (i=0;i<K;i++){
		for (j=0;j<N;j++){
			scanf("%d",&t[j]);
		}
		if (stackcheck(t,s))
			printf("YES\n");
		else
			printf("NO\n");
	}
	free(t);
	return 0;
}

int push(stack s,int p){
	if (s->top == s->maxsize)
		return 0;
	s->data[++(s->top)]=p;
	return 1;
}

int pop(stack s){
	if (s->top==-1)
		return 0;
	s->top--; 
	return 1;
}

int stackcheck(int *t,stack s){
	int index=0,num=1;
	s->top=-1;
	while (index!=N){
		while (s->top!=-1 && s->data[s->top]<t[index] && s->top+1<M||s->top==-1 && index!=N){
			push(s,num); 
			num++;
		}
		if (s->top!=-1 && s->data[s->top]==t[index]){
			pop(s);
			index++;
		}
		if (s->top!=-1 && s->data[s->top]>t[index]||s->top+1==M && s->data[s->top]!=t[index]){
			return 0;
		}
	}
	return 1;
}
