#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a,b) a>b?b:a
int main()
{
    char a[1001];
    char b[1001];
    int i,j,k=0,l;
    int ara1[300];
    int ara2[300];
    while(gets(a))
    {
        gets(b);
        memset(ara1,0,sizeof ara1);
        memset(ara2,0,sizeof ara2);
        for(i=0;a[i];i++) ara1[a[i]]++;
        for(i=0;b[i];i++) ara2[b[i]]++;
        for(i=97;i<=122;i++) if(ara1[i] && ara2[i]){ k=min(ara1[i],ara2[i]);  for(j=0;j<k;j++) printf("%c",i);}
        printf("\n");

    }
    return 0;
}
