#include<stdio.h>
int main()
{
    int ara[55];
    int i,n,j=0,l=0,sum=0;
    while(scanf("%d",&n)==1)
    {
        l++;
        if(!n) break;
        for(i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
            sum+=ara[i];
        }
        sum/=n;
        for(i=0; i<n; i++)
            if(ara[i]>sum)
                while(ara[i]!=sum)
                {
                    ara[i]-=1;
                    j++;
                }
            printf("Set #%d\nThe minimum number of moves is %d.\n",l,j);
            printf("\n");
        sum=0,j=0;
    }
    return 0;

}
