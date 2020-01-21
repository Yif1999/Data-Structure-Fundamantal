#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
    int Key;
    BinTree Left;
    BinTree Right;
};

BinTree BuildTree(){
	BinTree T=NULL;
/*	T=(BinTree)malloc(sizeof(struct TNode));
	T->Left=(BinTree)malloc(sizeof(struct TNode));
	T->Left->Left=(BinTree)malloc(sizeof(struct TNode));
	T->Right=(BinTree)malloc(sizeof(struct TNode));
	T->Right->Left=(BinTree)malloc(sizeof(struct TNode));
	T->Right->Right=(BinTree)malloc(sizeof(struct TNode));
	T->Key=4;
	T->Left->Key=5;
	T->Left->Left->Key=1;
	T->Left->Right=NULL;
	T->Right->Key=3;
	T->Right->Left->Key=6;
	T->Right->Right->Key=7;
	T->Left->Left->Left=NULL;
	T->Left->Left->Right=NULL;
	T->Right->Left->Left=NULL;
	T->Right->Left->Right=NULL;
	T->Right->Right->Left=NULL;
	T->Right->Right->Right=NULL;*/
	T=(BinTree)malloc(sizeof(struct TNode));
	T->Left=(BinTree)malloc(sizeof(struct TNode));
	T->Left->Left=(BinTree)malloc(sizeof(struct TNode));
	T->Left->Left->Right=(BinTree)malloc(sizeof(struct TNode));
	T->Right=(BinTree)malloc(sizeof(struct TNode));
	T->Right->Right=(BinTree)malloc(sizeof(struct TNode));
	T->Right->Right->Left=(BinTree)malloc(sizeof(struct TNode));
	T->Right->Right->Right=(BinTree)malloc(sizeof(struct TNode));
	T->Left->Right=NULL;
	T->Left->Left->Left=NULL;
	T->Left->Left->Right->Left=NULL;
	T->Left->Left->Right->Right=NULL;
	T->Right->Left=NULL;
	T->Right->Right->Left->Left=NULL;
	T->Right->Right->Left->Right=NULL;
	T->Right->Right->Right->Left=NULL;
	T->Right->Right->Right->Right=NULL;
	T->Key=4;
	T->Left->Key=3;
	T->Left->Left->Key=1;
	T->Left->Left->Right->Key=2;
	T->Right->Key=5;
	T->Right->Right->Key=7;
	T->Right->Right->Left->Key=6;
	T->Right->Right->Right->Key=8;
	return T;
}


int CheckIsBst ( BinTree T, int K );

int main()
{
    BinTree T;
    int K, out;

    T = BuildTree();
    scanf("%d", &K);
    out = CheckBST(T, K);
    if ( out < 0 )
        printf("No.  Height = %d\n", -out);
    else
        printf("Yes.  Key = %d\n", out);

    return 0;
}

int IsBst( BinTree T){
	static BinTree PreT;
	if (T!=NULL){
		if (!IsBst(T->Left))
			return 0;
		if (PreT!=NULL && T->Key<PreT->Key)
			return 0;
		PreT=T;
		if (!IsBst(T->Right))
			return 0;
	}
	return 1;
}

int Key( BinTree T, int K ){
	typedef struct SNode *Stack;
	struct SNode{
		BinTree Data;
		struct SNode *Next;
	};
	
	Stack S;
	S=(Stack)malloc(sizeof(struct SNode));
	S->Next=NULL;
	
	BinTree Temp=T;
	int count=0;
	
	while(Temp || S->Next!=NULL){
		while (Temp){
			struct SNode *TmpCell;
			TmpCell=(struct SNode *)malloc(sizeof(struct SNode));
			TmpCell->Data=Temp;
			TmpCell->Next=S->Next;
			S->Next=TmpCell;
			Temp=Temp->Right;
		}
		if (S->Next!=NULL){
		struct SNode *FirstCell;
		int Top;
		FirstCell=S->Next;
		S->Next=FirstCell->Next;
		Top=FirstCell->Data->Key;
		Temp=FirstCell->Data;
		free(FirstCell);
		if (count++==K-1)
			return Top;	
		else
			Temp=Temp->Left;
		}
	}
	return 0;

}

int Height( BinTree T){
	int h,lh,rh;
	if (!T) 
		h=0;
	else{
		lh=Height(T->Left);
		rh=Height(T->Right);
		if (lh>rh)	h=lh+1;
		else	h=rh+1;
	}
	return h;
}

int CheckBST ( BinTree T, int K ){
	if (IsBst(T))
		return Key( T, K );
	else
		return (0-Height(T));
} 
