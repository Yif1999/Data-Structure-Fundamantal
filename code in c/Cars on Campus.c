#include<stdio.h>
#include<string.h>

struct car {
	char plate_number[8];
	int time;
	char status[4];
};

struct ParkTime {
	char plate_number[8];
	int park_time;
};

int cmp_id(struct car a,struct car b){
	int t=strcmp(a.plate_number,b.plate_number);
	while (t!=0)
		return t;
	return a.time-b.time;
}

void PercDown(struct car A[], int p, int N ){ 
    int parent, child;
    struct car temp;
    temp=A[p];
    for(parent=p; (parent*2+1)<N; parent=child){
        child=parent*2+1;
        if((child!=N-1) && (cmp_id(A[child],A[child+1])<0))
            child++;
        if(cmp_id(temp,A[child])>=0) break;
        else
            A[parent] = A[child];
    }
    A[parent]=temp;
}
 
void sort(struct car A[], int N ) {
    int i;
    struct car temp;
    for (i=N/2-1;i>=0;i--)
        PercDown(A,i,N);
      
    for (i=N-1;i>0;i--){
         temp=A[0];
         A[0]=A[i];
         A[i]=temp;
         PercDown(A,0,i);
     }
}

int main(){
	int N,K;
	scanf ("%d %d",&N,&K);
	struct car Car_data[N+1];
	int T[K+1];
	int i,j=0;
	for (i=0;i<N;i++){
		int hh,mm,ss;
		scanf ("%s %d:%d:%d %s",&Car_data[i].plate_number,&hh,&mm,&ss,&Car_data[i].status);
		Car_data[i].time=3600*hh+60*mm+ss;
	}
	sort(Car_data,N);
	for (i=0;i<K;i++){
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		T[i]=3600*hh+60*mm+ss;
	}
	struct ParkTime PT[N+1];
	int Num_car[24*3600]={0};
	for (i=0;i<N;i++){
		int t_in,t_out,delta=0,flag=0;
		while (strcmp(Car_data[i].plate_number,Car_data[i+1].plate_number)==0){
			if ((strcmp(Car_data[i].status,"in")==0) && (strcmp(Car_data[i+1].status,"in")!=0)){
				t_in=Car_data[i].time;
				Num_car[Car_data[i].time]+=1;
				t_out=Car_data[i+1].time;
				Num_car[Car_data[i+1].time]-=1;
				delta+=(t_out-t_in);
				flag=1;
			}
			i++;
		}
		if (flag){
			PT[j].park_time=delta;
			strcpy(PT[j].plate_number,Car_data[i-1].plate_number);
			j++;
		}		
	}
	
	int t=0,sum=0;
	for (i=0;i<K;i++){	
		for (;t<=T[i];t++){
			sum+=Num_car[t];
		}
		printf("%d\n",sum);		
	}
	
	int PtrToMax[N+1];
	int max_time=-1;
	for (i=0;i<j;i++){		
		if (PT[i].park_time>max_time){
			t=0;
			max_time=PT[i].park_time;
			PtrToMax[t++]=i;
		}
		else if (PT[i].park_time==max_time){
			PtrToMax[t++]=i;
		}
	}
	
	for (i=0;i<t;i++){
		printf("%s ",PT[PtrToMax[i]].plate_number);
	}
	
	printf("%02d:%02d:%02d",max_time/3600,max_time%3600/60,max_time%60);
	
	return 0; 
}
