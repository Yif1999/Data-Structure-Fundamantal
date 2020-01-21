#include<stdio.h>
#include<stdlib.h>
#define MAXN 105	

int Sort[MAXN][MAXN]={0};	//���ڴ洢���ս���ľ���ÿ�д洢һ������
int Tmep[MAXN]={0};	//���ں���ð�����򽻻����е���ʱһά����ռ�

struct Graph{
	int weight;	//Ȩ��
	int parent,k,child[MAXN];	//parent���ڵ�id��k�ӽڵ������child�ӽڵ�id
}G[MAXN];	//ÿ���ڵ�Ĵ洢�ṹ

void BuildGraph(int n,int m){	//��ͼ
	int i,j,t;
	for (i=0;i<n;i++){	//����n�����벢�Խڵ�Ȩ�����ӽڵ�������и�ֵ���ʼ��
		scanf ("%d",&G[i].weight);
		G[i].k=0;
	}
	for (i=0;i<m;i++){
		int id,k;
		scanf ("%d %d",&id,&k);	//��ȡ���id���ӽڵ����k
		G[id].k=k;
		for (j=0;j<k;j++){	//�������ӹ�ϵ
			scanf("%d",&t);
			G[id].child[j]=t;
			G[t].parent=id;
		}
		
	}
}

int path[MAXN],line=0;	//path�洢����Ҫ���DFS·����lineΪ������е�����

void DFS(int id,int s,int weight_sum,int path_length){	//�����������
	if (weight_sum==s && G[id].k==0){	//��Ȩ��֮�͵���Ҫ���ֵ���Ѿ���������
		for (int i=0;i<path_length;i++){	//��·�������洢����ľ����е�һ��
			Sort[line][i]=G[path[i]].weight;
		}
		line++;
	}
	else if (weight_sum<s){	//��Ȩ�غͲ����������
		for (int i=0;i<G[id].k;i++){
			int child=G[id].child[i];
			path[path_length]=child;	//ɨ���ڽӵ�
			DFS(child,s,weight_sum+G[child].weight,path_length+1);	//�ݹ�DFS
		}
	}
	return;
}

int cmp(int i,int j){	//���ڱȽ������д�С�ĺ���
	int k=0;
	while(Sort[i][k]==Sort[j][k]){	//ֱ�����е�k��Ԫ�ز���
		k++;
	}
	return Sort[i][k]-Sort[j][k]; //���ز�ֵ
}

void ArraySort(){	//�Խ������Sort����ð������
	int i,j,k;
	for (i=line-1;i>=0;i--){
		int flag=0;
		for (j=0;j<i;j++){
			if (cmp(j,j+1)<0){	//����һά������Ϊ��ʱ�ռ���н���
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
	scanf("%d %d %d",&N,&M,&S);	//�����ʼ����N��M��S
	BuildGraph(N,M);	//��ͼ
	DFS(0,S,G[0].weight,1);	//�����������
	ArraySort();	//����������
	for (int i=0;i<line;i++){	//����ʽ���
		for (int j=0;Sort[i][j]!=0;j++){
			if (!j)
				printf("%d",Sort[i][j]);					
			else 
				printf(" %d",Sort[i][j]);			
		}	
		printf("\n");	//�����һ����һ������
	}

	return 0;
}				

//����� 3180101376