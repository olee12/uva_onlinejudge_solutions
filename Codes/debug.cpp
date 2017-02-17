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
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 515
#define sf scanf
#define pf printf
#define INF 1061109567
vii graph[M];

struct parent
{
    int u,v,w;

};
parent par[M];
int dist[M];
struct node
{
    int u,w;
    node() {}
    node(int _u,int _w) : u(_u),w(_w) {}
    bool operator < (const node& p) const
    {
        return p.w<w;
    }
};
bool visited[M];
int G[M][M];
map<iii,bool> root1;
int dijkstra(int s,int t)
{
    for(int i = 0; i<M; i++)
    {
        visited[i]=0;
        dist[i]=INF;
        par[i].u=par[i].v=par[i].w=0;
    }
    dist[s]=0;
    priority_queue<node> Q;
    Q.push(node(s,0));
    int u,v,cst;
    while(Q.empty()==false)
    {
        u = Q.top().u;
        visited[u]=1;
        // if(u==t) return dist[t];
        Q.pop();

        for(int i= 0; i<M; i++)
        {
            if(G[u][i])
            {
                v = i;
                cst = G[u][i];
                //if(root1.find(mp(mp(u,v),cst))!=root1.end()) continue;
                if(visited[v]) continue;
                if(dist[v]>=dist[u]+cst)
                {
                    // cout<<u<<' '<<v<<dist[v]<<endl;
                    dist[v]=dist[u]+cst;
                    Q.push(node(v,dist[v]));
                    par[v].u=u;
                    par[v].w=cst;
                }
            }
        }
    }
    if(dist[t]<INF) return dist[t];
    return -1;

}
void display(int s,int t)
{
    if(s==t)
    {
        return;
    }
    display(s,par[t].u);
    // cout<<par[t].u<<" "<<t<<' '<<par[t].w<<endl;
    G[par[t].u][t]=0;
    root1[mp(mp(par[t].u,t),par[t].w)]=true;
}
int main()
{
    int n,m,s,t;
    while(sf("%d %d",&n,&m))
    {
        if(n==0 && m==0) return 0;
        root1.clear();
        memset(G,0,sizeof G);
        sf("%d %d",&s,&t);
        for(int i= 0; i<m; i++)
        {
            int u,v,w;
            sf("%d %d %d",&u,&v,&w);
            G[u][v]=w;
            // graph[u].pb(mp(v,w));
        }
        int res1,res2,res3;

        res1 = dijkstra(s,t);
     //   cout<<res1<<endl;
        if(res1==-1)
        {
            puts("-1");
            continue;
        }
        display(s,t);

        res2 = dijkstra(s,t);
       // cout<<res2<<endl;
        if(res2==-1)
        {
            puts("-1");
            continue;
        }
        display(s,t);
        while(res1==res2)
        {
            res2 = dijkstra(s,t);
            if(res2==-1) break;
            display(s,t);
        }
        if(res2!=-1) printf("%d\n",res2);
        else printf("-1\n");
    }
    return 0;
}

