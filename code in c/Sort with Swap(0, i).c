#include<stdio.h>

void Print(int A[],int a,int b,int N){
	if (A[0]==0){
		int result=N-a+b;
		printf("%d",result);
	}
	else if (a!=N){
		int result=N-a+b-2;
		printf("%d",result);
	}
	else if (a==N){
		printf("0");
	}
}

int main(){
	int N;
	scanf("%d",&N);
	
	if (N==1){
		printf("0");
		return 0;
	}
	
	int A[N+1],T[N+1],visit[N+1];
	int i;
	for (i=0;i<N;i++){
		visit[i]=0;
		scanf("%d",&A[i]);
		T[A[i]]=i;		
	}
	int temp,count1=0,count2=0;
	for (i=0;i<N;i++){
		if (!visit[i]){
			if (T[i]==i){
				visit[i]++;
				count1++;
			}
			else{
				temp=T[i];
				for (;!visit[temp];temp=T[temp]){
					visit[temp]++;
				}
				count2++;
			}
		}
	}
	Print(A,count1,count2,N);
	
	return 0;
} 
