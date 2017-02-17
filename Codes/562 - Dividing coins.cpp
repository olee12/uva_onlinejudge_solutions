#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int v[120];
int c[110][25100];
int main()
{
    int t,n,sum,avg;

    scanf("%d",&t);
    int i,j,k,w;
    while(t--)
    {

        scanf("%d",&n);
        sum=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&v[i]);
            sum+=v[i];
        }
        avg=sum/2;
        for(i=0; i<=n; i++) c[i][0]=0;
        for(i=0; i<=avg; i++) c[0][i]=0;
        for(i=1; i<=n; i++)
        {
            for(w=1; w<=avg; w++)
            {
                c[i][w]=c[i-1][w];
                if(w>=v[i])
                {
                    c[i][w]=max(c[i-1][w],c[i-1][w-v[i]]+v[i]);
                }
            }
        }
        printf("%d\n",sum - c[n][avg]*2);
    }
    return 0;
}
