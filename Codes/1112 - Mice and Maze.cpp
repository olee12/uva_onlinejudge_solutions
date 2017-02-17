#include<cstdio>
#include<iostream>
#include<vector>
#include<iterator>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
#define M 105
#define INF (1<<31)-1
struct node
{
    int u,w;
    node() {};
    node(int i,int j): u(i),w(j) {}
    bool operator < (const node& p) const
    {
        return w> p.w;
    }
};
int dist[M];
bool visited[M];
int main()
{
   // freopen("input.txt","r",stdin);
    int test;
    int n,e,t,m;
    scanf("%d",&test);
    bool f = false;
    while(test--)
    {
        if(f) puts("");f= true;
        scanf("%d %d %d %d",&n,&e,&t,&m);
        vector<int> graph[M];
        vector<int> cost[M];
        for(int i = 0; i<m; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            graph[u].push_back(v);
            cost[u].push_back(w);
        }
        int cnt = 0;
        for(int i = 1; i<=n; i++)
        {
            priority_queue<node> Q;
            Q.push(node(i,0));
            for(int j = 0; j<=n+1; j++)
            {
                dist[j]=INF;
                visited[j]=false;
            };
            dist[i]=0;
            while(Q.empty()==false)
            {
                int u = Q.top().u;
                Q.pop();
                visited[u] = true;
                if(u==e)
                {
                    break;
                }
                int sz = graph[u].size();
                for(int i = 0; i<sz; i++)
                {
                    int v = graph[u][i];
                    if(visited[v]==true) continue;
                    int cst = cost[u][i];
                  //  printf("%d %d %d\n",u,v,cst);
                    if(dist[v] > dist[u] + cst)
                    {
                        dist[v] = dist[u]+cst;
                        Q.push(node(v,dist[v]));
                    }
                }
            }
            if(dist[e]<=t) cnt++;
           // puts("\n\n\n");

        }
        printf("%d\n",cnt);
    }
    return 0;

}
