#include<stdio.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,f=0,ara[15];
    int i,j,k,l,m,o;
    while(scanf("%d",&n) && n)
    {
        for(int i = 0; i<n; i++) scanf("%d",&ara[i]);
        if(f)puts("");f=1;
        for(i = 0; i<n; i++)
            for(j=i+1; j<n; j++)
                for(k = j+1; k<n; k++)
                    for(l = k+1; l<n; l++)
                        for(m=l+1; m<n; m++)
                            for(o = m+1; o<n; o++)
                            {
                                printf("%d %d %d %d %d %d\n",ara[i],ara[j],ara[k],ara[l],ara[m],ara[o]);
                            }


    }
    return 0;
}

