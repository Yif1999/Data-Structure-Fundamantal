#include<stdio.h>
#include<math.h>
#include<time.h>

double result;		//����ȫ�ֱ��������ڴ洢���ռ����� 

/*�����㷨 T(N)=O(N) */ 
double Algorithm_One (long x,long n){		

	result=x;
	if (n==0) 		//���ָ��Ϊ0�򷵻�1���������� 
		return 1;
	for(long i=0;i<n-1;i++){		//���ָ������0�����ѭ�� 
		result=result*x;		//ѭ����˼����� 
	}
	return result;		//���ؽ�� 
	
}

/*�����㷨 T(N)=O(logN)*/ 
double Algorithm_Two (long x,long n){		

	if (n==0)		//���ָ��Ϊ0�򷵻�1���������� 
		return 1;
	if (n==1)		//���ָ��Ϊ1�򷵻�ԭֵ���������� 
		return x;
		
	long p,q=1;		//����ѭ�����Ʊ��� 
	double temp=1;		// ������ʱ����Ĵ���� 
    p=n;q=1;		//��ʼ��ѭ�����Ʊ��� 
    while(p>0){		//����ѭ�����������ѭ�����Ʊ���q��ֵ 
        p/=2;q*=2;
    }
    p=n;
    while(q>1){		//����ѭ�������������� 
        q/=2;
        temp=temp*temp;
        if (p>=q){		//�ȼ����ж�ָ��Ϊ������ 
			temp*=x;
			p-=q;
		}
	}	
	return temp;		//���ؼ����� 

}

/*�ݹ��㷨 T(N)=O(logN)*/ 
double Algorithm_Three (long x,long n){		

	if (n==0)
		return 1;
	if (n==1)
		return x;
	if (n%2==0)
		return Algorithm_Three(x*x,n/2);
	else
		return Algorithm_Three(x*x,n/2)*x;
		
}
/*ע������ĳ��ԭ����㷨��n����ĳһֵʱ�޷������ȷ�Ľ�����������㷨3�������������ǵ���Ҫ�����ڴ�ֻ���Ƿ����临�Ӷȼ���*/ 

int main(){
	clock_t start,stop;		//ʱ�ӱ������� 
	double total,duration,ticks=0;		//totalΪ������ʱ�䣬durationΪ��������ʱ�䣬ticksΪ����� 
	long X,N,k=0;
	
	while(1){		//����ѭ�� ������������ڳ���ͬһ�����й����ж���������ݽ������� 
		scanf("%ld %ld",&X,&N);		//�������� 
		
		for(int j=1;j<=3;j++){		//����ѭ���ֱ���������㷨�ĺ��� 
			printf("\nAlgorithm%d:\n",j);
		
			start=clock();		//��¼��ʼʱ��ĵ��� 
			
			while(ticks<10){		//Ϊ��֤���ȣ�ѭ�����ú��� ��ֱ��������ʱ��Ĵ��������10 
				switch (j){		//ѡ����õĺ�����jΪ���Ʊ���������ѭ���зֱ���������㷨�ĺ��� 
					case 1:result=Algorithm_One(X,N); break;
					case 2:result=Algorithm_Two(X,N); break;
					case 3:result=Algorithm_Three(X,N); break;
				}
				stop=clock();		//��¼ֹͣʱ��ĵ��� 
				ticks=stop-start;		//�������ʱ���еĴ���� 
				k++;		//�ۼ�������¼ͬһ���㷨���еĴ��� 
			}
	
			total=((double)(stop-start))/CLK_TCK;		//����ͬ���㷨������ʱ�� 
			duration=((double)(stop-start))/CLK_TCK/k;		//�����㷨��������ʱ�� 
			//����Ϊ��ӡ������� 
			printf("result=%e\n",result);
			printf("iterations(K)=%ld\n",k);
			printf("ticks=%.0lf\n",ticks);
			printf("total time=%.3e\n",total);
			printf("duration=%.3e\n\n",duration);
			//������������k��ticks 
			k=0;ticks=0;	
		}
	}
	
	return 0;
}
