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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//some constants
const int PI = 2.0 * acos(0.0);
const int E = exp(1);
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
struct point
{
    int x, y;
    point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }


};
point a, b, c, d, s, t;
bool on_segment(point p_i, point p_j, point p_k)
{
    bool a = (min(p_i.x , p_j.x) <= p_k.x)  &&  (max(p_i.x , p_j.x) >= p_k.x);
    bool b = (min(p_i.y , p_j.y) <= p_k.y)  &&  (max(p_i.y , p_j.y) >= p_k.y);
    if(a && b) return true;
    return false;
}
point minus_vector(point a, point b)
{
    return point(a.x - b.x, a.y - b.y);
}
int cross(point p1,point p2)
{
    return (p1.x*p2.y)-(p2.x*p1.y);
}
int direction(point pi, point pj, point pk)
{
    return cross(minus_vector(pk, pi) , minus_vector(pj, pi));
}

bool segment_intersect(point p1, point p2, point p3, point p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;

    else if(d1 == 0 && on_segment(p3, p4, p1)) return true;
    else if(d2 == 0 && on_segment(p3, p4, p2)) return true;
    else if(d3 == 0 && on_segment(p1, p2, p3)) return true;
    else if(d4 == 0 && on_segment(p1, p2, p4)) return true;
    return false;

}
int main()
{


    int test;
    sf1(test);
    while(test--)
    {
        sf("%d %d %d %d %d %d %d %d", &s.x, &s.y, &t.x, &t.y, &a.x, &a.y, &c.x, &c.y);
        if(a.x > c.x) swap(a.x, c.x);
        if(c.y > a.y)swap(a.y, c.y);
        b.x = a.x;
        b.y = c.y;
        d.x = c.x;
        d.y = a.y;
        int minx = min(a.x,c.x);
        int miny = min(a.y,c.y);
        int maxx = max(a.x,c.x);
        int maxy = max(a.y,c.y);
        int f = 0;
        if(segment_intersect(s, t, a, b)) f = 1;
        if(segment_intersect(s, t, b, c)) f = 1;
        if(segment_intersect(s, t, c, d)) f = 1;
        if(segment_intersect(s, t, a, d)) f = 1;
        if(minx<=s.x && maxx>=s.x && s.y>=miny && maxy>=s.y && minx<=t.x && maxx>=t.x && t.y>=miny && maxy>=t.y ) f = 1;

        if(f) puts("T");
        else puts("F");
    }
    return 0;

}


/*
3
2 3 2 6 0 4 5 0
2 4 2 6 0 4 5 0
1 1 2 2 0 4 4 0
*/
