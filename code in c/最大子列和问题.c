//在线处理
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int maxsubsum=0,thismax=0,maxsum=0;
	for(i=0;i<n;i++){
		thismax += a[i];
		if(thismax<0)
			thismax=0;
		else if(thismax>maxsum)
			maxsum=thismax;
	}
	maxsubsum=maxsum;
	printf("%d",maxsubsum);
}
