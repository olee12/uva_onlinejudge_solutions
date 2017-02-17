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
struct pnt
{
    int x,y;
};
int people[M];
struct edge
{
    int u,v;
    double w;
    bool operator < (const edge& b) const
    {
        return w < b.w;
    }

};
pnt ara[M];
int par[M];
vector<edge> e;
vector<pair<int,double> > graph[M];
edge get;
//int n,m;
int pos;
bool visited[M];
///functions__
int find_par(int r);
void read(int n);
void make_edge(int n);
double dist(pnt a,pnt b);
double mst(int n);
int start;
double mx;
double mmst;
void dfs(int u,double cst);
///main function__
int main()
{
    int test;
    sf("%d",&test);
    while(test--)
    {
        int n;
        sf("%d",&n);
        read(n);
        make_edge(n);
        sort(all(e));



        mmst=mst(n);
        mx = 0;
        for(int i= 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++) visited[j]=0;
            start = i;
            dfs(i,0);
        }
        pf("%.2lf\n",mx);
        e.clear();
        for(int i = 0;i<=n+2;i++) graph[i].clear();

    }
    return 0;
}

int find_par(int r)
{
    return (par[r]==r)? r : par[r] = find_par(par[r]);
}

void read(int n)
{
    int x,y,p;
    for(int i =1; i<=n; i++)
    {

        sf("%d %d %d",&ara[i].x,&ara[i].y,&people[i]);
    }
}


double dist(pnt a,pnt b)
{
    return sqrt( (double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}


void make_edge(int n)
{
    for(int i = 1; i<n; i++)
        for(int j = i+1; j<=n; j++)
        {
            double d = dist(ara[i],ara[j]);
            get.u = i;
            get.v = j;
            get.w = d;
            e.push_back(get);
        }
}

double mst(int n)
{
    for(int k = 1; k<=n+2; k++) par[k]=k;
    int u,v,cnt=1;
    double s = 0;
    int zz = (int)e.size();
    for(int i= 0; i<zz; i++)
    {
        // if(i==pos) continue;
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            graph[e[i].u].pb(mp(e[i].v,e[i].w));
            graph[e[i].v].pb(mp(e[i].u,e[i].w));
            par[u]=v;
            s+= (e[i].w);
            cnt++;
            if(cnt == n) break;
        }
    }
    return s;
}
void dfs(int u,double cst)
{
    visited[u]=true;
    if(u!=start) mx = max(mx,double(people[u]+people[start])/(mmst-cst));
   // cout<<(people[start] + people[u])<<' '<<mmst<<' '<<cst<<' '<<(double)(people[start] + people[u]) / (mmst-cst) <<endl;

    int zz = sz(graph[u]);
    for(int i = 0;i<zz;i++)
    {
        int v = graph[u][i].fr;
        double c = graph[u][i].sc;
        if(visited[v]==false) dfs(v,max(cst,c));
    }
}
