#include<stdio.h>
#include<stdlib.h>
#define MAXN 1010

int edge[MAXN][MAXN]={0};
int indegree[MAXN]={0};
int queue[MAXN]={0};

void Topsort(int N,int hash[],int M){

	int i,j,q=0,cnt=0;
	int first=1;
	while (cnt<M){
		for (i=0;i<N;i++)	
		if (indegree[i]==0){
			queue[q]=i;
			q++;
		}
		int min=queue[0];
		for (i=1;i<q;i++){
			if (hash[min]>hash[queue[i]]){
				min=queue[i];
			}
		}
		indegree[min]--;
		if (first){
			printf("%d",hash[min]);	
			first--;
		}		
		else
			printf(" %d",hash[min]);
		for (j=0;j<N;j++){
			if (edge[min][j]==1){
				indegree[j]--;
			}
		}
		cnt++;
		q=0;
	}
}

int main(){
	int N;
	scanf("%d",&N);
	int M=N;
	int i,j,hash[N+1];
	for (i=0;i<N;i++){
		scanf("%d",&hash[i]);
	}
	int ptr;
	for (i=0;i<N;i++){
		if (hash[i]>=0){
			ptr=hash[i]%N;
			for (j=ptr;j!=i;j=(j+1)%N){
				edge[j][i]=1;
				indegree[i]++;
			}
		}
		else{
			indegree[i]=-1;
			M--;
		}
			
	}
	Topsort(N,hash,M);

	return 0;
} 
