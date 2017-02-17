#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<iterator>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define M 10050
ll dist[M];
ll s ,mx_dist;

void cle(ll *a,ll n,ll val)
{
    for(ll i = 0; i<n; i++)
        a[i]=val;
}
void bfs(vpll graph[],ll start)
{
    queue<ll> Q;
    dist[start] = 0;
    Q.push(start);
    while(Q.empty()==false)
    {
        ll u = Q.front();
        Q.pop();
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            ll v = graph[u][i].first;
            if(dist[v]>-1) continue;
            ll cst = graph[u][i].second;
            dist[v]=dist[u]+cst;
            Q.push(v);
            if(dist[v]>mx_dist)
            {
                mx_dist = dist[v];
                s = v;
            }
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);

    char str[200];
    while(cin.peek()!=EOF)
    {
        //if(strlen(str)==0) return 0;
        vpll graph[M];
        ll u,v,w;
        int cnt = 0;
        //sscanf(str,"%lld %lld %lld",&u,&v,&w);
        //graph[u].pb(mp(v,w));
        //graph[v].pb(mp(u,w));
        while(gets(str) && strlen(str)>0)
        {
            sscanf(str,"%lld %lld %lld",&u,&v,&w);
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
            cnt++;
        }
        s = 1;
        mx_dist=0;
        cle(dist,cnt+2,-1);
        bfs(graph,1);
        cle(dist,cnt+2,-1);
        mx_dist = 0;
        bfs(graph,s);
        printf("%lld\n",mx_dist);
    }
    return 0;
}
