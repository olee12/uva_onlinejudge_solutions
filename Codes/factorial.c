#include<stdio.h>
int main()
{
    int i,n,sum=1;
    printf("Enter a number: ");
    while((scanf("%d",&n)==1))
    {
        if(n==0)
            printf("%d\n",1);
        else
        {
            for(i=1; i<=n; i++)
            {
                sum *= i;

            }
            if(n>12)
            {
                printf("ERROR\n");
                sum = 1;
            }
            else
            {
                printf("%d \n",sum);
                sum = 1;
            }
            printf("Enter a number: ");

        }

    }
}
