#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXN 10001
 
int G[MAXN][MAXN]={0};
int visited[MAXN]={0};
int m,n;

void isinvisited();
int BFS(int v);

int main(){
	int i,v1,v2;
	scanf("%d %d",&n,&m);
	for (i=0;i<m;i++){
		scanf("%d %d",&v1,&v2);
		v1--;v2--;
		G[v1][v2]=1;
		G[v2][v1]=1; 
	}
	
	int v,count;
	double ratio;
	for (v=0;v<n;v++){
		isinvisited();
		count=BFS(v);
		ratio=count*1.0/n*100;
		printf("%d: %.2lf%%\n",v+1,ratio);
	}
	return 0;
}

void isinvisited(){
	int i;
	for (i=0;i<n;i++){
		visited[i]=0;
	}
}

int BFS(int v){
	const int maxnum=10002;
	int queue[maxnum];
	int first=-1,rear=-1;
	int count,level,last,tail;
	visited[v]=1;
	count=1;
	level=0;
	last=v;
	queue[++rear]=v;
	
	while(first<rear){
		int de=queue[++first];
		for (int i=0;i<n;i++){
			if(G[de][i]&&!visited[i]){
				visited[i]=1;
				queue[++rear]=i;
				count ++;
				tail = i; 
			}
		}
		if (de==last){
			level++;
			last=tail;
		}
		if (level==6){
			break;
		}
	}
	return count;
}
