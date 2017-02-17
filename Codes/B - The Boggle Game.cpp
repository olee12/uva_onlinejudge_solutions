/*
 * B - The Boggle Game.cpp
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
ll x[] =
{ -1, -1, -1, 0, 0, 1, 1, 1 }; //8-way
ll y[] =
{ -1, 0, 1, -1, 1, -1, 0, 1 }; //8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
#define M 6
char g1[M][M];
char g2[M][M];
bool flag[M][M];
bool flag2[M][M];
vector<char> res;
map<string, bool> mp1;
map<string, bool> mp2;
vector<string> ans;
int aaa =0;
bool vowel[30];
bool is_valid(int i, int j)
{
	return (i >= 0 && i < 4 && j >= 0 && j < 4);
}
void dfs(int i, int j, char g[][M], map<string, bool>& mep)
{
	int tx, ty;
	if (sz(res) == 4)
	{
		int cnt = 0;
		string s = "";
		for (int i = 0; i < 4; i++)
		{
			if (vowel[res[i] - 'A'])
				cnt++;
			s += res[i];
		}
		if (cnt < 2 || cnt > 2)
			return;

		aaa++;
		mep[s] = 1;
		return;
	}
	for (int k = 0; k < 8; k++)
	{
		tx = i + (int) x[k];
		ty = j + (int) y[k];
		if (is_valid(tx, ty))
		{
			if (flag[tx][ty] == 0)
			{
				flag[tx][ty] = 1;
				res.push_back(g[tx][ty]);
				dfs(tx, ty, g, mep);
				res.pop_back();
				flag[tx][ty] = 0;
			}
		}
	}
}
int main(int argc, char **argv)
{
	vowel['A' - 'A'] = 1;
	vowel['U' - 'A'] = 1;
	vowel['O' - 'A'] = 1;
	vowel['I' - 'A'] = 1;
	vowel['E' - 'A'] = 1;
	vowel['Y' - 'A'] = 1;
	char str[100];
	int n;
	bool f = 0;
	while (gets(str))
	{

		if (str[0] == '#')
			break;
		sscanf(str, " %c %c %c %c %c %c %c %c", &g1[0][0], &g1[0][1], &g1[0][2],
				&g1[0][3], &g2[0][0], &g2[0][1], &g2[0][2], &g2[0][3]);
		n = 1;
		while (gets(str) && *str)
		{

			sscanf(str, " %c %c %c %c %c %c %c %c", &g1[n][0], &g1[n][1],
					&g1[n][2], &g1[n][3], &g2[n][0], &g2[n][1], &g2[n][2],
					&g2[n][3]);
			n++;

		}
		if (f)
			puts("");
		f = 1;
		mp1.clear();
		mp2.clear();
		mem(flag, 0);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				dfs(i, j, g1, mp1);
		mem(flag, 0);
        cout<<aaa<<endl;
        aaa=0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				dfs(i, j, g2, mp2);
    cout<<aaa<<endl;
		ans.clear();
		cout<<sz(mp1)<<' '<<sz(mp2)<<endl;
		map<string, bool>::iterator it;
		for (it = mp1.begin(); it != mp1.end(); it++)
		{
			// cout<<it->fr<<endl;
			if (mp2.find(it->fr) != mp2.end())
			{
				//cout<<mp1.size()<<' '<<mp2.size()<<endl;
				ans.push_back(it->fr);
			}
		}
		for (int i = 0; i < sz(ans); i++)
			pf("%s\n", ans[i].c_str());
		if (sz(ans) == 0)
			pf("There are no common words for this pair of boggle boards.\n");
	}
	return 0;

}

