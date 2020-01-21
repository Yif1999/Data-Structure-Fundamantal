#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10001
typedef enum{link,check,end} Operation;

int S[MAX];

Operation Get_Op();
int Find(int X);
void Link();
void Check();
void End(int n);

int main(){
    int n,i;
    Operation Op;
    scanf("%d\n",&n);
    for (i=0;i<n;i++)	S[i]=-1;
    Op=Get_Op();
    while(Op!=end){
        switch(Op){
            case link:	Link();break;
            case check:	Check();break;
        }
        Op=Get_Op();
    }
    End(n);
    return 0;
}

Operation Get_Op(){
	char I[]="I";
	char C[]="C";
	char S[]="S";
	char s[5];
	scanf("%s",s);
	
	if (strcmp(I,s)==0) return link;
	if (strcmp(C,s)==0) return check;
	if (strcmp(S,s)==0) return end;
}

int Find(int X){
    int root,lead,trail;
    for (root=X;S[root]>0;root=S[root]);
    for (trail=X;trail!=root;trail=lead){
    	lead=S[trail];
    	S[trail]=root;
	}
	return root;
}

void Link(){
    int root1,root2;
    int m,n;
    scanf("%d %d\n",&m,&n);
    root1 = Find(m-1);
    root2 = Find(n-1);
    if (S[root1]<S[root2]){
    	S[root1]+=S[root2];
    	S[root2]=root1;
	}
	else{
		S[root2]+=S[root1];
		S[root1]=root2;
	}
}

void Check(){
    int root1,root2;
    int m,n;
    scanf("%d %d\n",&m,&n);
    root1 = Find(m-1);
    root2 = Find(n-1);
    if (root1!=root2) printf("no\n");
    else printf("yes\n");
}

void End(int n){
    int count=0,i;
    for (i=0;i<n;i++){
        if(S[i]<0) count++;
    }
    if(count==1)
		printf("The network is connected.");
    else 
		printf("There are %d components.",count);
}
