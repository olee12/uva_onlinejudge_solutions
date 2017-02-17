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
            printf("Case %d: Invalid\n",m);
        else if (a==b && b==c)
            printf("Case %d: Equilateral\n",m);
        else if(a!=b&b!=c&c!=a)
            printf("Case %d: Scalene\n",m);
        else
            printf("Case %d: Isosceles\n",m);

        m++;
        }
    }
    return 0;

}

