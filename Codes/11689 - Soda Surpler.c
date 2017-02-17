
#include<stdio.h>
int main()
{
    int i,j=0,k,l,m,n=0;
    scanf("%d",&m);

        while(m--)
        {
            scanf("%d %d %d",&i,&k,&l);
            {
                i+=k;

                while(i>=l)
                    j+=i/l,i=(i/l)+(i%l);

                printf("%d\n",j);
                j=0;
            }
        }

    return 0;
}
