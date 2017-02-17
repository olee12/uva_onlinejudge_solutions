#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int dp[100][100];
int nCr(int n, int r)
{

    if(n == r) return 1;
    if(r == 1) return n;
    int& res = dp[n][r];
    if(res != -1) return res;
    res = nCr(n - 1, r - 1) + nCr(n - 1, r);
    return res;
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    memset(dp, -1, sizeof dp);
    nCr(n, r);
    while(scanf("%d %d", &n, &r) == 2)
    {
        // memset(dp,-1,sizeof dp);
        printf("n = %d , r = %d ... res nCr = %d\n", n, r, dp[n][r]);

    }
}
