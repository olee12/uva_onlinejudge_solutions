/*
 * dp_solution.cpp
 *
 *  Created on: Feb 16, 2014
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
#include<iostream>
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
#define M 105
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct sol
{
	int a, b;
	sol()
	{
	}
	sol(int _a, int _b) :
			a(_a), b(_b)
	{
	}

};
sol dir[M][M];
char str1[M];
char str2[M];
int n, m;
int dp[M][M];
int lcm(int i, int j)
{
	if (i == n || j == m)
		return 0;
	int& res = dp[i][j];

	if (res != -1)
		return res;
	int p1 = 0, p2 = 0, p3 = 0;
	if (str1[i] == str2[j])
		p1 = lcm(i + 1, j + 1) + 1;
	p2 = lcm(i, j + 1);
	p3 = lcm(i + 1, j);
	if (p1 > res)
	{
		res = p1;
		dir[i][j] = sol(i + 1, j + 1);
	}
	if (p2 > res)
	{
		res = p2;
		dir[i][j] = sol(i, j + 1);

	}
	if (p3 > res)
	{
		res = p3;
		dir[i][j] = sol(i + 1, j);
	}
	return res;

}

void solution(int a,int b)
{
	if(a==n || b==m) return ;
	int nxt_a,nxt_b;
	nxt_a = dir[a][b].a;
	nxt_b = dir[a][b].b;
	if(a!=nxt_a && b!=nxt_b){
		pf("%c",str1[a]);
	}
	solution(nxt_a,nxt_b);
}

int main(int argc, char **argv)
{
	while (sf("%s %s", str1, str2))
	{
		puts(str1);
		puts(str2);
		n = strlen(str1);
		m = strlen(str2);
		mem(dp, -1);
		cout << lcm(0, 0)<<endl;
		puts("");
		solution(0,0);
		puts("");

	}
	return 0;
}

