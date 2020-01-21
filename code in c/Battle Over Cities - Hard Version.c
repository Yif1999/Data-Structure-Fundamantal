#include<stdio.h>
#include<stdlib.h>
#define INFINITY 1000000
#define MAX 505

struct City{
	int city1,city2;	//�����б��
	int cost,status;	//costΪ�޸�������statusΪͨ�����
};	//���ٴ洢�ṹ

int parent(int t,int S[]){	//·��ѹ�����ң�Find�������˸����֣�
	if (S[t]==t)
		return t;
	else
		return S[t]=parent(S[t],S);
}
 
void Union(int a,int b,int S[]){	//���鼯����
	int tmp1,tmp2;
	tmp1=parent(a,S);
	tmp2=parent(b,S);
	if (tmp1==tmp2)
		return;
	S[tmp1]=tmp2;
}

int compare(struct City a,struct City b){	//�����ڶ������бȽ��жϻ����ĺ���
	if (a.status!=b.status)
		return b.status-a.status;
	else
		return a.cost-b.cost;
}

void PercDown(struct City W[],int P,int M){	//�������е�PercDown����
	int parent,child;
	struct City Tmp;
	Tmp=W[P];
	parent=P;
	while((parent*2+1)<M){
		child=parent*2+1;
		if (compare(W[child],W[child+1])<0)
			if (child!=M-1)
				child++;
		if (compare(Tmp,W[child])<=0)
			W[parent]=W[child];
		else
			break;
		parent=child;
	}
	W[parent]=Tmp;
}

void HeapSort(struct City W[],int M){	//�Ի������ж�����
	int i;
	struct City Tmp;
	for (i=M/2-1;i>=0;i--){
		PercDown(W,i,M);
	}
	for (i=M-1;i>0;i--){
		Tmp=W[0];
		W[0]=W[i];
		W[i]=Tmp;
		PercDown(W,0,i);
	}
}

int main(){
	int N,M;
	scanf ("%d %d",&N,&M);
	int S[N+1],cost[N+1];
	struct City way[M+1];
	//�����ʼ�������ٿռ�
	int i=1;
	while (i<N+1){	//�Լ�¼������cost������г�ʼ������	
		cost[i]=0;
		i++;
	}
	
	for (i=0;i<M;i++){
		scanf("%d %d %d %d",&way[i].city1,&way[i].city2,&way[i].cost,&way[i].status);
	}	//����ÿһ������
	
	HeapSort(way,M);	//������
	
	int j,k,max_cost=0;
	for (i=1;i<N+1;i++){
		
		j=1;
		while(j<N+1){	//��ʼ��
			S[j]=j;
			j++;
		}
		
		j=0;
		while (j<M){
			if (!(way[j].city1==i || way[j].city2==i)){	//������������ڲ��鼯��������Ӧ����
				if (way[j].status==1)	//��·���
					Union(way[j].city1,way[j].city2,S);	//�ڼ������������
				else
					if (parent(way[j].city1,S)!=parent(way[j].city2,S)){	//������ͨ����Ҫ�޸���·
						Union(way[j].city1,way[j].city2,S);	//�޸���·���Ἧ��
						cost[i]=cost[i]+way[j].cost;	//�����ۼ�
					}
			}
			j++;
		}
		
		for (j=1;j<N+1;j++){
			if (j!=i){
				for (k=1;k<N+1;k++)
					if((k!=i) && (parent(j,S)!=parent(k,S))){
						cost[i]=INFINITY;	//�����ڱ�
						break;
					}
				break;
			}		
		}
		while (cost[i]>max_cost){	//����������ĳ���
			max_cost=cost[i];
		}
	} 
	
	if (max_cost==0){	//��������Ϊ0������ѭ��
		printf("0");
		return 0;
	}
	int first=1;	//����ʽ����޸��������ļ������б��
	for (i=1;i<N+1;i++){
		if (cost[i]==max_cost){
			if (first){
				printf("%d",i);
				first--;
			}
			else
				printf(" %d",i);
		}
	}
		
	return 0;
}
//����� 3180101376