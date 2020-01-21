ElementType EvalPostfix( char *expr){
	int i=0,count_opa=0;
	double operands[Max_Expr+1];
	double result=Infinity,num;
	int t,k;
	
	while (expr[i]!='\0'){
		if (expr[i]>='0' && expr[i]<='9'){
			num=expr[i]-'0';i++;k=-1;
			while (expr[i]!=' ' && expr[i]!='\0'){
				if (expr[i]=='.'){
					k++;i++;
                }
				else{
                    if(k==-1){
                        num=10*num+expr[i]-'0';
						i++;
                    }
                    else{
                        num=10*num+expr[i]-'0';		
					    i++;k++;
                    }
                } 

			}
			for (t=0;t<k;t++){
				num*=0.1;
			}
			operands[count_opa]=num;
			count_opa++;
		}
		else if (expr[i]=='-' && expr[i+1]>='0' && expr[i+1]<='9'){
			i++;
			if (expr[i]>='0' && expr[i]<='9'){
			num=expr[i]-'0';i++;k=-1;
			while (expr[i]!=' ' && expr[i]!='\0'){
				if (expr[i]=='.'){
					k++;i++;
                }
				else{
                    if(k==-1){
                        num=10*num+expr[i]-'0';
						i++;
                    }
                    else{
                        num=10*num+expr[i]-'0';		
					    i++;k++;
                    }
                } 

			}
			for (t=0;t<k;t++){
				num*=0.1;
			}
			num=0-num;
			operands[count_opa]=num;
			count_opa++;
			}
		}
		else if (expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/'){
			if (count_opa-1>0){
				if (expr[i]=='+')
					operands[count_opa-2]=operands[count_opa-2]+operands[count_opa-1];
				else if (expr[i]=='-')
					operands[count_opa-2]=operands[count_opa-2]-operands[count_opa-1];
				else if (expr[i]=='*')
					operands[count_opa-2]=operands[count_opa-2]*operands[count_opa-1];
				else if (expr[i]=='/'){
					if (operands[count_opa-1]==0) return Infinity;
					operands[count_opa-2]=operands[count_opa-2]/operands[count_opa-1];					
				}
				if (count_opa-2==0)
					result=operands[count_opa-2];
				count_opa--;
				i++;
			}
			else return Infinity;
		}
		else if (expr[i]==' ') i++;
	}
	
	if (count_opa==1) return operands[0];
	if (count_opa==2) return Infinity;
	
	return result;
	
}
