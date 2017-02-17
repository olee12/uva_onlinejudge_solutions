#include<stdio.h>
int main()
{
    signed long int a,b,c;
    int n,m;

    while(scanf("%d",&n)==1)
    {
        m = 1;
        while(m<=n){

        scanf("%ld %ld %ld",&a,&b,&c);


        if((((a+b)<=c)|((b+c)<=a)|((a+c)<=b)))
            printf("Wrong!!\n");
        else
            printf("OK\n");
        m++;
        }
    }
    return 0;
}
