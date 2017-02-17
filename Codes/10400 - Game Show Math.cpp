/*
*   Author:        illuz <iilluzen[at]gmail.com>
*   Blog:          http://blog.csdn.net/hcbbt
*   File:          uva10400.cpp
*   Lauguage:      C/C++
*   Create Date:   2013-09-01 21:34:49
*   Descripton:    uva10400, dfs
*/
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

const int MAXN = 101;
int a[MAXN], res, n;
bool flag, vis[MAXN][32000 * 2 + 1];
const string ept;

bool ok(int a, int b)
{
    if (b >= -32000 && b <= 32000 && !vis[a][b + 32000])
    {
        vis[a][b + 32000] = true;
        return true;
    }
    return false;
}

void dfs(int d, int s, string t)
{
    if (flag) return;
    if (d == n)
    {
        if (s == res)//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#include<bits/stdc++.h>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define sz(a) (int)a.size()
#define sf scanf
#define pf printf
#define NL pf("\n")
/*--------------------------------------------------------------------------------------------------*/
#define MOD 1000007
#define M 100099

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//int x[] = {0,0,-1,1};//4-way
//int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

int terget ;
int inp[105];
int flag;
vi res;
string s;
int p;
bool visited[105][2 * 32000 + 1];
bool ok(int i, int sum)
{
    if(sum >= -32000 && sum <= 32000 && !visited[i][sum + 32000])
    {
        visited[i][sum + 32000] = 1;
        return true;
    }
    return false;
}

void dfs(int indx, int sum, string s)
{
    if(flag) return ;
    //cout<<sum<<endl;
    if(indx == p)
    {
        if(sum == terget)
        {
            flag = 1;
            REP(i, 0, p - 1) pf("%d%c", inp[i], s[i]);
            pf("%d=%d", inp[p - 1], terget);
            NL;
        }
        return ;
    }


    if(ok(indx, sum + inp[indx]))
        dfs(indx + 1, sum + inp[indx], s + "+");

    if(ok(indx, sum - inp[indx]))
        dfs(indx + 1, sum - inp[indx], s + "-");


    if(ok(indx, sum * inp[indx]))
        dfs(indx + 1, sum * inp[indx], s + "*");


    if(inp[indx] && (sum % inp[indx] == 0) && ok(indx, sum / inp[indx]))
        dfs(indx + 1, sum / inp[indx], s + "/");
}

int main()
{
    int test;

    sf("%d", &test);
    REPE(cas, 1, test)
    {
        flag = 0;
        clr(visited);
        sf("%d", &p);
        REP(i, 0, p) sf("%d", inp + i);
        sf("%d", &terget);
        dfs(1,inp[0],"");
        if(flag == 0) pf("NO EXPRESSION\n");
    }
    return 0;
}

        {
            flag = true;
            rep(i, n - 1)
            printf("%d%c", a[i], t[i]);
            printf("%d=%d\n", a[n - 1], res);
        }
        return;
    }
    if (ok(d + 1, s + a[d + 1]))
    {
        dfs(d + 1, s + a[d + 1], t + '+');
    }
    if (ok(d + 1, s - a[d + 1]))
    {
        dfs(d + 1, s - a[d + 1], t + '-');
    }
    if (ok(d + 1, s * a[d + 1]))
    {
        dfs(d + 1, s * a[d + 1], t + '*');
    }
    if (a[d + 1] && s % a[d + 1] == 0 && ok(d + 1, s / a[d + 1]))
    {
        dfs(d + 1, s / a[d + 1], t + '/');
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        rep(i, n) scanf("%d", &a[i]);
        scanf("%d", &res);
        flag = false;
        dfs(0, a[0], ept);
        if (flag == false) printf("NO EXPRESSION\n");
    }
    return 0;
}
