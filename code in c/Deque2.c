#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR 1e5
typedef enum { push, pop, inject, eject, end } Operation;

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};
Deque CreateDeque();
int Push( ElementType X, Deque D );
ElementType Pop( Deque D );
int Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp();          /* details omitted */
void PrintDeque( Deque D ); /* details omitted */

int main()
{
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Memory is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Memory is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }
    return 0;
}

void PrintDeque( Deque D )
{
    if(D -> Rear == D -> Front)
    {
        printf("Deque is Empty!");
        return;
    }
    printf("Inside Deque:");
    PtrToNode p = D -> Front -> Next;
    while(p)
    {
        printf(" %d",p -> Element);
        p = p -> Next;
    }
}
Operation GetOp()
{
    char s[10];
    scanf("%s",s);
    if(!strcmp(s,"Pop"))return pop;
    else if(!strcmp(s,"Push"))return push;
    else if(!strcmp(s,"Inject"))return inject;
    else if(!strcmp(s,"Eject"))return eject;
    else return end;
}
//------------------------------------------------//

Deque CreateDeque(){
	PtrToNode p;Deque d;
	p=(PtrToNode)malloc(sizeof(struct Node));
	p->Next=NULL;p->Last=NULL;
	d=(Deque)malloc(sizeof(struct DequeRecord));
	d->Rear=p;d->Front=p;
	
	return d;
}

int Push( ElementType X, Deque D ){
	PtrToNode temp,head;
	temp=(PtrToNode)malloc(sizeof(struct Node));
	if (temp==NULL) return 0;
	temp->Element=X;
	if (D->Front==D->Rear){
		head=(PtrToNode)malloc(sizeof(struct Node));
		if (head==NULL) return 0;
		head->Last=NULL;
		head->Next=temp;
		temp->Last=head;
		temp->Next=NULL;
		D->Rear=temp;
		D->Front=head;
	}
	else{
		temp->Next=D->Front->Next;
		temp->Next->Last=temp;
		temp->Last=D->Front;
		D->Front->Next=temp; 
	}
	return 1;
}

ElementType Pop( Deque D ){
	ElementType t;PtrToNode temp;
	if (D->Front==D->Rear) return ERROR;
	t=D->Front->Next->Element;
	temp=D->Front->Next;
	D->Front->Next=temp->Next;
	if (temp->Next) temp->Next->Last=D->Front;
	else{
		free(D->Front);
		D->Front=D->Rear;	
	}
	free(temp);
	return t;
}

int Inject( ElementType X, Deque D ){
	PtrToNode temp;
	temp=(PtrToNode)malloc(sizeof(struct Node));
	if (temp==NULL) return 0;
	temp->Element=X;
	temp->Next=NULL;
	temp->Last=D->Rear;
	D->Rear->Next=temp;
	D->Rear=temp;
	return 1;
}

ElementType Eject( Deque D ){
	ElementType t;PtrToNode temp;
	if (D->Front==D->Rear) return ERROR;
	t=D->Rear->Element;
	temp=D->Rear;
	D->Rear=temp->Last;
	temp->Last->Next=NULL;
	free(temp);
	return t;
}

