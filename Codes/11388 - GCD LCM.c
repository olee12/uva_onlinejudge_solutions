#include<stdio.h>

int main()
{
    int a,b,l,g,m,t,n;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            scanf("%d %d",&a,&b);
            if(b%a) printf("-1\n");
            else printf("%d %d\n",a,b);

        }
    }
    return 0;

}
