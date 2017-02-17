#include<stdio.h>
int main()
{
    int ara[20];
    int t,n,i,j,c=0,temp;
    while(scanf("%d",&t)==1)
    {
        c=0;
        while(t--)
        {
            c++;
            scanf("%d",&n);
            for(i=0; i<n; i++)
                scanf("%d",&ara[i]);
            for(i=0; i<n-1; i++)
                for(j=i+1; j<n; j++)
                    if(ara[i]>ara[j]) temp=ara[i],ara[i]=ara[j],ara[j]=temp;
            printf("Case %d: %d\n",c,ara[n/2]);

        }
    }
    return 0;
}
