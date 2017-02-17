/*#include<stdio.h>
#include<stdlib.h>
int sort(const void *p,const void *q);
int main()
{
    unsigned char* ara;

    ara = (unsigned char*)malloc(2000000);

    int i,j,k,l,m,n;
    while(scanf("%d",&n)==1&&n)
    {
        for(i=0; i<n; i++)
            scanf(" %d",&ara[i]);
        qsort(ara,n,sizeof(char),sort);
        for(i=0; i<n; i++) printf("%d ",ara[i]);
        printf("\n");
    }
    return 0;
}
int sort(const void *p,const void *q)
{
    char *a;
    char *b;
    a = (char *)p;
    b = (char *)q;
    return *a-*b;
}*/


#include <stdio.h>
#include <stdlib.h>
unsigned char* ppl;
int comp(const void* a,const void*b)
{
    return *(char*)a-*(char*)b;
}
int main()
{
    int top,n;
    ppl = (unsigned char*) malloc(2000000);
    while(scanf("%u",&n)&&n)
    {
        top = 0;
        while(n-->0)   scanf("%d",&ppl[top++]);
        qsort(ppl,top,sizeof(char),comp);
        for(n=0; n<top-1; n++)            printf("%d ",ppl[n]);
        printf("%d\n",ppl[top-1]);
    }
    return 0;

}
