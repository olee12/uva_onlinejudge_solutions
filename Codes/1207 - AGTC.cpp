//============================================================================
// Name        : 1207.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int, int> mii;
typedef long long ll;

#define sf scanf
#define pf printf
#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
#define M 1505
char str1[M];
char str2[M];
int len1, len2;
int dp[M][M];
int func(int i, int j)
{
	if (i < 0 || j < 0)
	{
		return i==j?0:1050;
	}
	int& res = dp[i][j];
	if (res != -1)
		return res;

	int p1 = 1005, p2 = 1005, p3 = 1005, p4 = 1005;
	if (str1[i] == str2[j])
	{
		p1 = func(i - 1, j - 1);
		res = p1;
	}
	else
	{
		p2 = func(i - 1, j);
		p3 = func(i, j - 1);
		p4 = func(i - 1, j - 1);
		res = min(min(p2, p3), p4) + 1;
	}
	return res;
}
int main()
{
	int i;
	while (cin >> len1 >> str1 >> len2 >> str2)
	{
		memset(dp, -1, sizeof dp);
		/*
		for (int i = 0; i <= len1; i++)
			dp[i][0] = i;
		for (int i = 0; i <= len2; i++)
			dp[0][i] = i;
		for (int i = 1; i <= len1; i++)
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i - 1] == str2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
				{
					dp[i][j] = min(dp[i - 1][j - 1],
							min(dp[i][j - 1], dp[i - 1][j])) + 1;
				}
			}
*/
		cout << func(len1-1,len2-1) << endl;
	}
	return 0;
}
