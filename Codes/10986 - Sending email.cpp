#include<cstring>
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define M 20005
struct node
{
    int u,w;
    node(int _u,int _w)
    {
        u = _u;
        w = _w;
    }
    bool operator < (const node& b) const
    {
        return w > b.w;
    }
};
vector<int> cost[M];
map<int,vector<int> > graph;
int dist[M];

int dijkstra(int s,int to)
{
    memset(dist,1e6,sizeof dist);
    priority_queue<node> Q;
    dist[s]=0;
    Q.push(node(s,0));
    while(Q.empty() == false)
    {
        node top = Q.top();
        Q.pop();
        int u = top.u;
         if(u==to) return dist[u];


        for(int i = 0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(dist[v] > (dist[u] + cost[u][i]))
            {
               // cout<<cost[u][i]<<endl;;
                dist[v]=dist[u]+cost[u][i];
                Q.push(node(v,dist[v]));
               // cout<<dist[v]<<endl;

            }
        }
    }
    //for (int i = 0; i < 3; i++)
        //(dist[i] == 1e6)? cout << "INF ": cout << dist[i] << " ";

    return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,m,t,s;
    int u,v,w;
    int test;
    int cas=1;
    scanf("%d",&test);
    while(test--)
    {
        //for(int i = 0; i<M; i++) cost[i].clear();
        scanf("%d %d %d %d",&n,&m,&s,&t);
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        //
        int res = dijkstra(s,t);
        if(res!=-1)
        {
            printf("Case #%d: %d\n",cas++,dist[t]);
        }
        else printf("Case #%d: unreachable\n",cas++);
        for(int i = 0; i<M; i++) cost[i].clear();
        graph.clear();
    }
    return 0;

}
