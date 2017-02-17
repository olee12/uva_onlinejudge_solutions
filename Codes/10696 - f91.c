#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d",&n)==1&&n)
    {
        m=n;
        if(n<=100)
        {
            while(n<=100)
            {
                n+=11;
                if(n>=101)
                {
                    n-=10;

                }
            }
            printf("f91(%d) = %d\n",m,n-10);
        }

        else
            printf("f91(%d) = %d\n",m,n-10);

    }
    return 0;
}
