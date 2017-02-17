#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
int dp[700][700];
int coin[100];
int n;
int func(int sum)
{
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i = 0; i<n; i++)
        for(int j = sum; j>=0; j--)
            for(int k = sum; k>=0; k--)
                if(dp[j][k]==1)
                {

                    dp[j+coin[i]][k]=1;
                    dp[j][k+coin[i]]=1;
                }

    int res = 1<<30;
    int a,b,c;
    int ta,tb,tc;
    int a_lt = sum/3+1;
    int b_lt = a_lt*2;
    for(int i = 0; i<a_lt; i++)
        for(int j= i; j<b_lt; j++)
        {
            if(dp[i][j]==1)
            {
                a = i,b =j,c = sum-i-j;
                int p = abs(a-b)+abs(b-c)+abs(c-a);
                if(p<res)
                {
                    ta = a;
                    tb = b;
                    tc = c;
                    res = p;
                }
            }

        }
    // cout<<ta<<' '<<tb<<' '<<tc<<endl;
    int mx = -1;
    if(ta>mx) mx = ta;
    if(tb>mx) mx = tb;
    if(tc>mx) mx = tc;
    int mn = 10000000;
    if(ta<mn) mn = ta;
    if(tb<mn) mn = tb;
    if(tc<mn) mn = tc;

    return mx - mn;

}

int main()
{
    int sum = 0;
    int test;
    sf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {
        sf("%d",&n);
        sum = 0;
        for(int i = 0; i<n; i++)
        {
            sf("%d",coin+i);
            sum+=coin[i];
        }
        pf("Case %d: %d\n",cas,func(sum));

    }
    return 0;

}

