#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int maxsubsum=0,thismax=0,maxsum=-1;
	int left=0,right=0,temp_left=0;
	for(i=0;i<n;i++){
		thismax += a[i];
		if(thismax<0){
			thismax=0;
			temp_left=i+1;
		}	
		else if(thismax>maxsum){
			maxsum=thismax;
			left=temp_left;
			right=i;
		}
	}
	maxsubsum=maxsum;
	if(maxsubsum<0)
		printf("0 %d %d",a[0],a[n-1]);
	else
		printf("%d %d %d",maxsubsum,a[left],a[right]);
} 
