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

void RD(int &x)
{
    scanf("%d",&x);
}
void RD(ll &x)
{
    scanf("%I64d",&x);
}
void RD(double &x)
{
    scanf("%lf",&x);
}
void RD(int &x,int &y)
{
    scanf("d",&x,&y);
}
void RD(ll &x,ll &y)
{
    scanf("I64d",&x,&y);
}
void RD(double &x,double &y)
{
    scanf("lf",&x,&y);
}
void RD(char *s)
{
    scanf("%s",s);
}
void RD(char &s)
{
    scanf("%c",&s);
}
void RD(string &s)
{
    cin>>s;
}

void PR(int x)
{
    printf("%d\n",x);
}
void PR(int x,int y)
{
    printf("%d %d\n",x,y);
}
void PR(ll x)
{
    printf("%I64d\n",x);
}
void PR(char x)
{
    printf("%c\n",x);
}
void PR(char *x)
{
    printf("%s\n",x);
}
void PR(string x)
{
    cout<<x<<endl;
}

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
#define M 100500
#define sf scanf
#define pf printf
#define INF 1000000000000
#define mp make_pair
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


struct node
{
    int u;
    ll w;
    node() {}
    node(int a,ll b) : u(a), w(b) {}

    bool operator < (const node& p) const
    {
        return w > p.w;
    }
};
ll dist[M];
bool visited[M];
vii graph[M];
int par[M];
int dijkstra(int s,int t)
{
    for(int i = 0; i<M; i++)
    {
        dist[i]=INF;
        visited[i]=0;
        par[i]=0;
    }
    priority_queue<node> Q;
    dist[s] = 0;
    Q.push(node(s,0));
    while(Q.empty()==0)
    {
        int u = Q.top().u;
        Q.pop();
        visited[u] = true;
        // if(u==t) return dist[t];
        int zz = (int) graph[u].size();
        for(int i= 0; i<zz; i++)
        {
            int v = graph[u][i].fr;
            int cst = graph[u][i].sc;
            if(visited[v]) continue;
            if(dist[v] > dist[u]+ cst)
            {

                dist[v] = dist[u]+cst;
                Q.push(node(v,dist[v]));
                par[v]=u;
            }
        }
    }
    if(dist[t]!=INF) return 1;
    return -1;
}
vi path;
void display(int s,int t)
{
    if(t==s) return ;
    display(s,par[t]);
    path.pb(t);
    // pf(" %d ",t);
}
int main()
{
    // cout<<INF<<endl;

    int test;
    // sf("%d",&test);
    int u,v,w,m,n;
    int s,t;
    // while(test--)
    //{

    sf("%d %d",&n,&m);
    for(int i= 0; i<m; i++)
    {
        sf("%d %d %d",&u,&v,&w);

        graph[u].pb(mp(v,w));
        graph[v].pb(mp(u,w));

    }
    int res = dijkstra(1,n);
    if(res != -1)
    {
        path.clear();
        display(1,n);
        pf("%d",1);
        for(int i = 0; i<(int)path.size()-1; i++) pf(" %d",path[i]);
        pf(" %d\n",n);
    }
    else puts("-1");
    //  }

    return 0;
}
