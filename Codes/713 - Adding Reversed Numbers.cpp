#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char *strrevv(char *s)
{
    char *re;
    char *fo;
    char tmp;
    re=s;
    fo=s;
    while(*s)
        s++;
    while(fo<s)
    {
        tmp=*(--s);
        *s=*fo;
        *fo++=tmp;
    }
    return (re);
}

char *add(char *n1,char *n2)
{
    char *res;
    int l1,l2,ml;
    l1=strlen(n1);
    l2=strlen(n2);
    ml=(l1>l2)?l1:l2;
    res=(char*)calloc(ml+2,sizeof(char));
    int a,b,s,t,i,j;
    for(i=ml,t=0,--l1,--l2; i>=0; i--,l1--,l2--)
    {
        a=(l1>=0)? n1[l1]-'0':0;
        b=(l2>=0)?n2[l2]-'0':0;
        s=a+b+t;
        t=s/10;
        res[i] = s-t*10+'0';

    }

    while(res[0]=='0'&& res[1]!=0) res++;
    res = strrevv(res);
    while(res[0]=='0'&& res[1]!=0) res++;
    return res;
}
int main()
{
    int test;
    char *res;
    char num1[210];
    char num2[210];
    char *n1,*n2;
    scanf("%d",&test);
    while(test--){
        scanf("%s %s",num1,num2);
        n1=strrevv(num1);
        n2=strrevv(num2);
        res=add(n1,n2);
        cout<<res<<endl;
    }
    return 0;
}
