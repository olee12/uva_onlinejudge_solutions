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

//#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
typedef long long ll;


#define sf scanf
#define pf printf
#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

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



typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;
#define M 1005
int par[M];
struct pnt
{
    double x,y;
    int bap;
};
pnt ara[M];
struct edge
{
    pnt u,v;
    double w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};
double dist(pnt a,pnt b)
{
    return sqrt( (double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

vector<edge> e;
edge get;
int find_par(int r)
{
    return (par[r]==r)? r : par[r] = find_par(par[r]);
}
void make_edge(int n)
{
    for(int i=1; i<=n; i++)
        for(int j = 1; j<=i; j++)
        {
            double d = dist(ara[i],ara[j]);
            get.u = ara[i];
            get.v = ara[j];
            //  cout<<ara[i].x<<' '<<ara[i].y<<' '<<"to "<<ara[j].x<<' '<<ara[j].y<<' ';
            // cout<<i<<' '<<j<<' '<<d<<endl;
            get.w = d;
            e.push_back(get);
        }
}
double mst(int n)
{
    int u,v,cnt = 0;
    double s=0;
    sort(e.begin(),e.end());
    int zz = (int ) e.size();
    // cout<<"sfaasdf: "<<zz<<endl;
    for(int i =0; i<zz; i++)
    {
        u = find_par(e[i].u.bap);
        v = find_par(e[i].v.bap);
        if(u!=v)
        {
            par[u]=v;
            s+=e[i].w;
            cnt++;
            //  cout<<s<<endl;
            // if(cnt==n - 1) break;
        }
    }
    return s;
}
int main()
{
    // cout<<dist(1,1,2,3);
    int n,m;
    int a,b;
    while(sf("%d %d",&n,&m)!=EOF)
    {
        e.clear();
        memset(par,0,sizeof par);
        for(int i = 1; i<=n; i++)
        {
            sf("%lf %lf",&ara[i].x,&ara[i].y);
            ara[i].bap=i;
            par[i]=i;
        }
        for(int i= 0; i<m; i++)
        {
            sf("%d %d",&a,&b);
            int x= find_par(a);
            int y = find_par(b);
            if(x!=y) par[x]=y;
        }
        make_edge(n);
        double res = mst(n-m);
        pf("%.2f\n",res);

    }
    return 0;
}
