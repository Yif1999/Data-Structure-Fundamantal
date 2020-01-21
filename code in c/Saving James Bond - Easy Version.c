#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MaxVertexNum 101

int N,D;
struct Crocodile{
	int x;
	int y;
}cro[MaxVertexNum]; 

int Visited[MaxVertexNum]={0};
int result=0;

double Distance(int i,int j){
	double d;
	d=sqrt(pow(cro[i].x-cro[j].x,2)+pow(cro[i].y-cro[j].y,2));
	return d;
} 

int CanEscape(int i){
	if ((cro[i].x<=D-50)||(cro[i].y<=D-50)||(cro[i].x>=50-D)||(cro[i].y>=50-D)){
		return 1;
	}
	else{
		return 0;
	}
}

int DFS(struct Crocodile cro[],int V,int Visted[]){
	Visited[V]=1;
	if (CanEscape(V)){
		result=1;
	}
	else{
		for (int i=1;i<=N;i++){
			if ((Visited[i]==0)&&(Distance(V,i)<=D)){
				result=DFS(cro,i,Visited);
			}
		}
	}
	return result;
}

int main(){
	scanf("%d %d",&N,&D);
	cro[0].x=0;
	cro[0].y=0;
	for (int i=1;i<=N;i++){
		scanf("%d %d",&cro[i].x,&cro[i].y);
	}
	
	Visited[0]=1;
	for (int i=1;i<=N;i++){
		if (Distance(0,i)<=(D+7.5)){
			result=DFS(cro,i,Visited);
			if (result){
				printf("Yes");
				break;
			}
		}
	}
	if (!result){
		printf("No");
	}
	return 0;
}
