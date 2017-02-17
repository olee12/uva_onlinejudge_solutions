#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int l,h;
    long long int count=0,sum=0,i,j,k,max=0,n;
    while(scanf("%lld %lld",&l,&h)==2 && l && h)
    {
        sum=0,max=0;
        k=0;
        if(l>h) l^=h^=l^=h;
        for(i=l; i<=h; i++)
        {
            n=i;
            count=0;
            while(1)
            {
                if(n%2 != 0) n = 3*n+1;
                else n/=2;
                count++;
                if(n==1) break;

            }
            if(count>k) sum=i,k=count;
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,h,sum,k);
    }
    return 0;
}
