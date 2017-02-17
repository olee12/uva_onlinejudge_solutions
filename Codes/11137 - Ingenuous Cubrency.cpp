#include<cstdio>
#include<cstdlib>
#include<iterator>
#include<iostream>
using namespace std;
typedef long long ll;
int coin[24];
ll dp[24][10002];
ll func(int i,int amount)
{
    if(i>21) {
        if(amount==0) return 1ll;
        return 0;
    }
    if(amount==0) return 1ll;
    ll& res = dp[i][amount];
    if(res!=-1) return res;
    ll ret1=0,ret2=0;
    if(amount-coin[i] >=0) ret1 = func(i,amount-coin[i]);
    ret2 = func(i+1,amount);
    res = ret2+ret1;
    return res;
}
#include<cstring>
int main()
{
    for(int i = 1;i<=21;i++) coin[i] = i*i*i;
    int money;
    memset(dp,-1,sizeof dp);
    while(scanf("%d",&money)==1)
    {
        printf("%lld\n",func(1,money));
    }
    return 0;
}
