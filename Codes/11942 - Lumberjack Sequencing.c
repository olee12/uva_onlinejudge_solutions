#include<stdio.h>
int main()
{
    int t,i,j,ara[15],k;
    printf("Lumberjacks:\n");
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            for (i=0; i<10 ; i++ )
                scanf("%d",&ara[i]);
            j=1;
            for(i=0; i<9; i++)
            {
                if((ara[i]>ara[1+i])) j=1;
                else
                {
                    j=0;
                    break;
                }
            }
            for(i=0; i<9; i++)
            {
                if((ara[i]<ara[1+i])) k=1;
                else
                {

                    k=0;
                    break;
                }
            }

            if(j||k) printf("Ordered\n");
            else
                printf("Unordered\n");

        }
    }
    return 0;
}
