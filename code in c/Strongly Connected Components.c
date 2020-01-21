#include <stdio.h>
#include <stdlib.h>

#define MaxVertices 10  /* maximum number of vertices */
typedef int Vertex;     /* vertices are numbered from 0 to MaxVertices-1 */
typedef struct VNode *PtrToVNode;
struct VNode {
    Vertex Vert;
    PtrToVNode Next;
};
typedef struct GNode *Graph;
struct GNode {
    int NumOfVertices;
    int NumOfEdges;
    PtrToVNode *Array;
};

Graph ReadG(); /* details omitted */

void PrintV( Vertex V )
{
   printf("%d ", V);
}

void StronglyConnectedComponents( Graph G, void (*visit)(Vertex V) );

int main()
{
    Graph G = ReadG();
    StronglyConnectedComponents( G, PrintV );
    return 0;
}

Graph ReadG()
{
	int N1,N2,ig;
	PtrToVNode ptr;
	Graph G = (Graph)malloc(sizeof(struct GNode));
	scanf("%d%d", &G->NumOfVertices, &G->NumOfEdges);
	G->Array = (PtrToVNode*)malloc(G->NumOfVertices * sizeof(PtrToVNode));
	for(ig=0;ig<G->NumOfVertices;ig++)
	G->Array[ig]=NULL;
	for(ig=0;ig<G->NumOfEdges;ig++)
	{
		scanf("%d%d", &N1, &N2);
		if(G->Array[N1]== NULL)
		{
			G->Array[N1]=(PtrToVNode)malloc(sizeof(struct VNode));
			G->Array[N1]->Next=NULL;
			G->Array[N1]->Vert=N2;
		}
		else
		{
			ptr=(PtrToVNode)malloc(sizeof(struct VNode));
			ptr->Vert=N2;
			ptr->Next=NULL;
			ptr->Next=G->Array[N1];
			G->Array[N1]= ptr;
		}
	}
	return G; 
}


//////////////////////////////////////////////////////////

int visited[20];

void DFS(int graph[][20],int v,int NV){
	visited[v]=1;
	for (int w=0;w<NV;w++){
		if (w!=v && graph[v][w]==1 && !visited[w]){
			DFS(graph,w,NV);
		}
	}	
}

void StronglyConnectedComponents(Graph G, void(*visit)(Vertex V)) {
	int i,j;
	int edge[20][20]={0};

	//½¨Á¢ÁÚ½Ó¾ØÕó
	for (i=0;i<G->NumOfVertices;i++){
		PtrToVNode temp;
		temp=G->Array[i];

	
	
		while(temp){
			j=temp->Vert;
			edge[i][j]=1;
			temp=temp->Next;	
		}
	}
	
	int IsConnected[20][20]={0};
	
	for (i=0;i<G->NumOfVertices;i++){
		for (j=0;j<G->NumOfVertices;j++){
			for (int t=0;t<G->NumOfVertices;t++){
				visited[t]=0;
			}
				DFS(edge,i,G->NumOfVertices);
			if (visited[j]==1)
				IsConnected[i][j]=1;
		}
	}
	
	int flag[20]={0};
	
	for (i=0;i<G->NumOfVertices;){
		int first=1;	
		for (j=i;j<G->NumOfVertices;j++){
			if (IsConnected[i][j]==1 && IsConnected[j][i]==1){		
				PrintV(j);
				flag[j]=1;
			}
		}
		printf("\n");
		while (flag[i] && i<G->NumOfVertices){
			i++;
		}
	}
	return;
}
