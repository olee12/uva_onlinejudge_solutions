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
#define M 10000
#define sf scanf
#define pf printf
#define INF 2061109567
struct node
{
    int u,w,t;
    node() {}
    node(int _u,int _t,int _w): u(_u),w(_w),t(_t) {}
    bool operator < (const node& p) const
    {
        if(p.t!=t)
            return p.t<t;
        else return p.w<w;
    }
};
struct iiii
{
    int u,v,time,len;
    iiii() {}
    iiii(int _v,int t,int w):v(_v),time(t),len(w) {}
};
int dist[M][3];
vector<iiii> graph[M];
void dijkstra(int s,int t,int n)
{
    for(int i = 0; i<n+2; i++)
    {
        dist[i][0]=dist[i][1]=INF;
        //visited[i]=false;
    }
    priority_queue<node> Q;
    dist[s][0]=0;
    dist[s][1]=0;
    Q.push(node(s,0,0));
    int u,v,cst,tm;
    while(Q.empty()==false)
    {
        u = Q.top().u;
        Q.pop();
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            v = graph[u][i].v;
            tm = graph[u][i].time;
            cst = graph[u][i].len;
            if(dist[v][0]> dist[u][0]+tm)
            {

                dist[v][0]=dist[u][0]+tm;
                dist[v][1]=dist[u][1]+cst;
                Q.push(node(v,dist[v][0],dist[v][1]));
               // cout<<u<<' '<<v<<' '<<dist[v][0]<< ' '<<dist[v][1]<<endl;
            }
            else if(dist[v][0]== dist[u][0] + tm)
                if(dist[v][1]> dist[u][1]+cst)
                {
                    dist[v][1]=dist[u][1]+cst;
                    Q.push(node(v,dist[v][0],dist[v][1]));
                   // cout<<u<<' '<<v<<' '<<dist[v][0]<< ' '<<dist[v][1]<<endl;
                }

        }

    }
}
int main()
{
    int n,m;
    int x,y;
    int w,t;
    int u,v;
    int q;
    int test;
    sf("%d",&test);
    while(test--)
    {
        sf("%d %d",&n,&m);

        for(int i = 0; i<m; i++)
        {
            sf("%d %d %d %d",&x,&y,&t,&w);
            graph[x].push_back(iiii(y,t,w));
            graph[y].push_back(iiii(x,t,w));
        }
        sf("%d",&q);
        while(q--)
        {
            sf("%d %d",&u,&v);
            dijkstra(u,v,n);
            if(dist[v][0]!=INF)
            {
                pf("Distance and time to reach destination is %d & %d.\n",dist[v][1],dist[v][0]);

            }
            else pf("No Path.\n");
        }
        for(int i = 0; i<n+3; i++) graph[i].clear();
        if(test) puts("");
    }
    return 0;
}
