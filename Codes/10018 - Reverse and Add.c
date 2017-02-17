#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *add(char *n1,char *n2);
char *strdup(const char *s);
int pal(char *n1);
char *strrevv(char *s);
int main()
{
    char n1[100],*rev,*res,*n2,*n3;

    int t,i,j,c,k;
    while(scanf("%d",&t)==1)
    {

        while(t--)
        {
            c=1;
            scanf(" %s",&n1);
            n2=n1;
            while(1)
            {
                n3=strdup(n2);
                rev=strrevv(n2);
                res=add(n3,rev);
                if(1 == pal(res))
                {
                    break;
                }
                n2=res;
                c++;
                if(c==1000)
                    break;
            }

            if(c==1000)
                break;
            else
                printf("%d %s\n",c,res);
        }
    }
    return 0;
}

char *add(char *n1,char *n2)
{
    char *res;
    int l1,l2,ml;
    l1=strlen(n1);
    l2=strlen(n2);
    ml=(l1>l2)?l1:l2;
    res=calloc(ml+2,sizeof(char));
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
    return res;
}
int pal(char *n1)
{
    int l,i,j,f=1;
    l=strlen(n1);
    for(i=0,j=l-1; i<=l/2; i++,j--)
    {
        if(n1[i]!=n1[j])
        {
            f=0;
            break;
        }
    }
    return f;
}
char *strdup(const char *s)
{
    char *a;
    if(a=malloc(strlen(s)))
        strcpy(a,s);
    return (a);
}

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
