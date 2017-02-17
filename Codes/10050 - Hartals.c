/*#include<stdio.h>

#define N 3655
_Bool day[N];
int main()
{
    int p,n,t;

    register int i,j,w=0,x=0;
    int par[110];

    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d",&n,&p);
            for(i=0; i<p; i++) scanf("%d",&par[i]);
            for(i=0; i<p; i++)

                for(j=par[i]; j<=n; j+=par[i])
                    if ((j%7)!=6 && (j%7)!=0)

                    day[j]=1;

//            for(i=7; i<=n; i+=7)
//            {
//                day[i] = 1;
//                day[i-1] = 1;
//                x+=2;
//            }

            for(i=1; i<=n; i++) if(day[i]) w++;
            printf("op = %d\n",w);
            w=0,x=0;
            memset(day,0,n);

        }
    }
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
#define N 3655
_Bool day[N];
int main()
{
    int p,n,t;

    register int i,j,w=0;
    int par[110];

    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d",&n,&p);
            for(i=0; i<p; i++) scanf("%d",&par[i]);
            for(i=0; i<p; i++)
                for(j=par[i]; j<=n; j+=par[i])
                    if ((j%7)!=6 && (j%7)!=0)
                    day[j]=1;

            for(i=1; i<=n; i++) if(day[i]) w++;
            printf("%d\n",w);
            w=0;
            memset(day,0,N);

        }
    }
    return 0;
}

