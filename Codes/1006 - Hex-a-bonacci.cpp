#include<cstdio>
#include<cstring>
#define M 10005
typedef unsigned long long ll;
ll a, b, c, d, e, f;
ll dp[M];
ll fn( int n )
{
   // if(n<0) return 0;
   // int& val = dp[n];
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    if(dp[n]!=-1) return dp[n];
    dp[n] =  ( fn(n - 1) + fn(n - 2) + fn(n - 3) + fn(n - 4) + fn(n - 5) + fn(n - 6) )% 10000007;
    return dp[n];
}
int main()
{
  //  freopen("input.txt","r",stdin);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- )
    {
        memset(dp,-1,sizeof dp);
        scanf("%llu %llu %lld %llu %llu %llu %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %llu\n", ++caseno, fn(n) % 10000007 );
    }
    return 0;
}
