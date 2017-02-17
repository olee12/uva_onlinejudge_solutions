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
/*--------------------------------------------------------------------------------------------------*/
#define MOD 1000007
#define M 30000

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

struct iii
{
    int w,q,ind;
    iii() {}
};
int dp[1001][1001];
int dir[1001][1001];
bool comp(iii a,iii b)
{
    return a.w<b.w;
}
int n = 1,ans;
iii ara[1001];
int cnt = 0;

int func(int i,int j)
{
    if(i==n+1) return 0;
    int &res = dp[i][j];
    if(res!=-1) return res;
    int p1 =0,p2=0;
    if(ara[i].w > ara[j].w && ara[i].q < ara[j].q)
    {
        p1 = 1+ func(i+1,i);
    }

    p2 = func(i+1,j);

    res = max(p1,p2);
    if(res == p1) dir[i][j]=1;
    else dir[i][j]=2;

    return res;
}

void path(int i,int j)
{
   // cout<<i<<' '<<j<<endl;
    if(i==n+1) return ;
    if(dir[i][j]==1)
    {
        pf("%d\n",ara[i].ind);
        cnt++;
        if(cnt==ans) return;
        return path(i+1,i);
    }
    return path(i+1,j);

}


int main()
{
    int  a,b,c;
    while(~sf("%d %d",&ara[n].w,&ara[n].q))
    {
        ara[n].ind = n;
        n++;
    }
    mem(dp,-1);
    sort(ara+1,ara+n,comp);
    ara[0].w = 0,ara[0].q=10000;
  //  for(int i = 0; i<=n; i++) printf("%d %d\n",ara[i].w,ara[i].q);
    ans = func(1,0);
    cout<<ans<<"\n";
    path(1,0);
    return 0;
}
