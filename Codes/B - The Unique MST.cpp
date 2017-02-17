#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
#define clr(a) (a.clear())

#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define sf scanf
#define pf printf
#define INF 2147483645

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }




#define SZ 100010
#define M 1111
int par[M];
struct edge
{
    int u,v,w,pos;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
vector<edge> e,e1;
edge get;
int find_par(int r)
{
    return (r==par[r])? r: (par[r] = find_par(par[r]));
}
int mst(int n)
{
    int u,v,cnt=1,s=0;
    int zz = (int)e.size();
    for(int i = 0; i<zz; i++)
    {
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            e1.push_back(e[i]);
            par[v]=u;
            cnt++;
            s+=e[i].w;
            if(cnt==n) break;
        }
    }
    return s;
}
int x2,y2,w2,p2;
int mst2(int n)
{
    int u,v,cnt=1,s=0;
    int zz = (int)e.size();
    for(int i = 0; i<zz; i++)
    {
        if(x2==e[i].u && y2==e[i].v && w2 == e[i].w && p2==e[i].pos) continue;
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            par[v]=u;
            s+=e[i].w;
            cnt++;
            //if(cnt==n) break;
        }
    }
    if(cnt==n) return s;
    return 1e6;
}

int main()
{
#ifndef OLEE
// freopen("1.txt", "r", stdin);
// freopen("2.txt", "w", stdout);
#endif
    int m,n,test;
    int u,v,w;
    int r;
    sf("%d",&test);
    while(test--)
    {

        sf("%d %d",&n,&m);
        for(int i = 0; i<=n+2; i++) par[i]=i;
        for(int i = 0; i<m; i++)
        {
            sf("%d %d %d",&u,&v,&w);
            get.u = u;
            get.v = v;
            get.w = w;
            get.pos = i;
            e.push_back(get);
        }
        sort(e.begin(),e.end());
        int res1 = mst(n);
        int res2=-1;
        int sec = 1e6;
        bool flag = true;
        for(int i = 0; i<(int)e1.size(); i++)
        {
            for(int k = 0; k<=n+2; k++) par[k]=k;
            x2 = e1[i].u;
            y2 = e1[i].v;
            w2 = e1[i].w;
            p2 = e1[i].pos;
            res2 = mst2(n);
            if(res2 == res1) flag = false;
        }
        if(flag) pf("%d\n",res1);
        else pf("Not Unique!\n");
        e.clear();
        e1.clear();
    }

    return 0;
}
