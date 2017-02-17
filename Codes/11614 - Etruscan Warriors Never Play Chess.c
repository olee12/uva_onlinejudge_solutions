/*#include<stdio.h>
int main()
{

    long long int n,c=0,i,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        m=n;
        for (i=1; i<=n; i++)
        {
            m -= i;
            c++;
            if(m<=0) break;
        }
        if(m<0) printf("%lld\n",c-1);
        else printf("%lld\n",c);
        c=0;
    }
    return 0;
}*/
/*
# include <stdio.h>
# include <math.h>
int main()
{
    long long i,n,t,sum;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        sum = (sqrt(1+8*n)-1)/2;
        printf("%lld\n",sum);
    }
    return 0;
}
*/
#include<stdio.h>
#include<math.h>
int main()
{
   long long int n,a,t;
    scanf("%lld",&t);
    {
        while(t--)
        {
            scanf("%lld",&a);

            n=floor((sqrt(2.0*(double)a +(.25))) - .5);
            printf("%lld\n",n);

        }
    }
    return 0;
}
