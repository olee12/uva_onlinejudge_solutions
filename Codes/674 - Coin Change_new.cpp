#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[5][7500];
int coin[] = {50, 25, 10, 5, 1};
int func(int i, int amount)
{
    if(i == 5)
    {
        return amount == 0 ? 1 : 0;
    }
    int& res = dp[i][amount];
    if(res != -1) return res;
  //  cout<<amount<<endl;
    int p1 = 0, p2 = 0;
    if(amount - coin[i] >= 0) p1 = func(i, amount - coin[i]);
   p2 = func(i + 1, amount);
    return res = p1+p2;

}
int main()
{
    int money;
    memset(dp,-1,sizeof dp);
    while(scanf("%d",&money)==1)
    {
        printf("%d\n",func(0,money));
    }
    return 0;
}
