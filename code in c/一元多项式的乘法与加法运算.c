#include<stdio.h>
#include<stdlib.h>
//#include"一元多项式的乘法与加法运算.h"


typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
}; 


Polynomial ReadPoly();

void Attach(int c,int e,Polynomial *pRear);

void PrintPoly(Polynomial P);

Polynomial Add(Polynomial P1,Polynomial P2); 

Polynomial Mult(Polynomial P1,Polynomial P2);


int main(){
	Polynomial P1,P2,PP,PS;
	
	P1=ReadPoly();
	P2=ReadPoly();
	PP=Mult(P1,P2);
	PrintPoly(PP);
	printf("\n");
	PS=Add(P1,P2);
	PrintPoly(PS);
	
	return 0;
}

Polynomial ReadPoly(){
	Polynomial P,Rear,t;
	int c,e,N;
	
	scanf("%d",&N);
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;	
	while(N--){
		scanf("%d %d",&c,&e);
		if (c != 0){
            Attach(c, e, &Rear);
        }
	}	
	t=P;P=P->link;
	free(t);
	return P;
}

void Attach(int c,int e,Polynomial *pRear){
	Polynomial P;
	
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->coef=c;
	P->expon=e;
	P->link=NULL;
	(*pRear)->link=P;
	*pRear=P;
}

Polynomial Add(Polynomial P1, Polynomial P2){
    Polynomial t1,t2,P,Rear,t;
    t1 = P1; 
	t2 = P2;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    
    while (t1 && t2){
        if (t1->expon == t2->expon){
            if (t1->coef + t2->coef)
                Attach(t1->coef + t2->coef, t1->expon, &Rear);	//系数和为0不添加在尾节点上
            t1 = t1->link;
            t2 = t2->link;
        }
        else if (t1->expon > t2->expon){
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->link;
        }
        else{
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->link;
        }
    }
    while (t1){
        Attach(t1->coef, t1->expon, &Rear);
        t1 = t1->link;
    }
    while (t2){
        Attach(t2->coef, t2->expon, &Rear);
        t2 = t2->link;
	}
    t = P;
    P = P->link;
    free(t);

    return P;
}

Polynomial Mult(Polynomial P1,Polynomial P2){
	Polynomial P,Rear,t1,t2,t;
	int c,e;
	
	if(!P1||!P2)return NULL;
	
	t1=P1;t2=P2;
	P=(Polynomial)malloc(sizeof(struct PolyNode));
	P->link=NULL;
	Rear=P;
	while(t2){
		Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);	//第一个多项式的第一项乘以第二个多项式的每一项 
		t2=t2->link;
	} 
	t1=t1->link;
	while(t1){
		t2=P2;Rear=P;
		 while(t2){
		 	e=t1->expon+t2->expon;	//第一个多项式除了第一项的每一项乘以第二个多项式的每一项 
		 	c=t1->coef*t2->coef;
		 	while(Rear->link && Rear->link->expon>e)	//将Rear指针移动到合适的位置以达到降幂排列的目的 
		 		Rear=Rear->link;
		 	if(Rear->link && Rear->link->expon==e){	//指数相同系数相加 
		 		if(Rear->link->coef+c)
		 			Rear->link->coef+=c;
		 		else{	//若系数为0则删除该结点 
		 			t=Rear->link;
		 			Rear->link=t->link;
		 			free(t);
				 }
			 }	
			 else{	//指数不同降幂排列 
			 	t=(Polynomial)malloc(sizeof(struct PolyNode));
				t->coef=c;t-> expon=e;
				t->link=Rear->link;
				Rear->link=t;
				Rear=Rear->link;
			 }
			 t2=t2->link;
		 }
		 t1=t1->link;
	}
	t2=P;P=P->link;
	free(t2);
	
	return P;
}

void PrintPoly(Polynomial P){
	int flag=0;
	if (!P){
		printf("0 0");
		return;
	}
	while(P){
		if(!flag)
			flag=1;
		else
			printf(" ");
		printf("%d %d",P->coef,P->expon);
		P=P->link;
	}
}
