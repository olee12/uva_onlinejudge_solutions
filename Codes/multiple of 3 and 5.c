#include<stdio.h>
int main()
{
    int a=1,b,sum=0,d;
    for(a=1; a<1000; a++)
    {
        if(((a%3) == 0) || ((a%5)==0))
        {

            sum+=a;
        }
    }

    printf("%d",sum);
    return 0;
}
