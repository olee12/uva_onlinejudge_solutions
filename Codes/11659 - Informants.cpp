/*
 * 11659 - Informants.cpp
 *
 *  Created on: Feb 20, 2014
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
#define M 25
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
vi tr[M];
vi fr[M];
bool visited[M];
bool real[M];
bool fal[M];
int n, m;
void dfs(int u)
{
	if (visited[u])
		return;
	visited[u] = true;
	int zz = sz(fr[u]);
	for (int i = 0; i < zz; i++)
		real[fr[u][i]] = true;
	zz = sz(tr[u]);
	for (int i = 0; i < zz; i++)
		dfs(tr[u][i]);
}
int main(int argc, char **argv)
{
    freopen("input.txt","r",stdin);
	int u, v;
	while (sf("%d %d", &n, &m) == 1, (n | m))
	{
		for (int i = 0; i < m; i++)
		{
			sf("%d %d", &u, &v);
			if (v < 0)
			{
				v *= -1;
				fal[v] = true;
				fr[u].push_back(v);

			}
			else
			{
				tr[u].push_back(v);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (fal[i])
				dfs(i);
		for (int i = 1; i <= n; i++)
			if (real[i] == false)
				cnt++;
		pf("%d\n", cnt);
		for (int i = 0; i <= n; i++)
		{
			tr[i].clear();
			fr[i].clear();
			visited[i] = 0;
			fal[i] = 0;
			real[i] = 0;
		}
	}
	return 0;

}
