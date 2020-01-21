#include<stdio.h>
#include<math.h>

int a[1001],t[1001];

void BuildCBT(int aLeft,int aRight,int tRoot);
int LeftNodesCount(int n);

int main(){
	int n,i;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int p,q,k,temp;
	for (p=0;p<n-1;p++){
		k=p;
		for (q=p+1;q<n;q++){
			if (a[q]<a[k]) 	
				k=q;
		}
		temp=a[p];
		a[p]=a[k];
		a[k]=temp;
	}
	
	BuildCBT(0,n-1,0);
	
	for (i=0;i<n;i++){
		if (i==0)
			printf("%d",t[i]);
		else
			printf(" %d",t[i]);
	}
	
	return 0;
} 

void BuildCBT(int aLeft,int aRight,int tRoot){
	int n,l,LTRoot,RTRoot;
	n=aRight-aLeft+1;
	if (n==0) return;
	l=LeftNodesCount(n);
	t[tRoot]=a[aLeft+l];
	LTRoot=tRoot*2+1;
	RTRoot=LTRoot+1;
	BuildCBT(aLeft,aLeft+l-1,LTRoot);
	BuildCBT(aLeft+l+1,aRight,RTRoot);
	return;
}

int LeftNodesCount(int n){
	int height=1,Lsize,max,leftleafsize,leafsize;
	while (pow(2,height)<=n) height++;
	max=pow(2,height-2);
	leafsize=n-(pow(2,height-1)-1);
	leftleafsize=(leafsize<max)?leafsize:max;
	Lsize=pow(2,height-2)-1+leftleafsize;
	return Lsize;
}
