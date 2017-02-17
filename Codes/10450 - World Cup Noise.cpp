#include<cstdio>
#include<cmath>
#include<iostream>
long long int fib[300];

int main()
{

    fib[1]=2;
    fib[2]=3;

    int i,j,k;
    for(i=3; i<=200; i++) fib[i]=fib[i-1]+fib[i-2];
    int num,t,cas;
    scanf("%d",&t);



            for(int j=1; j<=t; j++)
            {
                scanf(" %d",&num);
                printf("Scenario #%d:\n%lld\n\n",j,fib[num]);
            }


    return 0;
}

