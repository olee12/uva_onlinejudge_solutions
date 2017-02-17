#include<cstring>
#include<bits/stdc++.h>
using namespace std;
#define M 255
#define pb push_back
#define ii pair<int,int>
#define mp make_pair
#define mem(a,b) memset(a,0,sizeof(a))
#define REP(i,j,k) for(i = j; i<=(k);i++)
struct node
{
    int u,w;
    node() {}
    node(int a,int b) : u(a),w(b) {}
    bool operator < (const node& p) const
    {
        return w> p.w;
    }
};
bool visited[M];
vector<int> graph[M];
int S[M];
int dist[M];
map<ii,int> cost;
int dij(int s,int c,int n)
{
    dist[s]=0;
    priority_queue<node> Q;
    Q.push(node(s,0));
    node tmp;
    int u,v,w;
    while(Q.empty()==false)
    {
        tmp = Q.top();
        Q.pop();
        u = tmp.u;
        w = tmp.w;
        visited[u]=true;
        if(u < c) continue;
        for(int i = 0; i<(int) graph[u].size(); i++)
        {
            v = graph[u][i];


            if(visited[v]==true) continue;
            if(dist[v] > (dist[u] + cost[mp(u,v)]) )
            {
                // visited[v]=1;
                dist[v] = (dist[u] + cost[mp(u,v)]);

                //cout<<' '<<u<<' '<<v<<' '<<dist[v]<<'\n';
                Q.push(node(v,dist[v]));
            }

        }
    }
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int m,n,c,k;
    int u,v,w;
    int i;
    // cout<<int(1e8)<<endl;
    while(scanf("%d %d %d %d",&n,&m,&c,&k),(c|k|m|n))
    {
        // printf("%d %d %d %d\n",n,m,c,k);
        cost.clear();
        REP(i,0,n)
        {
            //cout<<i<<endl;
            graph[i].clear();
            S[i]=0;
        }
        for(i = 0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            // printf("%d %d %d\n",u,v,w);
            graph[u].pb(v);
            graph[v].pb(u);
            cost[mp(u,v)]=w;
            cost[mp(v,u)]=w;
        }
        for(i = c-2; i>=0; i--)
        {
            S[i]=S[i+1] + cost[mp(i,i+1)];
            // cout<<S[i]<<' '<<i<<endl;
        }

        REP(i ,0,n)
        {
            dist[i]=1e8;
            visited[i]=false;
        }
        dij(k,c,n);
        // for(int i = 0; i<n; i++) cout <<dist[i]<<endl;
        int ans = INT_MAX;
        REP(i,0,c-1)
        {
            ans = min(ans,dist[i]+S[i]);
        }
        cout<<ans<<endl;

    }
    return 0;
}

