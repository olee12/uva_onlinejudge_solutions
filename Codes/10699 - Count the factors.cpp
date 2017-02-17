#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAX=1001;
const int size = 1001;
int flag[MAX];
int prime[size];
int c;
void sieve();
int main()
{
    sieve();

    int n,m;
    register int i,j=0,k;
    while(scanf("%d",&n)==1 && n)
    {
        m=n;
        k=sqrt(n);

        for(i=0,j=0;i<c && prime[i] <=k; i++)
        {
            if(!(n%prime[i])){ j++;
            while(n%prime[i]==0)n/=prime[i];
            }
        }
        if(n>1) j++;
        printf("%d : %d\n",m,j);
    }
    return 0;
}
void sieve()
{
    register int i,j,add;
    prime[c++]=2;

    for(i=4; i<MAX; i+=2) flag[i]=1;
    for(i=3; i<MAX; i+=2)
        if(!flag[i])
        {
            prime[c++]=i;
            if(MAX/i>=i)
            {
                add=i*2;
                for(j=i*i; j<MAX; j+=add) flag[j]=1;
            }
        }
}
