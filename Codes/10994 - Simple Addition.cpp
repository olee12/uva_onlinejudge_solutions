#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef  long long ll;
ll func(ll n)
{
    if(n<=0) return 0L;
    ll sum1=0,sum2=0;
    while(n)
    {
        ll mod = n % 10;
         n = n/10;
        sum1+= ((mod*(mod+1))/2);
        sum2+= n*45L;

    }
    return (sum1+sum2);
}
int main()
{
    ll p,q;
    while(scanf("%lld %lld",&p,&q) && p>=0 && q>=0)
    {
       // cout<<q<<' '<<p-1<<endl;;
        //cout<<func(q)<<' '<<func(p-1)<<'\n';
        printf("%lld\n",func(q)-func(p-1));
    }
    return 0;
}
