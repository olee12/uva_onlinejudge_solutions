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
#define M 205
int par[M];
int find_par(int r)
{
    return par[r]==r ? r : par[r] = find_par(par[r]);
}
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};
vector<edge> e,e1;
edge get;
ll mst(int n)
{

    for(int i= 1; i<=n+2; i++) par[i]=i;
    int cnt = 1,u,v;
    ll s = 0;
    sort(e.begin(),e.end());
    int zz = sz(e);
    //if(zz < n - 1)  return -1;
    for(int i = 0; i<zz; i++)
    {
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            par[v] = u;
            s+=e[i].w;
            e1.push_back(e[i]);
            cnt++;
            if(cnt==n) break;
        }
    }
    if(e1.size())
    {
        e.clear();
        e = e1;
        e1.clear();
    }
    // cout<<cnt<<' '<<n<<endl;
    if(cnt==n) return s;
    return -1;
}
int main()
{
    int test;
    int n,m;
    sf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {
        e.clear();
        e1.clear();
        sf("%d %d",&n,&m);
        pf("Case %d:\n",cas);
        while(m--)
        {
            sf("%d %d %d",&get.u,&get.v,&get.w);
            e.push_back(get);
            //  cout<<"sz: "<<e.size()<<endl;
            pf("%lld\n",mst(n));
        }

    }
    return 0;
}

