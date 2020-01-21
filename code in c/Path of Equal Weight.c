#include<stdio.h>
#include<stdlib.h>
#define MAXN 105	

int Sort[MAXN][MAXN]={0};	//用于存储最终结果的矩阵，每行存储一条序列
int Tmep[MAXN]={0};	//用于后续冒泡排序交换序列的临时一维数组空间

struct Graph{
	int weight;	//权重
	int parent,k,child[MAXN];	//parent父节点id，k子节点个数，child子节点id
}G[MAXN];	//每个节点的存储结构

void BuildGraph(int n,int m){	//建图
	int i,j,t;
	for (i=0;i<n;i++){	//读入n行输入并对节点权重与子节点个数进行赋值与初始化
		scanf ("%d",&G[i].weight);
		G[i].k=0;
	}
	for (i=0;i<m;i++){
		int id,k;
		scanf ("%d %d",&id,&k);	//读取编号id与子节点个数k
		G[id].k=k;
		for (j=0;j<k;j++){	//建立父子关系
			scanf("%d",&t);
			G[id].child[j]=t;
			G[t].parent=id;
		}
		
	}
}

int path[MAXN],line=0;	//path存储符合要求的DFS路径，line为结果序列的条数

void DFS(int id,int s,int weight_sum,int path_length){	//深度优先搜索
	if (weight_sum==s && G[id].k==0){	//若权重之和等于要求键值且已经搜索到底
		for (int i=0;i<path_length;i++){	//将路径填充入存储结果的矩阵中的一行
			Sort[line][i]=G[path[i]].weight;
		}
		line++;
	}
	else if (weight_sum<s){	//若权重和不足继续搜索
		for (int i=0;i<G[id].k;i++){
			int child=G[id].child[i];
			path[path_length]=child;	//扫描邻接点
			DFS(child,s,weight_sum+G[child].weight,path_length+1);	//递归DFS
		}
	}
	return;
}

int cmp(int i,int j){	//用于比较两序列大小的函数
	int k=0;
	while(Sort[i][k]==Sort[j][k]){	//直至序列第k个元素不等
		k++;
	}
	return Sort[i][k]-Sort[j][k]; //返回差值
}

void ArraySort(){	//对结果矩阵Sort进行冒泡排序
	int i,j,k;
	for (i=line-1;i>=0;i--){
		int flag=0;
		for (j=0;j<i;j++){
			if (cmp(j,j+1)<0){	//利用一维数组作为临时空间进行交换
				for (k=0;k<MAXN;k++){
					Tmep[k]=Sort[j][k];
				}
				for (k=0;k<MAXN;k++){
					Sort[j][k]=Sort[j+1][k];
				}
				for (k=0;k<MAXN;k++){
					Sort[j+1][k]=Tmep[k];
				}
				flag++;
			}
		}
		if (flag==0) break;
	}
}

int main(){
	int N,M,S;
	scanf("%d %d %d",&N,&M,&S);	//读入初始数据N，M，S
	BuildGraph(N,M);	//建图
	DFS(0,S,G[0].weight,1);	//深度优先搜索
	ArraySort();	//序列排序函数
	for (int i=0;i<line;i++){	//按格式输出
		for (int j=0;Sort[i][j]!=0;j++){
			if (!j)
				printf("%d",Sort[i][j]);					
			else 
				printf(" %d",Sort[i][j]);			
		}	
		printf("\n");	//输出完一行来一个换行
	}

	return 0;
}				

//於怿丰 3180101376