#include<bits/stdc++.h>
using namespace std;
#define M 30
int indegree[M];
struct node
{
    int u,w;
    node(int ver,int wet):u(ver),w(wet) {}

};
struct graph
{
    int sum=0;;
    int V;
    int cost[30]= {0};
    map<int,set<int> > edge;
    vector<int > finish;
    vector<int> new_edge;
    void dfs_visite(int u,bool visited[],stack<int> & s);
    void add_Edge(int u,int v,int w);
    void critical_path(int s,map<int,set<int> > edge);
    void top_s();
    void show()
    {
        for(int i = 0; i<V; i++) if(indegree[i]==0) new_edge.push_back(i);
    }
};
void graph:: add_Edge(int u,int v,int w)
{
    edge[u].insert(v);
    //cost[v]=w;
}
void graph::dfs_visite(int u,bool visited[],stack<int > &s)
{
    visited[u]=true;
    set<int> :: iterator it = edge[u].begin();
    for(; it!=edge[u].end(); it++)
    {
        if(visited[*it]==0) dfs_visite(*it,visited,s);
    }
    s.push(u);
}
void graph::critical_path(int s,map<int,set<int> > edge)
{
    for(int i = 0; i<new_edge.size(); i++)
    {
        if(s!=new_edge[i])
        {
            edge[s].insert(new_edge[i]);
        }
    }
    int dist[30];
    memset(dist,INT_MIN,sizeof dist);
    dist[s]=0;
    for(int i = 0; i<finish.size(); i++)
    {
        int u = finish[i];
        set<int> ::iterator it = edge[u].begin();
        for(; it!=edge[u].end(); it++)
        {
            if(dist[*it] < (dist[u]+cost[u]))
            {
                dist[*it]= dist[u]+cost[u];
                sum =  max(sum,dist[*it]);
            }
        }
    }
    //  for (int i = 0; i < 6; i++)
    //  (dist[i] == INT_MIN)? cout << "INF ": cout << dist[i] << " ";

}

void graph:: top_s()
{
    stack <int> ss;
    bool visited[30]= {0};
    for(int i =0; i<V; i++)
    {
        if(visited[i]==0) dfs_visite(i,visited,ss);
    }
    while(ss.empty()==0)
    {
        finish.push_back(ss.top());
        ss.pop();
    }
}
int main()
{
    int f = 0;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    char line[100];
    char h[10];
    int w;
    int t;
    scanf("%d ", &t);
    while(t--)
    {
        set<int> order;
        graph g;
        int i, j;
        while(gets(line))
        {
            if(line[0] == '\0')
                break;
            sscanf(line, "%s %d", h, &w);
            j = h[0]-'A';
            order.insert(j);
            g.cost[j]=w;
            for(i = strlen(line)-1; i >= 0; i--)
            {
                if(line[i] < 'A' || line[i] > 'Z')
                    break;
                order.insert(int(line[i]-'A'));
                g.add_Edge(line[i]-'A',j,w);
                indegree[j]++;
            }
        }
        g.V= order.size();
        g.show();
        g.top_s();
        for(int i = 0; i<g.V; i++)
        {


            g.critical_path(i,g.edge);

        }
        if(f) puts("");
        f=1;
        cout<<g.sum<<endl;
        memset(indegree,0,sizeof indegree);

    }
    return 0;
}
