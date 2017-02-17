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
typedef pair<ii,int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set<int> si;

#define     M       1005
#define     sz(a)   (int)a.size()
#define     all(a)  a.begin(),a.end()
#define     VII     vi :: iterator
#define     pb      push_back
#define     mp      make_pair
#define     fr      first
#define     sc      second
#define     mem(a)  memset(a,0,sizeof(a))
#define     INF     (1<<31)-1
#define     VIII `  vii :: iterator
bool bel_ford(int& n, viii al_edge)
{
   // cout<<"faf";
    int dist[M];
    for(int i = 0; i<M; i++) dist[i]=INF;
    dist[0]=0;
    for(int i = 0; i<=n-1; i++)
    {
        //cout<<i;
        for(int j = 0; j<sz(al_edge); j++)
        {
            int u = al_edge[j].fr.fr;
            int v = al_edge[j].fr.sc;
            int cost = al_edge[j].sc;
           // cout<<v<<' '<<u<<endl;
            if(dist[v] > dist[u]+ cost)
            {

              //  cout<<dist[v]<<' '<<dist[u]<<' '<<cost<<endl;
                dist[v] = dist[u]+ cost;
            }
        }

    }
    for(int j = 0; j<sz(al_edge); j++)
    {
        int u = al_edge[j].fr.fr;
        int v = al_edge[j].fr.sc;
        int cost = al_edge[j].sc;
        if(dist[v] > dist[u]+ cost)
        {
            return false;
        }
    }
    return true;

}
int main()
{
   // freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        viii al_edge;
        for(int i = 0; i<m; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            al_edge.pb(mp(mp(u,v),w));
        }
        bool flag = bel_ford(n,al_edge);
        if(flag == false ) puts("possible");
        else printf("not possible\n");
    }
    return 0;
}









