#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<sstream>
using namespace std;
int dp[22][205];
int cost[22];
int wegth[22];
int cap;
int n;
int func(int i, int w)
{
    if(w > cap) return 0;
    int& res = dp[i][w];
    if(res != -1) return res;
    if(i == n + 1) return 0;
    int profit1 = 0, profit2 = 0;
    if(w + wegth[i] <= cap) profit1 = wegth[i] + func(i + 1, w + wegth[i]);
    else profit1 = 0;
    profit2 = func(i + 1, w);
    return res = max(profit1, profit2);
}
int main()
{

    // freopen("input.txt","r",stdin);
    int test;
    int a;
    char str[500];
    scanf("%d", &test);
    getchar();
    while(test--)
    {

        //scanf("%d", &n);
        int sum = 0;
        int one;
        gets(str);
        stringstream ss(str);
        int cnt = 1;
        while(ss >> a)
        {
            wegth[cnt] = a;
            sum += wegth[cnt];
            cnt++;
        }
        n = cnt - 1;
        if(sum & 1)
        {
            printf("NO\n");
            continue;
        }
        memset(dp, -1, sizeof dp);
        cap = sum / 2;
        one = func(1, 0);
        //cout<<one<<endl;
        if(one == cap) puts("YES");
        else puts("NO");
    }
    return 0;
}
