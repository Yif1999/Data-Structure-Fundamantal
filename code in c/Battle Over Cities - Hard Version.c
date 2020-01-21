#include<stdio.h>
#include<stdlib.h>
#define INFINITY 1000000
#define MAX 505

struct City{
	int city1,city2;	//两城市编号
	int cost,status;	//cost为修复花销，status为通断情况
};	//开辟存储结构

int parent(int t,int S[]){	//路径压缩查找（Find函数换了个名字）
	if (S[t]==t)
		return t;
	else
		return S[t]=parent(S[t],S);
}
 
void Union(int a,int b,int S[]){	//并查集连结
	int tmp1,tmp2;
	tmp1=parent(a,S);
	tmp2=parent(b,S);
	if (tmp1==tmp2)
		return;
	S[tmp1]=tmp2;
}

int compare(struct City a,struct City b){	//用于在堆排序中比较判断花销的函数
	if (a.status!=b.status)
		return b.status-a.status;
	else
		return a.cost-b.cost;
}

void PercDown(struct City W[],int P,int M){	//堆排序中的PercDown函数
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

void HeapSort(struct City W[],int M){	//对花销进行堆排序
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
	//读入初始参数开辟空间
	int i=1;
	while (i<N+1){	//对记录开销的cost数组进行初始化归零	
		cost[i]=0;
		i++;
	}
	
	for (i=0;i<M;i++){
		scanf("%d %d %d %d",&way[i].city1,&way[i].city2,&way[i].cost,&way[i].status);
	}	//读入每一行输入
	
	HeapSort(way,M);	//堆排序
	
	int j,k,max_cost=0;
	for (i=1;i<N+1;i++){
		
		j=1;
		while(j<N+1){	//初始化
			S[j]=j;
			j++;
		}
		
		j=0;
		while (j<M){
			if (!(way[j].city1==i || way[j].city2==i)){	//根据链接情况在并查集中连结相应城市
				if (way[j].status==1)	//公路完好
					Union(way[j].city1,way[j].city2,S);	//在集合中连结城市
				else
					if (parent(way[j].city1,S)!=parent(way[j].city2,S)){	//若不连通则需要修复公路
						Union(way[j].city1,way[j].city2,S);	//修复公路连结集合
						cost[i]=cost[i]+way[j].cost;	//花销累加
					}
			}
			j++;
		}
		
		for (j=1;j<N+1;j++){
			if (j!=i){
				for (k=1;k<N+1;k++)
					if((k!=i) && (parent(j,S)!=parent(k,S))){
						cost[i]=INFINITY;	//设置哨兵
						break;
					}
				break;
			}		
		}
		while (cost[i]>max_cost){	//查找最大花销的城市
			max_cost=cost[i];
		}
	} 
	
	if (max_cost==0){	//如果最大花销为0则跳出循环
		printf("0");
		return 0;
	}
	int first=1;	//按格式输出修复花销最大的几个城市编号
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
//於怿丰 3180101376