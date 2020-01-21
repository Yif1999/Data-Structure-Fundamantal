typedef struct Node *PtrToNode;
struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Add( Polynomial a, Polynomial b ){
    Polynomial p,temp1,temp2,prior;
    p=(Polynomial)malloc(sizeof(struct Node));
    p->Next=NULL;
	temp1=a;temp2=b;prior=p;
    
    while(temp1 && temp2){
    	if (temp1->Exponent == temp2->Exponent){
    		if (temp1->Coefficient+temp2->Coefficient){
    			p->Coefficient=temp1->Coefficient+temp2->Coefficient;
    			p->Exponent=temp1->Exponent;
    			p->Next=NULL;
    			prior->Next=p;
    			prior=p;
    			temp1=temp1->Next;temp2=temp2->Next;
			}
			else if (temp1->Exponent < temp2->Exponent){
				p->Coefficient=temp2->Coefficient;
				p->Exponent=temp2->Exponent;
				p->Next=NULL;
				prior->Next=p;
				prior=p;
				temp2=temp2->Next; 
			}
			else if (temp2->Exponent < temp1->Exponent){
				p->Coefficient=temp1->Coefficient;
				p->Exponent=temp1->Exponent;
				p->Next=NULL;
				prior->Next=p;
				prior=p;
				temp1=temp1->Next; 
			}
		}
	}
	while (temp1){
		p->Coefficient=temp1->Coefficient;
		p->Exponent=temp1->Exponent;
		p->Next=NULL;
		prior->Next=p;
		prior=p;
		temp1=temp1->Next; 
	}
	while (temp2){
		p->Coefficient=temp2->Coefficient;
		p->Exponent=temp2->Exponent;
		p->Next=NULL;
		prior->Next=p;
		prior=p;
		temp2=temp2->Next; 
	}
	
	return p;
    
}
