#include<stdio.h>
int main()
{
    long int n,i;
    while(scanf("%ld",&n)==1)
    {
        if(n >= 0 && n <= 210000000)
        {
            i = (n*(n+1)/2)+1;
            printf("%ld\n",i);
        }
        else if(n < 0)
            break;
    }
    return 0;
}
