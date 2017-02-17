#include<stdio.h>
int main()
{
    int t,n,a,c,f=0;
    while(scanf("%d",&t)==1)
    {
        c=1;
        while(t--)
        {
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&a);
                if(a>f) f=a;
            }
            printf("Case %d: %d\n",c++,f);
            f=0;
        }
    }
    return 0;
}
