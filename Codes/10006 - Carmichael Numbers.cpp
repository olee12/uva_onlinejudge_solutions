#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#define MAX 65000
using namespace std;
bool flag[MAX+2];

void sieve()
{
    flag[0]=1;
    flag[1]=1;
    flag[2]=0;
    int i,j,k;

    for(i=4; i<=MAX; i+=2)
        flag[i]=1;
    for(i=3; i<=MAX; i+=2)
    {
        if(!flag[i])
        {

            if(MAX/i=>i)
            {
                k=i*2;
                for(j=i*i; j<=MAX; j+=k)
                {
                    flag[j]=1;
                }
            }

        }
    }
}

unsigned int mpower(int a,int n,int d)
{
    if(n==0) return 1;
    else if(!(n%2)) return ((mpower(a,n/2,d)*mpower(a,n/2,d))%d);
    else return ((((mpower(a,n/2,d)*mpower(a,n/2,d))%d)*(a%d))%d);
}
unsigned int powermod(int a, int n, int d)
{
    unsigned int x;

    if (n == 0)
        return 1;
    if (n == 1)
        return a % d;

    x = powermod(a, n / 2, d);
    x = x * x % d;
    if (n % 2 == 0)
        return x;
    else
        return x * a % d;
}
int fermat(int n)
{
    int i;

    for (i = 2; i < n; i++)
        if (mpower(i, n, n) != i)
            return false;

    return true;
}
int main()
{
    sieve();
    int n;
    int t;
    while(scanf("%d",&n) && n)
    {
        if(flag[n] && fermat(n))
        {
            printf("The number %d is a Carmichael number.\n",n);

        }
        else printf("%d is normal.\n",n);
    }
    return 0;
}
