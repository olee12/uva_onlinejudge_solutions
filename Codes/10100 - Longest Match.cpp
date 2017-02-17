//============================================================================
// Name        : 10100.cpp
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
#define M 1005
int dp[M][M];
map<string, int> name;
int ara1[M];
int ara2[M];
int n, m;
int xx;
void format(char *str, int& n, int ara[])
{
	n = 0;

	char tmp[1050];
	int j = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (isalnum(str[i]))
		{
			tmp[j++] = str[i];
		}
		else
		{
			if (j)
			{
				tmp[j] = '\0';
				j = 0;
				if (name.find(string(tmp)) == name.end())
					name[string(tmp)] = xx++;
				ara[n++] = name[string(tmp)];
			}

		}
	}
	if (j)
	{
		tmp[j] = '\0';
		if (name.find(string(tmp)) == name.end())
			name[string(tmp)] = xx++;
		ara[n++] = name[string(tmp)];
	}
	/*for (int i = 0; i < n; i++)
	 {
	 if (i)
	 pf(" ");
	 pf("%d", ara[i]);
	 }*/
	//puts("");
}

int func(int i, int j)
{

	if (i == n || j == m)
		return 0;

	int& res = dp[i][j];
	if (res != -1)
		return res;
	int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

	if (ara1[i] == ara2[j])
	{
		p1 = func(i + 1, j + 1) + 1;
	}

	p2 = func(i, j + 1);
	p3 = func(i + 1, j);
	res = max(p1, p2);
	res = max(res, p3);
	return res;

}

int main()
{
	char str1[1050];
	char str2[1050];
	int cas = 1;
	while (gets(str1))
	{
		gets(str2);
		if (strlen(str1) == 0 || strlen(str2) == 0)
		{
			printf("%2d. Blank!\n", cas++);
			continue;
		}
		memset(dp, -1, sizeof dp);
		//puts(str1);
		xx = 1;
		name.clear();
		format(str1, n, ara1);
		//puts(str2);

		format(str2, m, ara2);

		int res = func(0, 0);
		printf("%2d. Length of longest match: %d\n", cas++, res);

	}

	return 0;
}
