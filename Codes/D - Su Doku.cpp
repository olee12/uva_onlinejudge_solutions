/*
 * D - Su Doku.cpp
 *
 *  Created on: Feb 19, 2014
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
#define M 100000250
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
#define UNASSIGNED 0
int N;
int grid[9][9];
int n;
bool find_unassinged(int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

bool Usedinrow(int row, int num)
{
	for (int i = 0; i < N; i++)
		if (grid[row][i] == num)
			return true;
	return false;
}

bool Usedincol(int col, int num)
{
	for (int i = 0; i < N; i++)
		if (grid[i][col] == num)
			return true;
	return false;
}
bool UsedinBox(int num, int wr, int wc)
{
	for (int row = 0; row < n; row++)
		for (int col = 0; col < n; col++)
			if (grid[row + wr][col + wc] == num)
				return true;
	return false;
}
bool issafe(int row, int col, int num)
{
	return !Usedinrow(row, num) && !Usedincol(col, num)
			&& !UsedinBox(num, row - (row % n), col - (col % n));
}

bool solve_suduku()
{
	int row, col;
	if (!find_unassinged(row, col))
		return true;
	for (int num = 1; num <= N; num++)
	{
		if (issafe(row, col, num))
		{
			grid[row][col] = num;
			if (solve_suduku())
				return true;

			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}
void display()
{
	for (int i = 0; i < N; i++)
	{
		pf("%d", grid[i][0]);
		for (int j = 1; j < N; j++)
			pf(" %d", grid[i][j]);
		puts("");
	}

}
int main(int argc, char **argv)
{
	bool f = 0;
	while (sf("%d", &n) == 1)
	{
		N = n * n;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				sf("%d", &grid[i][j]);
		if (f)
			puts("");
		f=1;
		//puts("");
		//display();
		if (solve_suduku())
			display();
		else
			puts("NO SOLUTION");
	}

	return 0;
}

