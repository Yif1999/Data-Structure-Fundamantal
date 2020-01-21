#include<stdio.h>
#include<stdlib.h>
#define maxn 10001
typedef int ElementType;
typedef int setName;
typedef int setType[maxn];

int Find(setType S,ElementType X){
    if(S[X] < 0) return X;
    else return S[X] = Find(S,S[X]); 
}

void Input_connection(setType S){
    ElementType u,v;
    setName root1,root2;
    scanf("%d %d\n",&u,&v);
    root1 = Find(S,u-1);
    root2 = Find(S,v-1);
    if(root1 != root2) S[root1] = root2;
}

void Check_connection(setType S){
    ElementType u,v;
    setName root1,root2;
    scanf("%d %d\n",&u,&v);
    root1 = Find(S,u-1);
    root2 = Find(S,v-1);
    if(root1 != root2) printf("no\n");
    else printf("yes\n");
}

void Check_network(setType S,int n){
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(S[i] < 0) counter++;
    }
    if(counter == 1) printf("The network is connected.\n");
    else printf("There are %d components.\n",counter);
}

void Initialization(setType S,int n){
    for(int i = 0; i < n; i++){
        S[i] = -1;
    }
}

int main(){
    setType S;
    int n;
    char in;
    scanf("%d\n",&n);
    Initialization(S,n);
    do{
        scanf("%c",&in);
        switch(in){
            case 'I':Input_connection(S);break;
            case 'C':Check_connection(S);break;
            case 'S':Check_network(S,n);break;
        }
    }while(in != 'S');
    return 0;
}
