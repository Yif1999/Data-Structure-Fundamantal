#include<stdio.h>
#include<stdlib.h>
#define maxtree 10
#define elementtype char
#define tree int
#define null -1

struct treenode{
    elementtype element;
    tree left;
    tree right;
}t1[maxtree],t2[maxtree];

tree buildtree(struct treenode t[]);
int isomorphic(tree r1,tree r2);

int main(){
    tree r1,r2;

    r1=buildtree(t1);
    r2=buildtree(t2);
    if (isomorphic(r1,r2))
        printf("Yes\n");
    else
        printf ("No\n");

    return 0;
}

tree buildtree(struct treenode t[]){
    int n,i,root=-1,check[maxtree];
    char cl,cr;
    scanf("%d\n",&n);
    if (n){
        for(i=0;i<n;i++) check[i]=0;
        for (i=0;i<n;i++){
            scanf("%c %c %c\n",&t[i].element,&cl,&cr);
            if (cl!='-'){
                t[i].left=cl-'0';
                check[t[i].left]=1;
            }
            else 
                t[i].left=null;
            if (cr!='-'){
                t[i].right=cr-'0';
                check[t[i].right]=1;
            }
            else 
                t[i].right=null;
        }
        for(i=0;i<n;i++)
            if (!check[i]) break;
        root=i;
    }
    return root;
}

int isomorphic(tree r1,tree r2){
    if (r1==null && r2==null)
        return 1;
    if ((r1==null && r2!=null) || (r1!=null && r2==null))
        return 0;
    if (t1[r1].element!=t2[r2].element)
        return 0;
    if (t1[r1].left==null && t2[r2].left==null)
        return isomorphic(t1[r1].right,t2[r2].right);
    if ((t1[r1].left!=null && t2[r2].left!=null) && (t1[t1[r1].left].element==t2[t2[r2].left].element))
        return (isomorphic(t1[r1].left,t2[r2].left) && isomorphic(t1[r1].right,t2[r2].right));
    else
        return (isomorphic(t1[r1].left,t2[r2].right) && isomorphic(t1[r1].right,t2[r2].left));
}
