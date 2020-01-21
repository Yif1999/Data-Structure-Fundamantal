#include<stdio.h>
#include<stdlib.h>

void Print(int b[],int N){
	int first=1;

	for (int i=0;i<N;i++){
		if (first){
			printf("%d",b[i]);
			first=0;
		}
	
		else
			printf(" %d",b[i]);
	}
}

int IsInsertion(int a[],int b[],int N){
	int k=0,i;
	while(1){
		if (b[k]>b[k+1] || k==N-1)
			break;
		k++;
	}
	i=++k;
	while(i<N){
		if (a[i]!=b[i])
			break;
		i++;
	}
	
	if (i==N)
		return k;
	else
		return 0;
}

void InsertionOneMoreIteration(int b[],int N,int t){
	int i,temp;
	temp=b[t];
	for (i=t;i>0 && b[i-1]>temp;i--){
		b[i] = b[i-1];	
	}
	b[i]=temp;
}

void HeapOneMoreIteration(int b[] ,int N){
	int i=N-1,capacity,temp;
	while(i>=0){
		if (b[i]<b[0]){
			capacity=i;
			break;
		}
		i--;
	}
	temp=b[capacity];
	b[capacity]=b[0];
	b[0]=temp;
	capacity--;
	for (i=0;2*i+1<=capacity;){
		if (2*i+2<=capacity && b[2*i+2]>b[2*i+1]){
			if (temp>=b[2*i+2])
				break;
			b[i]=b[2*i+2];
			i=2*i+2;
		}
		else{
			if (temp>=b[2*i+1])
				break;			
			b[i]=b[2*i+1];
			i=2*i+1;
		}
	}
	b[i]=temp;
}

int main(){
	int N;
	scanf("%d",&N);
	int i,a[N+1],b[N+1];
	for (int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	int t=IsInsertion(a,b,N);
	if (t){
		printf("Insertion Sort\n");
		InsertionOneMoreIteration(b,N,t);
		Print(b,N);
	}	
	else{													
		printf("Heap Sort\n");
		HeapOneMoreIteration(b,N);
		Print(b,N);
	}	
	system("pause");
	return 0;
}
