#include<stdio.h>
int main()
{
    unsigned long long int i=1,j=9,k=4,l=0;

    for(i=1; i<=j; i++)
    {
        l=(((k*k)-2) % 2047);
        printf("%d ",l);
        k=l;
    }
    return 0;
}
