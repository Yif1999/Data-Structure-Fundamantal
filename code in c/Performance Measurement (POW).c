#include<stdio.h>
#include<math.h>
#include<time.h>

double result;		//定义全局变量，用于存储最终计算结果 

/*线性算法 T(N)=O(N) */ 
double Algorithm_One (long x,long n){		

	result=x;
	if (n==0) 		//如果指数为0则返回1并跳出函数 
		return 1;
	for(long i=0;i<n-1;i++){		//如果指数大于0则进入循环 
		result=result*x;		//循环相乘计算结果 
	}
	return result;		//返回结果 
	
}

/*迭代算法 T(N)=O(logN)*/ 
double Algorithm_Two (long x,long n){		

	if (n==0)		//如果指数为0则返回1并跳出函数 
		return 1;
	if (n==1)		//如果指数为1则返回原值并跳出函数 
		return x;
		
	long p,q=1;		//定义循环控制变量 
	double temp=1;		// 定义临时结果寄存变量 
    p=n;q=1;		//初始化循环控制变量 
    while(p>0){		//进入循环计算所需的循环控制变量q的值 
        p/=2;q*=2;
    }
    p=n;
    while(q>1){		//进入循环，迭代计算结果 
        q/=2;
        temp=temp*temp;
        if (p>=q){		//等价于判定指数为奇的情况 
			temp*=x;
			p-=q;
		}
	}	
	return temp;		//返回计算结果 

}

/*递归算法 T(N)=O(logN)*/ 
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
/*注：由于某种原因该算法在n大于某一值时无法输出正确的结果，但对于算法3输出结果并非我们的首要任务，在此只考虑分析其复杂度即可*/ 

int main(){
	clock_t start,stop;		//时钟变量定义 
	double total,duration,ticks=0;		//total为运行总时间，duration为单轮运行时间，ticks为打点数 
	long X,N,k=0;
	
	while(1){		//进入循环 ，方便测试者在程序同一次运行过程中读入多组数据进行试验 
		scanf("%ld %ld",&X,&N);		//读入数据 
		
		for(int j=1;j<=3;j++){		//三轮循环分别调用三种算法的函数 
			printf("\nAlgorithm%d:\n",j);
		
			start=clock();		//记录开始时间的点数 
			
			while(ticks<10){		//为保证精度，循环调用函数 ，直到所经过时间的打点数大于10 
				switch (j){		//选择调用的函数，j为控制变量，三轮循环中分别调用三种算法的函数 
					case 1:result=Algorithm_One(X,N); break;
					case 2:result=Algorithm_Two(X,N); break;
					case 3:result=Algorithm_Three(X,N); break;
				}
				stop=clock();		//记录停止时间的点数 
				ticks=stop-start;		//计算持续时间中的打点数 
				k++;		//累加器，记录同一种算法运行的次数 
			}
	
			total=((double)(stop-start))/CLK_TCK;		//计算同种算法运行总时间 
			duration=((double)(stop-start))/CLK_TCK/k;		//计算算法单词运行时间 
			//以下为打印输出部分 
			printf("result=%e\n",result);
			printf("iterations(K)=%ld\n",k);
			printf("ticks=%.0lf\n",ticks);
			printf("total time=%.3e\n",total);
			printf("duration=%.3e\n\n",duration);
			//重置条件变量k与ticks 
			k=0;ticks=0;	
		}
	}
	
	return 0;
}
