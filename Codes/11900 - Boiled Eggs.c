#include<stdio.h>
int main()
{
    int ara[40],t,l;
    scanf("%d",&t);
    for(l=1; l<=t; l++)
    {int n,p,q,i,j=0,k=0;
        scanf("%d %d %d",&n,&p,&q);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
            if((i<=p) &&((k+ara[i])<=q))
            {
                j=i;
                k+=ara[i];
            }
        }
         printf("Case %d: %d\n",l,j);
    }
    return 0;
}


/*#include <stdio.h>
int main()
{
    int T,j,a[40];
    scanf("%d",&T);
    for(j=1; j<=T; j++)
    {
        int n,p,m,i,sum=0,r=0;
        scanf("%d %d %d",&n,&p,&m);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if((i<=p )&&((sum+a[i])<=m))
            {
                r=i;
                sum+=a[i];
            }
        }
        printf("Case %d: %d\n",j,r);
    }
    return 0;
}

*/
