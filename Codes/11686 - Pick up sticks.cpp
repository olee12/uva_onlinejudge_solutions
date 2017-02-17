#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
#define VII vector<int> :: iterator
#define sz(a) (int)a.size()
#define pb push_back
#define M 1000005
int colour[M];
int path[M];
int ind;
int cl = 0;
vector<int> graph[M];
stack< int > s;
void dfs(int u)
{
    if(colour[u]==2 || cl )  return ;
    if(colour[u]==1)
    {
        cl = 1;
        return;
    }
    colour[u]=1;
    VII i  ;
    for(i = graph[u].begin(); i!=graph[u].end(); i++)
    {
        dfs(*i);
    }

    colour[u]=2;
    path[ind++]=u;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int m,n,a,b;
    while(scanf("%d %d",&n,&m),(n|m))
    {
        for(int i = 1; i<=n; i++) graph[i].clear();
        memset(colour,0,M);
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].pb(b);
        }
        cl = 0;
        ind = 0;
        for(int i = 1; i<=n; i++)
        {
            if(colour[i]==0) dfs(i);
        }
        if(cl==0)
        {
            for(int i = ind-1; i>=0; i--) printf("%d\n",path[i]);
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}

