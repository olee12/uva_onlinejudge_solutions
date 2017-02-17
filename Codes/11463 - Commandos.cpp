#include<cstdio>
#include<algorithm>
#include<iostream>
#include<iterator>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set<int> si;

#define     M       105
#define     sz(a)   (int)a.size()
#define     all(a)  a.begin(),a.end()
#define     VII     vi :: iterator
#define     pb      push_back
#define     mp      make_pair
#define     fr      first
#define     sc      second
#define     mem(a)  memset(a,0,sizeof(a))
#define     INF     (1<<31)-1
int dist[M];
vi graph[M];
int bfs(int start,int to)
{
    bool taken[M];
    mem(taken);
    //mem(dist);
    dist[start] = 0;
    taken[start] = true;
    queue<int> Q;
    Q.push(start);
    while(Q.empty()==false)
    {
        int u = Q.front();
        Q.pop();
        if(u==to) return dist[to];
        for(int i = 0; i<sz(graph[u]); i++)
        {
            int v = graph[u][i];
            if(taken[v]==true) continue;
            taken[v]=true;
            dist[v]=dist[u]+1;
            Q.push(v);

        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    int test;
    int cas=1;
    scanf("%d",&test);
    while(test--)
    {
        int n;
        int m;

        scanf("%d",&n);
        scanf("%d",&m);
        for(int i = 0; i<m; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        int s,t;
        scanf("%d %d",&s,&t);
        int res = bfs(s,-1);
        int mx = 0;
        int pos = 0;
        int tmp[M];
        for(int i= 0;i<n;i++) tmp[i]=dist[i];
        for(int i = 0; i<n; i++)
        {
            if(i==t) continue;
            res = bfs(i,t);
            if(tmp[i] + res > mx )
            {
                mx = tmp[i]+res;
                pos = i;

            }
        }
        printf("Case %d: %d\n",cas++,mx);
        for(int i = 0;i<=n;i++) graph[i].clear();
    }
    return 0;//
}
