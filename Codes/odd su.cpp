#include<stdio.h>
int main()
{
    int a,b,i,s,n,j=1;
    scanf("%d",&n);

    while(j<=n)
    {
        s=0;
        scanf("%d %d",&a,&b);
        if((a%2)==0)
        {


            i=a+1;
        }
        else
            i=a;
        while(i<=b)
        {
            s=s+i;
            i=i+2;
        }
        printf("case %d: %d\n",j,s);
        j++;

    }

    return 0;
}
