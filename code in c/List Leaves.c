#include<stdio.h>
struct node{   //���������洢������ 
	int data;
	int left;
	int right;
}tr[10];
 
int main()
{
	int N,i,M=0;
	int check[10]={0};
	scanf("%d",&N);
	getchar();                         //���뻻�з� 
	for(i=0;i<N;i++){
		char l,r;
	    scanf("%c %c",&l,&r);        //�������Һ��� 
	    getchar();
	    if(l=='-'&&r=='-')
			M++;        //Ҷ�ӽڵ���� 
	    tr[i].data=i;                  //�ڵ����� 
	    tr[i].left=l=='-'?-1:l-'0';    
	    tr[i].right=r=='-'?-1:r-'0'; 
	    if(l!='-')
			check[l-'0']=1;     //���Ҹ��ڵ� 
	    if(r!='-')
			check[r-'0']=1;
	}
	int queue[10]={0},rear=-1,front=-1;   //���ö��У��������� 
	struct node p;
	for(i=0;i<N;i++){         //���ڵ� 
	    if(check[i]==0)
			queue[++rear]=i;    //��β������ڵ� 
	}
	while(front!=rear){                       //���в�Ϊ�� 
		p=tr[queue[++front]];                 //��ͷȡ���ڵ� 
		if(p.left!=-1)
			queue[++rear]=p.left;   //��β��������
		if(p.right!=-1)
			queue[++rear]=p.right; //��β�����Һ��� 
		if(p.left==-1&&p.right==-1){          //���Ҷ�ӽڵ� 
		    printf("%d",p.data);
		    M--;
		    if(M)printf(" ");
		}
	}
	return 0;
}
