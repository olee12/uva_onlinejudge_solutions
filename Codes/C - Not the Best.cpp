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
#define INF 21474836450
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
#define M 5010
#define mp make_pair
struct node
{
    int u;
    ll w;
    node() {}
    node(int _u,ll _w) : u(_u),w(_w) {}
    bool operator < (const node& p) const
    {
        return w>p.w;
    }
};
vii graph[M];
ll dist[M][2];
void dijkstra(int s,int t,int n)
{
    for(int i=0; i<=n+5; i++)
    {
        dist[i][0]=dist[i][1]=INF;
    }
    dist[s][0]=0;
    priority_queue<node> Q;
    Q.push(node(s,0));
    while(Q.empty()==false)
    {
        int u = Q.top().u;
        ll d = Q.top().w;
        Q.pop();
        int zz = (int) graph[u].size();
        for(int i = 0; i<zz; i++)
        {
            int v = graph[u][i].X;
            ll cst =(ll) graph[u][i].Y;

            if(dist[v][0] > d + cst)
            {
                dist[v][1] = dist[v][0] ;
                dist[v][0] = d + cst;
                Q.push(node(v,dist[v][0]));
                // if(dist[v][1]<dist[v][0]) swap(dist[v][1],dist[v][0]);
            }
            else if((dist[v][1] > d + cst) )
            {
                if(d + cst == dist[v][0]) continue;
                dist[v][1] = d + cst;
                Q.push(node(v,dist[v][1]));
                // cout<<u<<' '<<v<<' '<<dist[v][1]<<endl;
                // if(dist[v][1]<dist[v][0]) swap(dist[v][1],dist[v][0]);
            }

        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    int test;
    int u,v,w;
    int n,m;
    sf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {
        // cout<<cas<<endl;
        sf("%d %d",&n,&m);
        for(int i = 0; i<m; i++)
        {
            sf("%d %d %d",&u,&v,&w);
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
        }
        dijkstra(1,n,n);
        pf("Case %d: %lld\n",cas,dist[n][1]);
        for(int i = 0; i<=n; i++) graph[i].clear();

    }
    return 0;
}
