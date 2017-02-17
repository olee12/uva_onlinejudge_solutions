#include<stdio.h>
int main()
{
    int w[55];
    int t,n,i,h=0,l=0,p;
    while(scanf("%d",&t)==1&&t)
    {
        for(p=1; p<=t; p++)
        {
            scanf("%d",&n);
            for(i=0; i<n; i++)
                scanf("%d",&w[i]);
            for(i=0; i<n-1; i++)
            {
                if(w[i]>w[i+1])
                    h++;
                else if(w[i]<w[i+1])
                    l++;
            }
            printf("Case %d: %d %d\n",p,l,h);
            h=0;
            l=0;
        }
    }
    return 0;
}
