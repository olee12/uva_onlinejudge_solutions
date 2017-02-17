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

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set<int> si;

#define     M       150
#define     sz(a)   (int)a.size()
#define     all(a)  a.begin(),a.end()
#define     VII     vi :: iterator
#define     pb      push_back
#define     mp      make_pair
#define     fr      first
#define     sc      second
#define     mem(a)  memset(a,0,sizeof(a))
#define     INF     (1 << 30)*-1
#define     VIII `  vii :: iterator
int dist[M];
vi graph[M];
bool taken[M];
bool win;
int n;
void dfs(int u)
{
    taken[u] = true;
    if(u == n)
    {
        win = true;
        return;
    }
    for(int i = 0; i < sz(graph[u]); i++)
    {
        int v = graph[u][i];
        if(taken[v] == false) dfs(v);
    }
}
void bel_ford(viii al_edge)
{
    for(int i = 0; i < M; i++) taken[i] = false;
    for(int i = 0; i < M; i++) dist[i] = INF;
    dist[1] = 100;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < sz(al_edge); j++)
        {
            int u = al_edge[j].fr.fr;
            int v = al_edge[j].fr.sc;
            int cst = al_edge[j].sc;
            if(dist[v] < dist[u] + cst && dist[u] > 0)
            {
                dist[v] = dist[u] + cst;
            }
        }
    }
    win = false;
    for(int j = 0; j < sz(al_edge); j++)
    {
        int u = al_edge[j].fr.fr;
        int v = al_edge[j].fr.sc;
        int cst = al_edge[j].sc;
        if(dist[v] < dist[u] + cst && dist[u] > 0)
        {
            dfs(u);
            if(win)
                dist[n] = 1000;
            return;
        }
    }
    return ;
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d", &n) && n != -1)
    {
        viii al_edge;
        for(int u = 1; u <= n; u++)
        {
            int w, m, v;
            scanf("%d %d", &w, &m);
            for(int i = 0; i < m; i++)
            {
                scanf("%d", &v);
                al_edge.pb(mp(mp(u, v), (w)));
                graph[u].pb(v);
            }

        }
        bel_ford(al_edge);
        if(dist[n] > 0)
        {

            printf("winnable\n");
        }
        else
        {
            printf("hopeless\n");

        }
        for(int i = 0; i < M; i++) graph[i].clear();

    }
    return 0;
}




