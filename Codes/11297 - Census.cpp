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
int ara[501][501];
ii tree[8 * 510 * 510];
void build(int node, int bx, int by, int ex, int ey)
{
    if(bx == ex && by == ey)
    {
        // cout<<node<<' '<<ara[bx][by]<<endl;
        tree[node].fr = ara[bx][by];
        tree[node].sc = ara[bx][by];
        return;
    }

    int mx = (bx + ex) /2;
    int my = (by + ey) / 2;

    int nxt = node * 4;

    build(nxt , bx, by, mx, my);

    tree[node].fr = tree[nxt ].fr;
    tree[node].sc = tree[nxt ].sc;

    if( my + 1 <= ey)
    {
        build(nxt + 1, bx, my + 1, mx, ey);
        tree[node].fr = min(tree[node].fr, tree[nxt + 1].fr);
        tree[node].sc = max(tree[node].sc, tree[nxt + 1].sc);
    }
    if(mx + 1 <= ex)
    {
        build(nxt + 2, mx + 1, by, ex, my);

        tree[node].fr = min(tree[node].fr, tree[nxt + 2].fr);
        tree[node].sc = max(tree[node].sc, tree[nxt + 2].sc);
    }
    if(my + 1 <= ey && mx + 1 <= ex)
    {
        build(nxt + 3, mx + 1, my + 1, ex, ey);

        tree[node].fr = min(tree[node].fr, tree[nxt + 3].fr);
        tree[node].sc = max(tree[node].sc, tree[nxt + 3].sc);
    }
}

void update(int node, int bx, int by, int ex, int ey, int &x, int &y, int &val)
{

    if(bx > x || by > y || x > ex || y > ey) return ;

    if(bx == x && ex == x && by == y && ey == y)
    {
        tree[node].fr = val;
        tree[node].sc = val;
        return;
    }

    int mx = (bx + ex) / 2;
    int my = (by + ey) / 2;

    int nxt = node * 4;

    update(nxt , bx, by, mx, my, x, y, val);

    tree[node].fr = tree[nxt ].fr;
    tree[node].sc = tree[nxt ].sc;

    if(my + 1 <= ey)
    {
        update(nxt + 1, bx, my + 1, mx, ey, x, y, val);
        tree[node].fr = min(tree[node].fr, tree[nxt + 1 ].fr);
        tree[node].sc = max(tree[node].sc, tree[nxt + 1].sc);
    }
    if(mx + 1 <= ex)
    {
        update(nxt + 2, mx + 1, by, ex, my, x, y, val);

        tree[node].fr = min(tree[node].fr, tree[nxt + 2].fr);
        tree[node].sc = max(tree[node].sc, tree[nxt + 2].sc);
    }
    if(mx + 1 <= ex && my + 1 <= ey)
    {
        update(nxt + 3, mx + 1, my + 1, ex, ey, x, y, val);

        tree[node].fr = min(tree[node].fr, tree[nxt + 3].fr);
        tree[node].sc = max(tree[node].sc, tree[nxt + 3].sc);
    }
}



ii query(int node, int bx, int by, int ex, int ey, int &x1, int &y1, int &x2, int &y2)
{

    if(x1 > ex || bx > x2 || y1 > ey || y2 < by) return mp(1000000, -10000);
    //  cout<<"hello olee\n\n\n";
    if(bx >= x1 && ex <= x2 && by >= y1 && ey <= y2)
    {
        // cout<<node<<' '<<tree[node].fr<<' '<<tree[node].sc<<endl;
        return tree[node];
    }

    int mx = (bx + ex) / 2;
    int my = (by + ey) / 2;

    int nxt = node * 4;

    ii tmp =  query(nxt , bx, by, mx, my, x1, y1, x2, y2);
    ii tmp2;

    if(my + 1 <= ey)
    {
        tmp2 =  query(nxt + 1, bx, my + 1, mx, ey, x1, y1, x2, y2);
        tmp.fr = min(tmp.fr, tmp2.fr);
        tmp.sc = max(tmp.sc, tmp2.sc);
    }
    if(mx + 1 <= ex)
    {
        tmp2 =  query(nxt + 2, mx + 1, by, ex, my, x1, y1, x2, y2);

        tmp.fr = min(tmp.fr, tmp2.fr);
        tmp.sc = max(tmp.sc, tmp2.sc);
    }
    if(mx + 1 <= ex && my + 1 <= ey)
    {
        tmp2 =  query(nxt + 3, mx + 1, my + 1, ex, ey, x1, y1, x2, y2);

        tmp.fr = min(tmp.fr, tmp2.fr);
        tmp.sc = max(tmp.sc, tmp2.sc);
    }
    return tmp;
}



int main()
{
    int row , col;
    sf2(row, col);
    char ch;
    int x1, y1, x2, y2;
    REP(i, 0, row) REP(j, 0, col) sf("%d", &ara[i][j]);
    build(1, 0, 0, row - 1, col - 1);
    int q, val;
    sf1(q);
    while(q--)
    {
        sf(" %c %d %d", &ch, &x1, &y1);
        x1--;
        y1--;
        if(ch == 'c')
        {
            sf1(val);
            update(1, 0, 0, row - 1, col - 1, x1, y1, val);
        }
        else
        {
            sf2(x2, y2);
            x2--;
            y2--;
            ii ans = query(1, 0, 0, row - 1, col - 1, x1, y1 , x2, y2);
            pf("%d %d\n", ans.sc, ans.fr);
        }
    }
    return 0;
}
