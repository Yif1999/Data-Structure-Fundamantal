#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
} 


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

void merge (ElementType list[],ElementType sorted[],int L,int R,int RightEnd){
	int LeftEnd,temp,num;
	
	num=RightEnd-L+1;
	LeftEnd=R-1;
	temp=L;
	
	while (L<=LeftEnd && R<=RightEnd){
		if (sorted[L]<=sorted[R])
			list[temp++]=sorted[L++];
		else
			list[temp++]=sorted[R++];
	}
	if (L<=LeftEnd)
		while (L<=LeftEnd)
			list[temp++]=sorted[L++];
	else
		while (R<=RightEnd)
			list[temp++]=sorted[R++];
	for(i=0;i<num;i++,RightEnd--)
		sorted[RightEnd]=list[RightEnd];
}

void merge_pass (ElementType list[],ElementType sorted[],int N,int length){
	int i,j;
	for (i=0;i<=N-2*length;i+=2*length)
		merge(sorted,list,i,i+length,i+2*length-1);
	if (i+length<N)
		merge(sorted,list,i,i+length,N-1);
	else
		for (j=i;j<N;j++)
			list[j]=sorted[j];
}
