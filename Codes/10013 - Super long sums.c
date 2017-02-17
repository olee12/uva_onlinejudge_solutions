#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *add(char *n1,char *n2);
int main()
{
    char n1[1000005],n2[1000005],*res;
    int t,n;
    int i;
    scanf("%d",&t);

        while(t--)
        {


            scanf("%d",&n);
            for(i=0; i<n; i++)
            {
                scanf(" %c %c",&n1[i],&n2[i]);
            }


            n1[i]='\0';
            n2[i]='\0';
            res=add(n1,n2);
            printf("%s",res);
            if(t) printf("\n\n");
            else printf("\n");

        }

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
