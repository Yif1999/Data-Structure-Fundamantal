#include<stdio.h>
#include<stdlib.h>
#define MaxN 50

int Po[MaxN],In[MaxN],print[31][31];
typedef struct TreeNode *Tree;
struct TreeNode {
	int data;
	Tree left;
	Tree right;
}; 
typedef struct QNode *Queue; 
struct QNode{
	Tree Data[MaxN];
	int rear;
	int front;
};

Tree BuildTree (int head_In,int head_Po,int tail_In,int tail_Po);
void ZPrint(Tree t);
void AddQ(Queue PtrQ,Tree item);
Tree DeleteQ(Queue PtrQ);
int Level(Tree t,Tree temp);
int getNodelayer(Tree temp,int level,int key);
int IsEmptyQ(Queue q);

int main(){
	int N;
	scanf("%d",&N);
	int i,j;
	for (i=0;i<N;i++){
		scanf("%d",&In[i]);
	}
	for (i=0;i<N;i++){
		scanf("%d",&Po[i]);
	}
	int head_In=0,head_Po=0,tail_In=N-1,tail_Po=N-1;
	
	Tree T=BuildTree(head_In,head_Po,tail_In,tail_Po);
	
	ZPrint(T);
	system("pause");
	return 0;
}

Tree BuildTree (int head_In,int head_Po,int tail_In,int tail_Po){
	Tree t=NULL;
	int flag=0,i;
	if (head_In<=tail_In && head_Po<=tail_Po){
		t=(Tree)malloc(sizeof(struct TreeNode));
		t->data=Po[tail_Po];
		t->left=NULL;t->right=NULL;
		for ( i=head_In;i<=tail_In;i++){
			if (In[i]==Po[tail_Po]){
				flag=1;
				break;
			}
		}
		if (!flag) return NULL;
		t->left=BuildTree(head_In,head_Po,i-1,head_Po+i-head_In-1);
		t->right=BuildTree(i+1,head_Po+i-head_In,tail_In,tail_Po-1);
	}
	return t;
}

void ZPrint(Tree t){
	Queue Q=(Queue)malloc(sizeof(struct QNode));
	Tree temp;
	Q->front=-1;
	Q->rear=-1;
	int i,j=0,m=0,n;
	if (!t) return;
	AddQ(Q,t);
	while (!IsEmptyQ(Q)){
		temp=DeleteQ(Q);
		if (m!=Level(t,temp)){
			j=0;
			m=Level(t,temp);
		}	
		print[m][j++]=temp->data;
		if (temp->left) AddQ(Q,temp->left);
		if (temp->right) AddQ(Q,temp->right);
	}
	printf("%d",print[0][0]);
	for (i=1;i<m+1;i++){
		if (i%2==1){
			for (j=0;print[i][j]!=0;j++){
				printf(" %d",print[i][j]);
			}
		}
		else{
			for (j=0;print[i][j]!=0;j++);
			n=j-1;
			for (j=n;j>=0;j--){
				printf(" %d",print[i][j]);
			}
		}
	}
	return;
}

int Level(Tree t,Tree temp){
	int level = 0;
    return getNodelayer(t,level,temp->data);
}

int getNodelayer(Tree temp,int level,int key){
	int layer;
	if (temp){
		if(temp->data==key)
			return level;
		layer=getNodelayer(temp->left,level+1,key);
		if(layer!=-1)	return layer;
		else	return getNodelayer(temp->right,level+1,key);
	}
	else	return -1;
}

void AddQ(Queue PtrQ,Tree item){
	PtrQ->rear=PtrQ->rear+1;
	PtrQ->Data[PtrQ->rear]=item;
}

Tree DeleteQ(Queue PtrQ){
	PtrQ->front=PtrQ->front+1;
	return PtrQ->Data[PtrQ->front];
}

int IsEmptyQ(Queue q){
	return q->front == q->rear;
}
