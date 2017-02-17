#include<cstring>
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<limits.h>
#include<algorithm>
using namespace std;
#define NINF INT_MIN
#define M 45
struct Box
{
    int dimension;
    int e[20];
    bool operator < (const Box& b) const
    {
        for(int i = 1; i<=dimension; i++)
        {
            if(e[i]>=b.e[i]) return 0;
        }
        return 1;
    }
    void boxsort()
    {
        sort(e+1, e+1+dimension);
    }
};
Box box[M];
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
    map<int,set<int> > edge;
    vector<int > finish;
    vector<int> new_edge;
    void dfs_visite(int u,bool visited[],stack<int> & s);
    void add_Edge(int u,int v,int w);
    void critical_path(int s,map<int,set<int> > edge);
    void top_s();
    void show()
    {
        for(int i = 1; i<=V; i++) if(indegree[i]==0) new_edge.push_back(i);
        cout<<new_edge[0]<<endl;
        map<int,set<int> > :: iterator it = edge.begin();
        for(; it!=edge.end(); it++)
        {
            cout<<it->first<<" : ";
            set<int> :: iterator it2 = it->second.begin();
            for(; it2!=it->second.end(); it2++)
            {
                cout<<' '<<*it2;
            }
            puts("");
        }
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
    // cout<<u<<' '<<endl;
    set<int> :: iterator it = edge[u].begin();
    for(; it!=edge[u].end(); it++)
    {
        if(visited[*it]==0) dfs_visite(*it,visited,s);
    }
    s.push(u);
}
void graph::critical_path(int s,map<int,set<int> > edge)
{
    // cout<<new_edge.size()<<endl;

    for(int i = 0; i<new_edge.size(); i++)
    {
        if(s!=new_edge[i])
        {
            edge[s].insert(new_edge[i]);
        }
    }
    int dist[V+5];
    memset(dist,NINF,sizeof dist);
    dist[s]=0;
    for(int i = 0; i<finish.size(); i++)
  //  for(int i = 1;i<=V;i++)
    {
        int u = finish[i];

        //if(dist[u]!=NINF)
        {
            set<int> ::iterator it = edge[u].begin();
            for(; it!=edge[u].end(); it++)
            {
                if(dist[*it] < (dist[u]+1))
                {
                    dist[*it]= dist[u]+1;
                    //cout<<dist[*it]<<endl;
                    sum =  max(sum,dist[*it]);

                }
            }
        }
    }
    for (int i = 1; i <=V; i++)
        (dist[i] == INT_MIN)? cout << "INF ": cout << dist[i] << " ";
    cout<<endl;

}

void graph:: top_s()
{
    stack <int> ss;
    bool *visited= new bool[V+1];
    for(int i = 1; i<=V; i++) visited[i]=false;
    for(int i =1; i<=V; i++)
    {
        if(visited[i]==0) dfs_visite(i,visited,ss);
    }
    while(ss.empty()==0)
    {
        finish.push_back(ss.top());
        cout<<ss.top()<<' ';
        ss.pop();
    }
    cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int k,n;
    while(scanf("%d %d",&k,&n)==2)
    {

        graph g;
        g.V=k;
        for(int i = 1; i<=k; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                scanf("%d",&box[i].e[j]);
                // cout<<box[i].e[j]<<endl;
                box[i].dimension=n;
            }
            box[i].boxsort();

        }
        for(int i = 1; i<=k; i++)
        {
            for(int j = 1; j<=k; j++)
            {
                //cout<<j<<endl;
                if(box[i] < box[j])
                {
                    //cout<<i<<' '<<j<<endl;
                    g.add_Edge(j,i,1);
                    indegree[i]++;
                }
            }
        }
        g.show();
        g.top_s();
        cout<<"sz: "<<g.edge.size()<<endl;


        for(int i = 1; i<=k; i++)
        {
            g.critical_path(i,g.edge);
        }
        cout<<g.sum<<endl;

    }
}
