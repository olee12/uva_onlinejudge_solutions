#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *add(char *n1,char *n2);

char **fib;
int main()
{
    fib=calloc(5500,sizeof(char *));

    fib[0]="1";
    fib[1]="2";
    int i,j,k;
    for(i=2;i<=5000;i++)
        fib[i]=add(fib[i-1],fib[i-2]);

    while(scanf("%d",&i)==1)
        printf("%s\n",fib[i]);

    return 0;
}


char *add(char *n1,char *n2)
{
    char *res;
    register l1,l2,ml;
    l1=strlen(n1);
    l2=strlen(n2);
    ml=(l1>l2)?l1:l2;
    res=calloc(ml+2,sizeof(char));
    register int a,b,s,t,i,j;
    for(i=ml,t=0,--l1,--l2;i>=0;i--,l1--,l2--)
    {
        a=(l1>=0)? n1[l1]-'0':0;
        b=(l2>=0)?n2[l2]-'0':0;
        s=a+b+t;
        t=s/10;
        res[i] = s-t*10+'0';

    }
    while(res[0]=='0'&& res[1]!=0) res++;
    return res;
}
