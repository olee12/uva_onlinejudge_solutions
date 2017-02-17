#include<cstdio>
#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
#include<cstdlib>
using namespace std;
#define MAX 1000000
int flag[MAX];
int prime[78498]={0};
int c=0;

void sieve()
{
    prime[c++]=2;
    register int i,j,add;
    for(i=4; i <=  MAX; i+=2) flag[i]=1;
    for(i=3; i<=MAX; i+=2)
    {
        if(!flag[i])
        {
            prime[c++]=i;
            if(MAX/i>i)
            {
                add=i<<1;
                for(j=i*i; j<=MAX; j+=add) flag[j]=1;
            }
        }
    }
}


int main()
{
    sieve();
    prime[0]=2;

     long long  int num;
    long long  int large,count;
    int i,t;
    int test;
    while(scanf("%lld",&num))

    {
        if(num<0) break;


        long long  int lim=(unsigned long long )sqrt(num);
        for(i=0; i<c && prime[i]<=lim; i++)
        {
            while(num%prime[i]==0)
            {
                count++;
                test++;
                large=prime[i];
                num/=prime[i];
                printf("    %d\n",prime[i]);
            }

        }
        if(num>1) printf("    %lld\n",num);

        printf("\n");
    }
    return 0;
}
