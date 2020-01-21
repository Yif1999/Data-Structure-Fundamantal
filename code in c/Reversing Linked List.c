#include<stdlib.h>
#include<stdio.h> 
#define MAXSIZE 100000

//�����ṹ���� 
typedef struct PolyNode{
	int data;
	int next;
} Node;

//�������� 
int rev_list(Node list[],int k,int head,int count);
void print_list(Node list[],int head);

//��ת����
int rev_list(Node list[],int k,int head,int count){
	int rear_head;
	int rev_head=head;
	int next=head;	//���ڻ������ַ 
	int pNext;
	int flag=1;
	int i;
	while (count-k>=0){
		count=count-k;
		
		//ð�ݷ�ת 
		for(i=0;i<k-1;i++){
			pNext=list[rev_head].next;
			list[rev_head].next=list[pNext].next;
			list[pNext].next=next;
			next=pNext;			
		}
		

		if (flag){
			head=next;
			flag=0;
		}
		else{
			list[rear_head].next=next;
		}
		rear_head=rev_head;
		rev_head=list[rev_head].next;
		next=rev_head;
		//��ַ���� 
	}
	return head;
}

//��ӡ����
void print_list(Node list[],int head){
	int temp=head;
	while(list[temp].next!=-1){
		printf("%05d %d %05d\n",temp,list[temp].data,list[temp].next);
		temp=list[temp].next;
	}
	printf("%05d %d %d\n",temp,list[temp].data,list[temp].next);
}

//��ת������
int main(){
	//�����ʼ��ֵ 
	int Head,N,k;
	scanf("%d %d %d",&Head,&N,&k);
	Node list[MAXSIZE];
	int i,add_front,add_next,number;
	
	//���������ʽ�����ṹ���� 
	for (i=1;i<=N;i++){
		scanf("%d %d %d",&add_front,&number,&add_next);
		list[add_front].data=number;
		list[add_front].next=add_next;
	}
	
	//���������� 
	int temp=Head;
	int count=1;
	while (list[temp].next!=-1){
		count++;
		temp=list[temp].next;
	}
	
	//���ú���ִ�з�ת���ӡ������� 
	if (k>1)
		Head=rev_list(list,k,Head,count);
	print_list(list,Head); 
	
	return 0;
} 
