#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int prime[]= {2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,53};
int fib[100];
map<int,long long > ara;
void divisor(int num,int n)
{
    for(int i = 0; i<17; i++)
    {
        int cnt = 0;
        if(num%prime[i]==0)
        {
            while(num%prime[i]==0)
            {
                cnt++;
                num/=prime[i];
            }
            ara[prime[i]] +=(fib[n]*cnt);
        }
    }
    if(num> 1)
    {
        ara[num] +=(fib[n]*1);
    }
}
int main()
{
    fib[0]=0;
    fib[1] = 1;
    for(int i = 2; i<=40; i++)
        fib[i]=fib[i-1]+fib[i-2];

    int n, a,b;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&n,&a,&b);
        ara.clear();
        divisor(b,n);
        divisor(a,n-1);
        map<int,long long > :: iterator it = ara.begin();
        for(; it!=ara.end(); it++)
        {
            printf("%d %lld\n",it->first,it->second);
        }
        puts("");

    }
    return 0;
}

