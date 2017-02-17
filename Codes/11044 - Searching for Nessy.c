#include<stdio.h>
int main()
{
    int c,m,n;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d %d",&n,&m);
        printf("%d\n",(n/3)*(m/3));
    }

    return 0;
}
