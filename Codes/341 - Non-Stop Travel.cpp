#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define M 15
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define fr first
#define sc second
#define INF  (1<<31)-1;
int dist[15];
int par[15];
bool visited[15];
struct node
{
    int u,w;
    node() {}
    node(int a,int b): u(a),w(b) {}
    bool operator < (const node& p) const
    {
        return w>p.w;
    }
};
void path(int s,int v)
{
    if(s==v)
    {
        printf("%d",s);
        return;
    }
    path(s,par[v]);
    printf(" %d",v);
}
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    int cas = 1;
    int u,v,w;
    int s,d;
    int x;
    while(scanf("%d",&n),n)
    {
        vii graph[M];
        for(u = 1; u<=n; u++)
        {
            scanf("%d",&x);
            for(int i = 0; i<x; i++)
            {
                scanf("%d %d",&v,&w);
                graph[u].pb(mp(v,w));
            }
        }
        scanf("%d %d",&s,&d);
        for(int i = 0; i<=12; i++)
        {
            dist[i]=INF;
            visited[i]=false;
            par[i]=0;
        }
        dist[s]=0;
        priority_queue<node> Q;
        Q.push(node(s,0));
        while(Q.empty()==false)
        {
            u = Q.top().u;
            Q.pop();
            if(u==d) break;
            visited[u]=true;
            x = sz(graph[u]);
            for(int i = 0; i<x; i++)
            {
                v = graph[u][i].fr;
                if(visited[v]==true) continue;
                int cst = graph[u][i].sc;
                if(dist[v]> dist[u]+cst)
                {
                    par[v]=u;
                    dist[v] = dist[u]+cst;
                    Q.push(node(v,dist[v]));

                }
            }
        }
        printf("Case %d: Path = ",cas++);
        path(s,d);
        printf("; %d second delay\n",dist[d]);


    }
    return 0;
}
