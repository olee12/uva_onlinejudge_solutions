#include<cstdio>
#include<cstring>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
int cost[1005];
int weghit[1005];
int cap, n;
int dp[1005][50];
int func(int i, int w)
{
    if(w > cap) return 0;
    int& res = dp[i][w];
    if(res != -1) return res;
    if(i == n + 1) return 0;
    int profit1 = 0, profit2 = 0;
    if(w + weghit[i] <= cap) profit1 = cost[i] + func(i + 1, w + weghit[i]);
    else profit1 = 0;
    profit2 = func(i + 1, w);
    return res = max(profit1, profit2);
}
int main()
{
   // freopen("input.txt", "r", stdin);
    int w, c;
    int test;
    int g;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", cost + i, weghit + i);
        }
        int sum = 0;
        scanf("%d", &g);

        for(int i = 0; i < g; i++)
        {
            scanf("%d",&cap);

            memset(dp, -1, sizeof dp);
            sum += func(1, 0);
            //printf("max profit : %d\n",func(1,0));
        }
        printf("%d\n", sum);
    }
    return 0;
}
