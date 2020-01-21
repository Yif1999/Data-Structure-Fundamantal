#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;

typedef struct StackRecord *Stack;
struct StackRecord  {
    int Capacity;       /* maximum size of the stack array */
    int Top1;           /* top pointer for Stack 1 */
    int Top2;           /* top pointer for Stack 2 */
    ElementType *Array; /* space for the two stacks */
};

Stack CreateStack( int MaxElements );
int IsEmpty( Stack S, int Stacknum );
int IsFull( Stack S );
int Push( ElementType X, Stack S, int Stacknum );
ElementType Top_Pop( Stack S, int Stacknum );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Stacknum ); /* details omitted */

int main()
{
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Sn, &X);
            if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
            break;
        case pop:
            scanf("%d", &Sn);
            X = Top_Pop(S, Sn);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Sn);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

Operation GetOp()
{
    char Push[] = "Push";
    char Pop[] = "Pop";
    char End[] = "End";
    char s[100];
    scanf("%s", s);

    if (strcmp(Push, s) == 0)return push;
    if (strcmp(Pop, s) == 0)return pop;
    if (strcmp(End, s) == 0)return end;
}
void PrintStack(Stack S, int Tag)
{
    printf("Pop from Stack %d:", Tag);
    if (Tag == 1){
        while (S->Top1 != -1){
            printf(" %d", S->Array[S->Top1--]);
        }
    }
    else {
        while (S->Top2 != S->Capacity){
            printf(" %d", S->Array[S->Top2++]);
        }
    }
    putchar('\n');
}

Stack CreateStack( int MaxElements ){
	Stack s;
	s=(Stack)malloc(sizeof(struct StackRecord));
	s->Array=(int *)malloc(sizeof(ElementType)*MaxElements);
	s->Top1=-1;
	s->Top2=MaxElements;
	s->Capacity=MaxElements;
	return s;
} 

int IsEmpty( Stack S, int Stacknum ){
	switch(Stacknum){
		case 1:
			if (S->Top1==-1) return 1;
			else return 0;
			break;
		case 2:
			if (S->Top2==S->Capacity) return 1;
			else return 0;
			break;
	}
}

int IsFull( Stack S ){
	if (S->Top1+1==S->Top2)	return 1;
	else return 0;
}

int Push( ElementType X, Stack S, int Stacknum ){
	if (IsFull(S)) return 0;
	else{
		switch (Stacknum){
			case 1:
				S->Array[++S->Top1]=X;
				break;
			case 2:
				S->Array[--S->Top2]=X;
				break;
		}
		return 1;
	}
}

ElementType Top_Pop( Stack S, int Stacknum ){
	if (S==NULL) return ERROR;
	switch (Stacknum){
		case 1:
			if (IsEmpty(S,1)) return ERROR;
			else return S->Array[S->Top1--];
			break;
		case 2:
			if (IsEmpty(S,2)) return ERROR;
			else return S->Array[S->Top2++];
			break;
	}
}
