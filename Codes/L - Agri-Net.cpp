
#include<iostream>
#include<cstdio>
#include<iterator>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
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
#define mp make_pair
#define fr first
#define sc second
#define sf scanf
#define pf printf
#define INF 2147483645
typedef long long ll;
#define M 1005
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
int par[M];
vector<edge> e;
edge get;
int mx;
int find_par(int r)
{
    return r==par[r]? r : par[r] = find_par(par[r]);
}
int mst(int n)
{
    for(int i = 0; i<=n+2; i++) par[i]=i;
    int u,v,s=0,cnt = 1;
    int zz = (int) e.size();
    for(int i= 0; i<zz; i++)
    {
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            s += e[i].w;
            cnt++;
            if(cnt==n) break;
        }
    }
    return s;
}
int main()
{
    int n,m;
    int u,v,w;
    while(sf("%d",&n)==1)
    {
        for(int i= 1; i<=n; i++)
        {
            for(int j= 1; j<=n; j++)
            {
                sf("%d",&w);
                get.u = i;
                get.v = j;
                get.w = w;
                e.push_back(get);
            }
        }
        sort(e.begin(),e.end());
        mx = mst(n);
        pf("%d\n",mx);
        e.clear();
    }
    return 0;
}
