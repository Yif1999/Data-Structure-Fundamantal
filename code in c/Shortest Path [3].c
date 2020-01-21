#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define INFINITY 1000000
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */
typedef int WeightType;
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S );

int main()
{
    int dist[MaxVertexNum], count[MaxVertexNum];
    Vertex S, V;
    int i,j;
    MGraph G1 = (MGraph*)malloc(sizeof(struct GNode));
    for(i=0;i<MaxVertexNum;i++)
        for(j=0;j<MaxVertexNum;j++)
            G1->G[i][j]=INFINITY;
    G1->G[3][0]=40;
    G1->G[3][1]=20;
    G1->G[3][2]=100;
    G1->G[3][7]=70;
    G1->G[0][4]=5;
    G1->G[0][7]=10;
    G1->G[4][7]=5;
    G1->G[6][2]=1; 
    G1->G[7][2]=50;
    G1->G[7][5]=3;
    G1->G[1][7]=30;   
    G1->Nv=8;
    G1->Ne=11;
    scanf("%d", &S);
    ShortestDist( G1, dist, count, S );
    for ( V=0; V<G1->Nv; V++ )
        printf("%d ", dist[V]);
    printf("\n");
    for ( V=0; V<G1->Nv; V++ )
        printf("%d ", count[V]);
    printf("\n");
    return 0;
}

void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S){
	int i;
	bool flag[Graph->Nv];
	//初始化 
	dist[S]=0;
	count[S]=1; 
	for (i=0;i<Graph->Nv;i++){
		if (i!=S){
			dist[i]=INFINITY;
			count[i]=0;
			flag[i]=false;
		}
	}
	for (i=0;i<Graph->Nv;i++){
		if (i!=S && Graph->G[S][i]!=INFINITY){
			dist[i]=Graph->G[S][i];
			count[i]=1;
		}
	}
	//遍历解题 
	while(1){
		Vertex V=-1;
		int min_dist=INFINITY;
		for (i=0;i<Graph->Nv;i++) {
			if (flag[i]==false){
				if (dist[i]<min_dist){
					min_dist=dist[i];
					V=i;
				}
			}
		}
		if (V<0)
			break;
		flag[V]=true;
		for (i=0;i<Graph->Nv;i++){
			if (i!=V && Graph->G[V][i]!=INFINITY){
				if (flag[i]==false){
					if (Graph->G[V][i]+dist[V]==dist[i]){
						count[i]=count[i]+count[V];
					}
					else if (Graph->G[V][i]+dist[V]<dist[i]){
						dist[i]=Graph->G[V][i]+dist[V];
						count[i]=count[V];
					}
				}
			}
		}		
	}
	//规范输出格式 
	i=0;	
	while (i<Graph->Nv){
		if (dist[i]==INFINITY){
			dist[i]=-1;
			count[i]=0;
		}
		i++;
	}
	return;
}
