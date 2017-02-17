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
//#include <bits/stdc++.h>
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
#define sf1(a) scanf("%d",&a)
/*--------------------------------------------------------------------------------------------------*/
#define MOD 1000007
#define M 250005

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
int val;
struct ttt
{
    ll val;
    ll st;
    ll nd;
    void  clear()
    {
        val = st = nd = 0;
    }

};

ll tree[M * 4];
ttt lazy[M * 4];
ll forc[M * 4];

void refresh222(int node, int beg, int end, ll val)
{
    //cout<<"called\n";
    tree[node] = val * ll(end - beg + 1);
    if(beg != end)
    {
        int left = node << 1;
        int right = left + 1;
        forc[left] = val;
        forc[right] = val;
        lazy[left].clear();
        lazy[right].clear();
    }
    lazy[node].clear();
    forc[node] = 1000000;


}

void refresh(int node, int beg, int end)
{

    if(beg == end)
    {
        tree[node] += lazy[node].st;
        lazy[node].clear();
        return ;
    }

    ll a1, an, n, d;
    ll sn;
    n = end - beg + 1;

    a1 = min(lazy[node].st , lazy[node].nd);
    an = max(lazy[node].st, lazy[node].nd );
    d = (an - a1) / (n - 1);

    sn = (n * (2 * a1 + (n - 1) * d)) / 2LL;
    //  cout<<a1<<' '<<an<<' '<<d<<' '<<sn<<endl;
    tree[node] += sn;

    int mid = (beg + end) >> 1;
    ll lf, rt;

    if(beg != end)
    {

        if(lazy[node].st > lazy[node].nd) d *= -1;

        ///for left lazy node update
        n = (mid - beg + 1);
        if(forc[node*2]!=1000000) refresh222(node*2,beg,mid,forc[node*2]);
        rt = lazy[node].st + ( n - 1) * d;

        lf = lazy[node].st;



        lazy[node * 2].st += lf;
        lazy[node * 2].nd += rt;

        /// for right lazy node update
        if(forc[node*2+1]!=1000000) refresh222(node*2+1,mid+1,end,forc[node*2+1]);
        lf = lazy[node].st + (n) * d;
        rt = lazy[node].nd;

        lazy[node * 2 + 1].st += lf;
        lazy[node * 2 + 1].nd += rt;
    }
   lazy[node].clear();


}

void update(int node, int beg, int end, int &i, int &j, int &ty)
{
    //  pf("%d\n", node);
    if(forc[node] != 1000000) refresh222(node, beg, end,forc[node]);
    if(lazy[node].st || lazy[node].nd) refresh(node, beg, end);
    if(beg > j || end < i) return ;
    if(beg >= i && end <= j)
    {
        int lf, rt;

        if(ty == 2)
        {
            lf = j - beg + 1;
            rt = j - end + 1;
            lazy[node].st += lf;
            lazy[node].nd += rt;
            refresh(node, beg, end);
        }
        else if(ty == 1)
        {
            lf = beg - i + 1;
            rt = end - i + 1;
            lazy[node].st += lf;
            lazy[node].nd += rt;
            refresh(node, beg, end);

        }
        else if(ty == 3)
        {

            refresh222(node, beg, end, val);
        }

        return ;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (beg + end) >> 1;

    update(left, beg, mid, i, j, ty);
    update(right, mid + 1, end, i, j, ty);
    tree[node] = tree[left] + tree[right];
}

ll query(int node, int beg, int end, int &i, int &j)
{
    if(forc[node] != 1000000) refresh222(node, beg, end,forc[node]);
    if(lazy[node].st || lazy[node].nd) refresh(node, beg, end);
    if(beg > j || end < i) return 0;



    if(beg >= i && end <= j) return tree[node];

    int left = node << 1;
    int right = left + 1;

    int mid = (beg + end) >> 1;

    return query(left, beg, mid, i, j) + query(right, mid + 1, end, i, j);

}

int main()
{
    // cout << sizeof tree / (1024.0 * 1024.0);
    int test;
    char ch;
    int i, j, x;
    int ty ;
    int q;



        REPE(i,0,250001*4) forc[i]=1000000;
        clr(tree);
        clr(lazy);
        sf("%d", &q);

        while(q--)
        {
            sf(" %c %d %d", &ch, &i, &j);
            if(ch == 'C')
            {
                sf("%d ", &val);
                ty = 3;
                update(1, 1, 250001, i, j, ty);
            }
            else if(ch == 'A')
            {
                ty = 1;
                update(1, 1, 250001, i, j, ty);
                //   cout<<tree[4]<<' '<<tree[10]<<endl;
            }
            else if(ch == 'B')
            {
                ty = 2;
                update(1, 1, 250001, i, j, ty);
                // cout<<tree[4]<<' '<<tree[10]<<endl;
            }
            else pf("%lld\n", query(1, 1, 250001, i, j));
        }

    return 0;

}
//250001

