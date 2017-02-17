/*
 * 990 - Diving for Gold.cpp
 *
 *  Created on: Feb 17, 2014
 *      Author: Olee
 */

#include <cstdio>
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
#define mp make_pair
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
#define M 35
ii dp[M][1005];
int dir[M][1005];
int olee[M][1050];
int cas = 3;
int dept[M];
int cost[M];
int cap, w, n;
int cnt = 0;
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
//sol dir[M][1050];
ii func(int i, int ammount)
{
    if (i == n + 1)
        return mp(0, 0);
    ii& res = dp[i][ammount];
    int& v = olee[i][ammount];
    if (v == cas)
        return res;
    res.fr = 0;
    res.sc = 0;

    v = cas;
    ii p1, p2;
    p1.fr = p2.fr = p1.sc = p2.sc = 0;
    if (ammount + 3 * (dept[i] * w) <= cap)
    {
        p1 = func(i + 1, ammount + 3 * (dept[i] * w));
        p1.fr += cost[i];
        p1.sc++;
    }

    p2 = func(i + 1, ammount);
    if (p1.fr > p2.fr)
    {
        dir[i][ammount] = 1;

        res = p1;

    }
    else
    {
        dir[i][ammount]=2;
        res = p2;
    }
    return res;

}
void display(int a,int b)
{
    if(a==n+1) return;
    //int nxt_a = dir[a][b].a;
    // int nxt_b = dir[a][b].b;
    int res = dir[a][b];
    //cout<<"a = "<<a<<" b = "<<b<< " nxt_a = "<<nxt_a<<" nxt_b ="<<nxt_b<<endl;
    if(res==1)
    {
        pf("%d %d\n",dept[a],cost[a]);
        display(a+1,b + 3 * (dept[a] * w));
    }
    else if(res==2)
        display(a+1,b);

}
int main()
{
   // freopen("input.txt","r",stdin);
    bool f = 0;
    while (sf("%d %d", &cap, &w) == 2)
    {
        sf("%d", &n);
        if(f) puts("");
        f=1;
        for (int i = 1; i <= n; i++)
            sf("%d %d", dept + i, cost + i);

        pf("%d\n%d\n",func(1,0).fr,func(1,0).sc);
        cas++;
        display(1,0);

    }
    return 0;

}

