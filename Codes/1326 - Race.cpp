/*
 * 1326 - Race.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Olee
 */
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

#define clr(a) (a.clear())

#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 30005
#define sf scanf
#define pf printf
#define INF 2147483645

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
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
long long nCr[1005][1005];
long long dp[1005];
ll comb(int n, int r)
{
	if (n == r)
		return 1;
	if (r == 1)
		return n;
	ll &res = nCr[n][r];
	if (res != -1)
		return res;

	res = (comb(n - 1, r) % 10056 + comb(n - 1, r - 1) % 10056)%10056;
	return res;
}
ll func(int n)
{

	if (n == 1)
		return 1;
	if (n == 0)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	dp[n] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[n] = ((dp[n] % 10056)
				+ ((comb(n, i) % 10056 * func(n - i) % 10056) % 10056))%10056;
	}
	return dp[n] % 10056;
}
int main(int argc, char **argv)
{
	mem(dp, -1);
	mem(nCr, -1);
	int test;
	sf("%d", &test);
	for (int cas = 1; cas <= test; cas++)
	{
		int n;
		sf("%d", &n);
		pf("Case %d: %lld\n", cas, func(n));
	}
	return 0;
}

