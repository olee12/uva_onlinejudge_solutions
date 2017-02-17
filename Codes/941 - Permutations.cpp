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
#define all(a) a.begin(),a.end()

#define X first
#define Y second
#define M 25
ll f[M] =
{ 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600,
		6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000,
		6402373705728000, 121645100408832000, 2432902008176640000 };
char str[M];
int vis[M];
ll dp[M];

int len;
ll cnt(int mask)
{
	int a = 0;
	for(int i= 0;i<len;i++)
	{
		if(mask & (1<<i)) a++;
	}
	return f[len-a];
}
int main(int argc, char **argv)
{
	//fact(20);

	ll prv, nth, res;
	int test;
	string str;
	sf("%d", &test);
	while (test--)
	{
		cin>>str>>nth;
	//	puts(str);
		 len = str.length();
		// nth--;

		 sort(all(str));
		int c = 0;

		for(int i = len-1 ;i>0;i-- )
		{
			//cout<<i<<endl;
			c = nth/f[i];
			pf("%c",str[c]);
			str.erase(c+str.begin());
			nth = nth % (f[i]);
		}
		cout<<str<<"\n";
	}
	return 0;

}
