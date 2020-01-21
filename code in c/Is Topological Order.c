#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 1 to MaxVertexNum */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph ReadG(); /* details omitted */

bool IsTopSeq( LGraph Graph, Vertex Seq[] );

int main()
{
    int i, j, N;
    Vertex Seq[MaxVertexNum];
    LGraph G = ReadG();
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        for (j=0; j<G->Nv; j++)
            scanf("%d", &Seq[j]);
        if ( IsTopSeq(G, Seq)==true ) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}

#define MaxSize 1000
typedef struct QNode *Queue;
struct QNode {
	Vertex Data[MaxSize];
	int rear;
	int front;
};

int IsEmpty(Queue Q){
	if (Q->rear == Q->front)
		return 1;
	else
		return 0;
}

void EnQueue(Queue Q,Vertex t){
	Q->rear++;
	Q->Data[Q->rear]=t;
}

Vertex DeQueue(Queue Q){
	Q->Data[Q->front]=0; 
	Q->front++;
	return Q->Data[Q->front]; 
}

bool IsTopSeq( LGraph Graph, Vertex Seq[] ){
	Queue Q=(Queue)malloc(sizeof(struct QNode));
	PtrToAdjVNode Temp;
	int V;
	int i,cnt[MaxSize];
	
	Q->rear=0;Q->front=0;
	for (i=0;i<=Graph->Nv;i++)
		cnt[i] = 0;
	for (i=0;i<Graph->Nv;i++){
		Temp=Graph->G[i].FirstEdge;
		while (Temp){
			cnt[Temp->AdjV]++;
			Temp=Temp->Next;
		}
	}
	
	i=0;
	while(i<Graph->Nv){
		EnQueue(Q,Seq[i]-1);
		i++;
	}
		

	while (!IsEmpty(Q)){
		V = DeQueue(Q);
		if (cnt[V] != 0) 
			return false;
		Temp=Graph->G[V].FirstEdge;
		while (Temp){
			cnt[Temp->AdjV]--;
			Temp = Temp->Next;
		}
	}
	return true;
} 
