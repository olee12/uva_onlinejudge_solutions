#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 505
#define sf scanf
#define pf printf
#define INF 2147483645
int dist[M][2];
struct node
{
    int u,w,kind;
    node() {}
    node(int _u,int _w,int _k) : u(_u),w(_w),kind(_k) {}
    bool operator < (const node& p) const
    {
        return p.w<w;
    }
};
void init()
{
    for(int i = 0; i<M; i++) dist[i][0]=dist[i][1]=INF;
}
void dijkstra(vii graph[])
{
    priority_queue<node> Q;
    Q.push( node(0,0,0) );
    int u,v,k,cst,go;
    while(Q.empty()==false)
    {
        u = Q.top().u;
        k = Q.top().kind;
        Q.pop();
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            v = graph[u][i].first;
            cst = graph[u][i].second;
            go = 1-k;
            if(dist[v][go] > dist[u][k] + cst)
            {
                dist[v][go] = dist[u][k] + cst;
                Q.push(node(v,dist[v][go],go));
            }
        }
    }

}
int main()
{
    int n,m;
    int cas = 1;
    while(scanf("%d %d",&n,&m)==2)
    {
        vii graph[M];
        int u,w,v;
        while(m--)
        {
            scanf("%d %d %d",&u,&v,&w);
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
        }
        init();
        dist[0][0]=0;
        dijkstra(graph);
        pf("Set #%d\n",cas++);
        if(dist[n-1][0]!=INF)
            pf("%d\n",dist[n-1][0]);
        else pf("?\n");

    }
    return 0;

}
