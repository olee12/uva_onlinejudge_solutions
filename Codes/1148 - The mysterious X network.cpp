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
#include<stack>
#include<sstream>
#include<cctype>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 100005
#define sf scanf
#define pf printf
int dist[M];
int bfs(int s,int t,int n,vi graph[])
{

    memset(dist,-1,sizeof dist);
    queue<int> Q;
    Q.push(s);
    dist[s]=0;
    while(Q.empty()==false)
    {
        int u = Q.front();
        Q.pop();
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            int v = graph[u][i];
            if(dist[v]!=-1) continue;
            dist[v]=dist[u]+1;
            Q.push(v);
            if(v==t) return dist[t];
        }
    }
}
int main()
{
    int test;
    int n;
    int x,c,v;
    sf("%d",&test);
    while(test--)
    {
        vi graph[M];
        scanf("%d",&n);
        for(int i = 0; i<n; i++)
        {
            scanf("%d %d",&x,&c);
            for(int j=0; j<c; j++)
            {
                scanf("%d",&v);
                graph[x].pb(v);
                graph[v].pb(x);
            }

        }
        int s,t;
        sf("%d %d",&s,&t);
        pf("%d %d %d\n",s,t,bfs(s,t,n,graph)-1);
        if(test) puts("");
    }
    return 0;
}
