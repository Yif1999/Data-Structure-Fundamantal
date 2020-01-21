#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define INFINITY 2000000
#define MAX 1000

int count;

struct station {
	char n[4];
}sta[MAX];

int edge[1000][1000]={0};

struct Queue{
	int Front;
	int Rear;
	int a[10000];
}Q;

int Find_MAXFLOW(int s,int t){
	int i,j;
	int max_flow=0;
	int pre[MAX]={0},res[MAX]={0},flow[MAX][MAX];
	for (i=0;i<MAX;i++){
		for (j=0;j<MAX;j++){
			flow[i][j]=0;
		}
	}
	Q.Front=0;Q.Rear=-1;
	while(1){
		int n;
		for (i=0;i<MAX;i++)	res[i]=0;
		res[s]=INFINITY;
		Q.Rear++;
		Q.a[Q.Rear]=s;
		while(!(Q.Rear<Q.Front)){
			int m=Q.a[Q.Front];
			Q.Front++;
			for (n=0;n<count;n++){
				if (n!=t){
					if (!res[n]&&edge[m][n]>flow[m][n]){
					if (res[m]<edge[m][n]-flow[m][n])
						res[n]=res[m];
					else
						res[n]=edge[m][n]-flow[m][n];
					pre[n]=m;
					Q.Rear++;
					Q.a[Q.Rear]=n;
					}
				}	
			}
			n=t;
			if (!res[n]&&edge[m][n]>flow[m][n]){
				if (res[m]<edge[m][n]-flow[m][n])
				res[n]=res[m];
				else
				res[n]=edge[m][n]-flow[m][n];
			pre[n]=m;
			Q.Rear++;
			Q.a[Q.Rear]=n;
			}
	
		}
		if (res[t]==0) return max_flow;
		for (int m=t;m!=s;m=pre[m]){
			flow[pre[m]][m]+=res[t];
			flow[m][pre[m]]-=res[t];
		}
		max_flow+=res[t];
	}
}

int main(){
	int N,i,j,capacity,k;
	char source[4],destination[4];

	scanf("%s %s %d",&source,&destination,&N);
	
	if (strcmp(source,destination)){
		count=2;
		strcpy(sta[0].n,source);
		strcpy(sta[1].n,destination);
	}
	else{
		count=1;
		strcpy(sta[0].n,source);
	}
	
	int m,n;

	for (j=0;j<N;j++){
		scanf ("%s %s %d",&source,&destination,&capacity);
		
		k=0;
		for (i=0;i<count;i++){
			if (!strcmp(sta[i].n,source)){
				k=1;
				break;
			}
		}
		if (k==0) {
			strcpy(sta[i].n,source);
			count=i+1;
		}
		m=i;
		
		k=0; 
		for (i=0;i<count;i++){
			if (!strcmp(sta[i].n,destination)){
				k=1;
				break;
			}
		}
		if (k==0){
			strcpy(sta[i].n,destination);
			count=i+1;
		}
		n=i;
		
		edge[m][n]+=capacity;
	}
			
	printf("%d",Find_MAXFLOW(0,1));
	
	return 0;
}
