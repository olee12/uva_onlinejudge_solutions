#include<stdio.h>
int main()
{
    int i,j,k=1,l=0,m=1;

    while((scanf("%d",&j)==1)&&(j>=1))
    {




        for(k=1; j>k;)
        {
            k = k*2;

            l++;
        }
        printf("Case %d: %d\n",m,l);
        k=1;
        m++;
        l=0;

    }
    return 0;


}
