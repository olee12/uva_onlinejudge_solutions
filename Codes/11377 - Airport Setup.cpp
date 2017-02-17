#include <iostream>
#include <vector>
#include <iterator>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <limits.h>
using namespace std;
#define M 2010
#define mem(a,b) memset(a,b,sizeof(a));
#define REP(i,j,k) for(i = j;i<=(k);i++)
#define pb push_back
int n,m,k,q;
struct node
{
    int u,w;
    node() {}
    node(int a,int b):u(a),w(b) {}
    bool operator < (const node& p) const
    {
        return w > p.w;
    }
};
int dist[M];
bool visited[M];
bool have[M];
vector<int> graph[M];
int dij(int start,int to)
{
    int i;
    REP(i,0,n)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }

    dist[start]=have[start]?1:0;

    priority_queue<node> Q;
    Q.push(node(start,dist[start]));
    node tmp;
    int u,v;
    int cost;
    while(Q.empty()==false)
    {
        tmp = Q.top();
        Q.pop();
        u = tmp.u;

        cost = tmp.w;
        visited[u]=true;
        if(u==to) return dist[to];
        for(int i = 0; i<(int) graph[u].size(); i++)
        {

            v = graph[u][i];

            if(visited[v]==true) continue;
            //printf("%d %d %d\n",dist[u],dist[v],have[v]);
            if(dist[v] > (dist[u]+have[v] ))
            {

                dist[v]=dist[u]+have[v];
                Q.push(node(v,dist[v]));
            }
        }
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE

    int test;
    int i,j;
    int u,v,a,b;
    int cas=1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&n,&m,&k);
        REP(i,0,n) have[i]=true;
        REP(i,0,k-1)
        {
            scanf("%d",&a);
            have[a]=0;
        }
        REP(i,0,m-1)
        {
            scanf("%d %d",&u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        REP(i,0,q-1)
        {
            scanf("%d %d",&a,&b);
            if(a==b)
            {
                printf("0\n");
                continue;
            }
            int res = dij(a,b);
            printf("%d\n",res);

        }
        puts("");
        REP(i,0,n) graph[i].clear();

    }
    return 0;
}

