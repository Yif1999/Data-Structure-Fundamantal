#include <stdio.h>
#include <stdlib.h>
int main(){
    void *p;
    int count=0;
    while(p=malloc(100*1024*1024)){
        count++;
    }
    printf("分配了%d00MB的空间",count);
    free(p);
    return 0;
}
