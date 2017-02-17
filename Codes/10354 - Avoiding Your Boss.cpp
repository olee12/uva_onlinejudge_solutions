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
#include<sstream>
#include<stack>
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
#define M 105
#define sf scanf
#define pf printf
#define INF 1e9
int s[M][M];
int d[M][M];
int visited[M];
int main()
{
    int a = INF;
    //cout<<a+a<<endl;
    int p,r,bh,of,yh,m;
    int u,v,w;
    while(sf("%d %d %d %d %d %d",&p,&r,&bh,&of,&yh,&m)==6)
    {
        memset(visited,0,sizeof visited);
        for(int i = 0; i<=p; i++)
            for(int j = 0; j<=p; j++)
                if(i!=j)
                    s[i][j]=d[i][j]=INF;
                else
                    s[i][j]=d[i][j]=0;
        // cout<<s[3][3]<<' '<<d[4][5]<<endl;;

        for(int i = 0; i<r; i++)
        {
            sf("%d %d %d",&u,&v,&w);
            s[u][v]=s[v][u]=d[u][v]=d[v][u]=w;
            // cout<<s[u][v]<<' '<<d[v][u]<<endl;
        }
        for(int k= 1; k<=p; k++)
            for(int i = 1; i<=p; i++)
                for(int j = 1; j<=p; j++)
                    s[i][j] = min(s[i][j],s[i][k]+s[k][j]);

        //   cout<<s[2][3]<<endl;
        for(int i=  1; i<=p; i++)
            if(s[bh][i]+s[i][of]==s[bh][of])
            {
                visited[i]=1;
                // cout<<i<<endl;
            }


        for(int k = 1; k<=p; k++)
            for(int i = 1; i<=p; i++)
                for(int j= 1; j<=p; j++)
                    if(!visited[i] && !visited[j] && !visited[k])
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        if(d[yh][m]!=INF && visited[m]==0 && visited[yh]==0) pf("%d\n",d[yh][m]);
        else puts("MISSION IMPOSSIBLE.");
    }
    return 0;

}




















/*
int graph[M][M];
int par[M];
int dist[M];
bool visited[M];
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
int n;
int dijkstra(int s,int t,int c)
{
    if(c==0)
    {
        for(int i = 0; i<=n+2; i++)
        {
            dist[i]=INF;
            par[i]=0;
        }
        dist[s]=0;
        priority_queue<node> Q;
        Q.push(node(s,0));
        if(s==t) return 0;
        int u,v,cst;
        while(Q.empty()==false)
        {
            u = Q.top().u;
            Q.pop();
            for(int i= 0; i<=n; i++)
            {
                if(graph[u][i])
                {
                    cst = graph[u][i];
                    v = i;
                    if(dist[v]>=dist[u]+cst)
                    {
                        par[v]=u;
                        dist[v]=dist[u]+cst;
                        Q.push(node(v,dist[v]));
                    }
                }
            }
        }
        if(dist[t]!=INF) return dist[t];
        return -1;
    }

    if(visited[s]) return -1;
    if(visited[t]) return -1;
    for(int i = 0; i<=n+2; i++)
    {
        dist[i]=INF;
        par[i]=0;
        //  visited[i]=false;
    }
    dist[s]=0;
    priority_queue<node> Q;
    Q.push(node(s,0));
    if(s==t) return 0;
    int u,v,cst;
    while(Q.empty()==false)
    {
        u = Q.top().u;
        Q.pop();
        for(int i= 0; i<M; i++)
        {
            if(graph[u][i])
            {
                if(visited[i] && c) continue;
                cst = graph[u][i];
                v = i;
                if(dist[v]>=dist[u]+cst)
                {
                    par[v]=u;
                    dist[v]=dist[u]+cst;
                    Q.push(node(v,dist[v]));
                }
            }
        }
    }
    if(dist[t]!=INF) return dist[t];
    return -1;
}
void display(int s,int t)
{
    if(s==t) return;
    display(s,par[t]);
    graph[par[t]][t]=0;
    graph[t][par[t]]=0;
    visited[par[t]]=1;
    visited[t]=1;
    // cout<<par[t]<<' '<<t<<endl;
}
int main()
{
    // P, R, BH, OF, YH and M
    int p,r,bh,of,yh,m;
    int u,v,w;
    while(sf("%d %d %d %d %d %d",&p,&r,&bh,&of,&yh,&m)==6)
    {
        n=p;

        memset(graph,0,sizeof graph);
        memset(visited,0,sizeof visited);
        visited[of]=1;
        visited[bh]=1;
        for(int i = 0; i<r; i++)
        {
            sf("%d %d %d",&u,&v,&w);
            graph[u][v]=w;
            graph[v][u]=w;
        }
        int res1,res2;
        res1=dijkstra(bh,of,0);
        display(bh,of);
        res2 = dijkstra(bh,of,0);
        // cout<<res2<<endl;
        while(res1==res2)
        {
            display(bh,of);
            //  puts("");
            res2 = dijkstra(bh,of,0);
            if(res2==-1) break;
            // display(bh,of);
        }
        //if(res1!=-1) display(bh,of);
        res2=dijkstra(yh,m,1);
        if(res2==-1) puts("MISSION IMPOSSIBLE.");
        else pf("%d\n",res2);
    }
    return 0;
}
*/
