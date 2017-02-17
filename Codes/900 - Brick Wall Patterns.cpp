#include<cstdio>
#include<cmath>
#include<iostream>
long long int fib[100];

int main()
{
    fib[0]=1;
    fib[1]=1;
    fib[2]=2;
    fib[3]=3;
    int i,j,k;
    for(i=4; i<55; i++) fib[i]=fib[i-1]+fib[i-2];
    int num;
    while(scanf("%d",&num)&&num)
    {
        printf("%lld\n",fib[num]);
    }
    return 0;
}
