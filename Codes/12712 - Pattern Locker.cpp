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

 long long mod = 10000000000007LL;
/*

ll rec(int n, int r)
{
    if(n == r) return 1;
    if(r == 1) return n;
     long long &ret = nCr[n][r];
    if(ret != -1) return ret;

    ret = (rec(n - 1, r) % mod) + rec(n - 1, r - 1) % mod;
    ret %= mod;
    return ret;
}


void bottomupNcr()
{
    for(int i = 1; i <= 10000; i++)
        for(int j = 0; j <= 10000; j++)
            if(j == 0) nCr[i][j] = 1;
            else if(j == 1) nCr[i][j] = i;
            else if(i == j) nCr[i][j] = 1;
            else nCr[i][j] = ((nCr[i - 1][j] % mod) + (nCr[i - 1][j - 1] % mod));
}




void gennCr()
{
    nCr[1][0] = 1;
    nCr[1][1] = 1;

    REPE(i, 2, 10000)
    {
        nCr[i][0] = 1;
        REP(j, 1, i)
        {
            nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % mod;
        }
        nCr[i][i] = 1;
    }
}

void factorial()
{
    fact[0] = 1;
    fact[1] = 1;
    REPE(i, 1, 10000) fact[i] = (i * fact[i - 1]) % mod;
}
*/
ll nPr(int n,int r)
{
    ll ans = 1;
    for(int i = 1;i<=r;i++)
    {
        ans*=n;
        ans%=mod;
        n--;
    }
    return ans;
}
int main()
{

    int l, n, m;
    int test;
    sf("%d", &test);
    REPE(cas, 1, test)
    {
        sf("%d %d %d", &l, &n, &m);
        l = l * l;
        ll ans = 0;

        ll prv = nPr(l,n) % mod;

        ans = prv;

        REPE(i, n+1 , m)
        {
            prv *=  (l-i+1);
            prv%=mod;
            ans+= prv;
            ans%=mod;
        }
        pf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}
