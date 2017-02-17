#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *add(char *n1,char *n2);
char *cross(char *n1,int b,int len);
char *multi(char *n1,char *n2);
int main()
{
    char *n1,*n2,*res="0";
    n1=(char*)calloc(10000,sizeof(char));
    n2=(char*)calloc(10000,sizeof(char));
    int f=0;
    n2="0";
    while(scanf("%s",n1)){
            if(!strcmp("0",n1)) break ;
        if(f) n2=res;f=1;
        res=add(n1,n2);

    }
    printf("%s\n",res);

    return 0;
}

char *add(char *n1,char *n2)
{
    char *res;
    register int  l1,l2,ml;
    l1=strlen(n1);
    l2=strlen(n2);
    ml=(l1>l2)?l1:l2;
    res=(char*)calloc(ml+2,sizeof(char));
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
char *multi(char *n1,char *n2)
{
    register int l1,l2;
    l1=strlen(n1);
    l2=strlen(n2);
    char *temp;
    char *res=(char*)calloc(2,sizeof(char));
    register int b,i;
    for(--l2,i=0;l2>=0;l2--,i++){
        b=n2[l2]-'0';
        temp = cross(n1,b,i);
        res= add(res,temp);


    }
    while(res[0]=='0'&&res[1]!=0) res++;
    return res;

}
char *cross(char *n1,int b,int len)
{
    register int ml=strlen(n1);
    len+=ml;
    char *res=(char*)calloc(len+2,sizeof(char));
    register int i,a,s,t;
    for(i=ml,t=0;i>0;i--){
        a=n1[i-1]-'0';
        s=a*b+t;
        res[i]=s-t*10+'0';


    }
    res[0]=t+'0';
    for(i=ml+1;i<=len;i++)
        res[i]='0';
    return res;
}
