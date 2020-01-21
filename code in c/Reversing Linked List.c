#include<stdlib.h>
#include<stdio.h> 
#define MAXSIZE 100000

//建立结构数组 
typedef struct PolyNode{
	int data;
	int next;
} Node;

//函数声明 
int rev_list(Node list[],int k,int head,int count);
void print_list(Node list[],int head);

//反转函数
int rev_list(Node list[],int k,int head,int count){
	int rear_head;
	int rev_head=head;
	int next=head;	//用于缓存结点地址 
	int pNext;
	int flag=1;
	int i;
	while (count-k>=0){
		count=count-k;
		
		//冒泡反转 
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
		//地址交接 
	}
	return head;
}

//打印函数
void print_list(Node list[],int head){
	int temp=head;
	while(list[temp].next!=-1){
		printf("%05d %d %05d\n",temp,list[temp].data,list[temp].next);
		temp=list[temp].next;
	}
	printf("%05d %d %d\n",temp,list[temp].data,list[temp].next);
}

//反转主程序
int main(){
	//读入初始化值 
	int Head,N,k;
	scanf("%d %d %d",&Head,&N,&k);
	Node list[MAXSIZE];
	int i,add_front,add_next,number;
	
	//读入输入格式并填充结构数组 
	for (i=1;i<=N;i++){
		scanf("%d %d %d",&add_front,&number,&add_next);
		list[add_front].data=number;
		list[add_front].next=add_next;
	}
	
	//计数结点个数 
	int temp=Head;
	int count=1;
	while (list[temp].next!=-1){
		count++;
		temp=list[temp].next;
	}
	
	//调用函数执行反转与打印输出操作 
	if (k>1)
		Head=rev_list(list,k,Head,count);
	print_list(list,Head); 
	
	return 0;
} 
