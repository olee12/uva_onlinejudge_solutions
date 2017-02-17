#include<stdio.h>
int main()
{
    long int n,sum;
    while (scanf("%ld",&n)==1 && n!=0)
    {
        if (n<10)
            printf("%ld\n",n);
        if (n>9)
        {
            while (n>9)
            {
                sum=0;
                while (n>0 )
                {
                    sum=sum+n%10;
                    n=n/10;
                }
                n=sum;
            }
            printf("%ld\n",sum);
        }
    }
    return 0;
}
