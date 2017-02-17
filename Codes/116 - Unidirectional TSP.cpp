//C headers
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
#include <bits/stdc++.h>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
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
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d", &a,&b, &c)
/*--------------------------------------------------------------------------------------------------*/
#define MOD 1000007
#define M 100099
#define oo (1<<30)
//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//int x[] = {0,0,-1,1};//4-way
//int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

//#include<conio.h>
//#define wait getch()
int row , col;
ll dp[15][115];
ll graph[11][115];
ll rec(int i, int j)
{

    if(j == col) return 0LL;
    if(i == row) return oo;
    ll &ret = dp[i][j];

    if(ret != oo) return ret;

    if(i == 0)
    {
        ret = min(ret, rec(i, j + 1) + graph[i][j]);
        ret = min(ret, rec(i + 1, j + 1) + graph[i][j]);
        ret = min(ret, rec(row - 1, j + 1) + graph[i][j]);
    }
    else if( i == row - 1 )
    {
        ret = min(ret, rec(0, j + 1) + graph[i][j]);
        ret = min(ret, rec(i - 1, j + 1) + graph[i][j]);
        ret = min(ret, rec(i, j + 1) + graph[i][j]);
    }
    else
    {

        ret = min(ret, rec(i, j + 1) + graph[i][j]);
        ret = min(ret, rec(i - 1, j + 1) + graph[i][j]);
        ret = min(ret, rec(i + 1, j + 1) + graph[i][j]);

    }
    return ret;

}
vi ans;
void path(int i, int j)
{
    //pf("I = %d J = %d\n",i,j);
    if(j == col) return ;
    int v1, v2, v3, res;
    // ans.push_back(i + 1);
    if(j) pf(" ");
    pf("%d", i + 1);
    if(i == 0)
    {
        v1 = rec(i, j + 1) + graph[i][j];
        v2 = rec(i + 1, j + 1) + graph[i][j];

        if(v1 <= v2)
            res = v1;
        else res = v2;

        v3 = rec(row - 1, j + 1) + graph[i][j];
        if(res > v3)
        {
            res = v3;
        }

        if(res == v1) path(i, j + 1);
        else if(res == v2)  path(i + 1, j + 1);
        else path(row - 1, j + 1);
    }

    else if(i == row - 1)
    {
        v1 = rec(0, j + 1) + graph[i][j];
        v2 = rec(i - 1, j + 1) + graph[i][j];


        if(v1 <= v2)
            res = v1;
        else res = v2;

        v3 = rec(i, j + 1) + graph[i][j];
        if(res > v3) res = v3;

        if(res == v1)  path(0, j + 1);
        else if(res == v2)  path(i - 1, j + 1);
        else path(i, j + 1);

    }
    else
    {
        v1 = rec(i - 1, j + 1) + graph[i][j];
        v2 = rec(i, j + 1) + graph[i][j];

        if(v1 <= v2)
            res = v1;
        else res = v2;

        v3 = rec(i + 1, j + 1) + graph[i][j];
        if(res > v3) res = v3;

        if(res == v1) path(i - 1, j + 1);
        else if(res == v2) path(i , j + 1);
        else path(i + 1, j + 1);
    }


}

void init()
{
    REP(i, 0, 12) REP(j, 0, 111) dp[i][j] = oo;
}
int main()
{
    while(sf("%d %d", &row, &col) != EOF)
    {
        init();
        REP(i, 0, row) REP(j, 0, col)  sf("%lld", &graph[i][j]);


        ll mx = oo;
        int pos ;
        REP(i, 0, row)
        {
            if(mx > rec(i, 0)) mx = rec(i, 0), pos = i;
        }
        // cout<<pos <<' '<<mx<<endl;
        path(pos, 0);
        NL;
        pf("%lld\n", rec(pos, 0));
//        REP(i, 0, sz(ans))
//        {
//            if(i) pf(" ");
//            pf("%d", ans[i]);
//        }

    }
    return 0;
}
