#include<stdio.h>
int main()
{
    int t,l=0,i,j=1,c[55],n,temp;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d",&n);
            for(i=0; i<n; i++) scanf("%d",&c[i]);
            for(i=0; i<n-1; i++)
                for(j=i+1; j<n; j++)
                {
                    if(c[i]>c[j])
                    {
                        temp = c[i];
                        c[i]=c[j];
                        c[j]=temp;
                        l++;
                    }

                }
            printf("Optimal train swapping takes %d swaps.\n",l);
            l=0;
        }
    }
    return 0;
}
