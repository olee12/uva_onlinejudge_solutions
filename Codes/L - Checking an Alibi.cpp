#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
typedef long long ll;


#define sf scanf
#define pf printf
#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define INF 214748364
#define X first
#define Y second
#define mp make_pair
#define M 510
struct node
{
    int u,w;
    node() {}
    node(int _u,int _w): u(_u),w(_w) {}
    bool operator < (const node& p) const
    {
        return w>p.w;
    }
};
vii graph[M];
int dist[M];
void dijkstra(int s,int f)
{
    for(int i = 0; i<f+2; i++)
    {
        dist[i] = INF;
    }
    priority_queue<node> Q;
    Q.push(node(s,0));
    dist[s]=0;
    int u,v,cst;
    while(Q.empty()==false)
    {
        u = Q.top().u;
        Q.pop();
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            v = graph[u][i].X;
            cst = graph[u][i].Y;
            if(dist[v]> dist[u]+cst)
            {
                dist[v] = dist[u]+cst;
                Q.push(node(v,dist[v]));
            }
        }
    }
}
int pos[M];
vi cow;
int main()
{
    int zz;
    int p,c,f,m;
    int u,v,w;
    while(sf("%d %d %d %d",&f,&p,&c,&m)==4)
    {
        for(int i = 0; i<p; i++)
        {
            sf("%d %d %d",&u,&v,&w);
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
        }
        dijkstra(1,f);
        for(int i= 0; i<c; i++) sf("%d",pos+i);
        for(int i = 0; i<c; i++) if(dist[pos[i]]<=m)
            {
                cow.push_back(i);
            }
        pf("%d\n",zz = (int)cow.size());
        for(int i= 0; i<zz; i++) pf("%d\n",cow[i]+1);
        for(int i = 0; i<=f+2; i++) graph[i].clear();
        cow.clear();
    }
    return 0;
}
