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
#define sf1(a) sf()
#define NL pf("\n")
/*--------------------------------------------------------------------------------------------------*/
#define MOD 1000007
#define M 1024099

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
string inp;
int tree[M * 4];
int lazy[M * 4];

void in_ref(int &val, int &type)
{
    if(val == 1 && type == 1) val = 0;
    else if(val == 2 && type == 1) val = 3;
    else if(val == 3 && type == 1) val = 2;
    else if(val == 0 && type == 1) val = 1;
    else
        val = type;
    return ;
}


void build(int node, int beg, int end)
{
    if(beg == end)
    {
        if(inp[beg] == '1') tree[node] = 1;
        else tree[node] = 0;
        lazy[node] = 0;
        return ;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (beg + end) >> 1;
    build(left, beg, mid);
    build(right, mid + 1, end);
    tree[node] = tree[left] + tree[right];
    lazy[node] = 0;

}
void refresh(int node, int beg, int end, int value)
{
    if(value == 1)
    {
        int p = (end - beg + 1);
        tree[node] = p - tree[node];
    }
    else if(value == 2)  tree[node] = (end - beg + 1);
    else if(value == 3)   tree[node] = 0;

    if(beg != end)
    {
        in_ref(lazy[node * 2], value);
        in_ref(lazy[node * 2 + 1], value);
    }
    lazy[node] = 0;
}
void update(int node, int beg, int end, int &i, int &j, int val)
{
    if(lazy[node]) refresh(node, beg, end, lazy[node]);
    if(beg > j || end < i ) return ;
    if(beg >= i && end <= j)
    {
        refresh(node, beg, end, val);
        return ;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (beg + end) >> 1;

    update(left, beg, mid, i, j, val);
    update(right, mid + 1, end, i, j, val);
    tree[node] = tree[left] + tree[right];

}

int query(int node, int beg, int end, int &i, int &j)
{
    if( beg > j || end < i ) return 0;
    if(lazy[node]) refresh(node, beg, end, lazy[node]);
    if(beg >= i && end <= j) return tree[node];
    int left = node << 1;
    int right = left + 1;
    int mid = (beg + end) >> 1;

    return query(left, beg, mid, i, j) + query(right, mid + 1, end, i, j);

}
int main()
{
    int test;
    int m, n, p, k;
    char ch;
    int  i, j, val;
    char str[100];
    int q;
    sf("%d", &test);
    for(int cas = 1; cas <= test; cas++)
    {
       // clr(lazy);
       // clr(tree);
        inp = "";
        sf("%d", &m);
        while(m--)
        {
            sf("%d", &n);
            sf("%s", str);
            for(int i = 0; i < n; i++)
                inp += string(str);
        }
        int N = sz(inp);
        build(1,0,N-1);
      //  puts(inp.c_str());
       // pf("%d\n", N);
        sf("%d", &q);
        int k = 0;
        pf("Case %d:\n",cas);
        while(q--)
        {
            sf(" %c %d %d", &ch, &i, &j);
            if(ch == 'I') update(1, 0, N - 1, i, j, 1);
            else if(ch == 'F') update(1, 0, N - 1, i, j, 2);
            else if(ch == 'E') update(1, 0, N - 1, i, j, 3);
            else printf("Q%d: %d\n",++k, query(1, 0, N - 1, i, j));
        }
    }
    return 0;
}
