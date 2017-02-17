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
char str[500];
int inp[30];
ii dp[30][30];
int flag[30];
int len;
ii rec(int prv, int now)
{
    if (now == len + 1 && prv != 0)
        return mp(0, 1);
    if (now == len + 1 && prv == 0)
        return mp(0, 0);


    ii &ret = dp[prv][now];
    if (ret.fr != -1)
        return ret;


    ii p1, p2;
    p1.fr = p1.sc = p2.fr = p2.sc = 0;


    if (prv == 0 || 5 * inp[prv-1] <= 4 * inp[now-1])
    {
        p1 = rec(now, now + 1);
        p1.fr += 1;
    }

p2 = rec(prv, now + 1);
    if (p1.fr > p2.fr)
        return ret = p1;
    if (p2.fr > p1.fr)
        return ret = p2;
    return ret = mp(p1.fr, p1.sc + p2.sc);

}
int main(int argc, char **argv)
{
    int test;
    sf("%d", &test);
    char a[1];
    gets(a);
    while (test--)
    {
        mem(dp, -1);
        clr(flag);
        gets(str);
        len = strlen(str);
        int j = 0;
        for (int i = 0; i < len; i++)
            if (str[i] >= 'A' && str[i] <= 'Z')
                if (flag[str[i] - 'A'] == 0)
                {
                    inp[j++] = str[i]-'A'+1;
                    flag[str[i] - 'A'] = 1;
                }
        inp[j] = '\0';
        len = j;
        sort(inp, inp + j);
        ii ans = rec(0, 1);
        pf("%d %d\n", ans.fr, ans.sc);

    }
    return 0;
}

