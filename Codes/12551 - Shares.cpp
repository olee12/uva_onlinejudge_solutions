//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
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
//#include <bits/stdc++.h>
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
#define csprnt printf("Case %d: ", cas++);
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define popc(i) (__builtin_popcount(i))
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
#define MOD 1000000007
#define M 16050
#define oo (1<<30)
//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//int x[] = {0,0,-1,1};//4-way
//int y[] = {1,-1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

template<class T1> void deb(T1 e)
{
    cout << e << endl;
}
template<class T1, class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << " " << e2 << endl;
}
template<class T1, class T2, class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << " " << e2 << " " << e3 << endl;
}
template<class T1, class T2, class T3, class T4> void deb(T1 e1, T2 e2, T3 e3,T4 e4)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template<class T1, class T2, class T3, class T4, class T5> void deb(T1 e1,T2 e2, T3 e3, T4 e4, T5 e5)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template<class T1, class T2, class T3, class T4, class T5, class T6> void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6<< endl;
}
template<typename T> inline T sqr(T n)
{
    return n * n;
}
inline double hypot(double x, double y)
{
    return sqrt(sqr(x) + sqr(y));
}
template<typename T> inline T pmod(T n, T m)
{
    return ((n % m) + m) % m;
}
template<typename T> T power(T n, int p)
{
    return (p == 0) ? (T) (1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1));
}
template<typename T> T bigmod(T n, int p, T m)
{
    return (p == 0) ?(T) (1) :((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m;
}
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

//#include<conio.h>
//#define wait getch()
/// bal bal bal bal

struct info
{
    ll now,next;
};
info ara[505];
pll tmp;
int capacity;
int n,p;
struct type
{
    ll buy ,sell;
};
bool comp(type a,type b)
{
    return a.sell>b.sell;
}
type packs[50005];
typedef pair<int,ll> llii;
//map<llii,ll> dp;
//ll rec(int pos,ll cost)
//{
//    if(pos >= p+1) return 0;
//    llii now = mp(pos,cost);
//    if(dp.find(now)!=dp.end()) return dp[now];
//    ll ret = -oo;
//    if(capacity >= cost + packs[pos].buy)
//    ret = max(ret,rec(pos+1,cost + packs[pos].buy) + packs[pos].sell);
//    ret = max(ret,rec(pos+1,cost));
//    dp[now] = ret;
//    return dp[now];
//}



map<ll , ll> dp,res;


int main()
{
    bool f = false;
    while(sf1(capacity)==1)
    {

        sf2(n,p);
        for(int i = 1; i<=n; i++)
        {
            sf("%lld %lld",&ara[i].now,&ara[i].next);
        }
        ll b,s;
        dp.clear();
        res.clear();
        ll mxx = -1;
        res[0]=0;
        for(int i = 1; i<=p; i++)
        {

            int a;
            sf1(a);
            for(int j = 0; j<a; j++)
            {
                sf("%lld %lld",&tmp.fr,&tmp.sc);

                packs[i].buy += (ara[tmp.fr].now*tmp.sc);
                packs[i].sell += ((ara[tmp.fr].next*tmp.sc) - (ara[tmp.fr].now*tmp.sc));
            }

            dp = res;
            //  deb("fadf");
            loop(it,res)
            {
                if(it->fr + packs[i].buy > capacity) continue;
                if( dp.count(it->fr + packs[i].buy) ) dp[it->fr + packs[i].buy] = max( dp[it->fr+packs[i].buy],dp[it->fr]+packs[i].sell);
                else dp[it->fr+packs[i].buy] = it->sc + packs[i].sell;

            }
            // deb("sfasdf");

            res.clear();
            mxx = -1;
            loop(it,dp)
            {
                if(it->sc > mxx)
                {
                    mxx = it->sc;
                    res[it->fr] = it->sc;
                }
            }

        }
        if(f) puts("");
        f = 1;
        pf("%lld\n",mxx);


    }
    return 0;
}
/**
200000000
5 30
2800 3500
1400 4800
2900 2800
500 3800
3300 4700
2 2 13 4 15
4 4 1 1 22 3 17 5 22
1 3 2
1 3 6
4 1 11 2 5 3 7 5 15
1 5 1
4 2 26 1 21 3 8 5 26
2 3 5 2 26
4 2 30 4 12 3 7 5 14
3 3 8 2 20 5 3
1 5 30
2 1 29 3 3
5 3 3 1 20 5 26 4 9 2 25
3 1 2 2 16 3 5
2 5 5 4 26
5 2 18 5 10 4 18 1 12 3 30
3 2 5 3 27 5 4
4 3 2 4 8 1 20 2 6
3 2 14 1 1 4 22
5 2 23 3 26 1 27 5 3 4 6
1 2 16
4 1 13 4 10 2 23 5 2
1 1 14
1 2 20
1 3 14
2 3 21 1 22
1 2 27
3 5 24 1 26 3 13
5 4 15 3 3 2 21 1 5 5 16
4 2 22 5 1 4 10 1 30
*/


