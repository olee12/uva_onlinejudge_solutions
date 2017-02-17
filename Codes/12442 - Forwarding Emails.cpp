#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
#define M 50005
bool visited[M];
int graph[M];
int sum[M];
int cnt = 0;
int dfs(int u)
{

    visited[u]=true;
    int par=0;
    if(graph[u]!=-1 && visited[graph[u]]==false)
    {
        par += (1+ dfs(graph[u]));
    }
    visited[u]=false;
    return sum[u] = par;
}
int main()
{
    // freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {
        memset(visited,0,sizeof visited);
        int ara[M];
        int n;
        scanf("%d",&n);
        for(int i = 0; i<=n+2; i++)
        {
            graph[i]=-1;
            sum[i]=-1;
        }

        for(int i = 0; i<n; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u]=v;
        }
        int mx = 0;
        int pos;
        for(int i = 1; i<=n; i++)
        {
            if(sum[i]==-1) dfs(i);
            // cout<<sum[i]<<endl;
            if(sum[i]>mx)
            {
                pos = i;
                mx = sum[i];
            }
        }
        printf("Case %d: %d\n",cas,pos);
    }
}

/*
#include<stdio.h>
#include<string.h>
#define M 50005
bool visited[M];
int graph[M];
int call[M];

int dfs(int u)
{

    visited[u]=true;
    int par=0;
    if(graph[u]!=-1 && visited[graph[u]]==false)
    {
        par += (1+ dfs(graph[u]));
    }
    visited[u]=false;
    call[u]=1;
   return par;
}
int main()
{
   // freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {

        int ara[M];
        int n;
        scanf("%d",&n);
        for(int i = 0; i<=n+2; i++)
        {
            graph[i]=-1;
            call[i]=-1;
            visited[i]=false;
        }

        for(int i = 0; i<n; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u]=v;
        }
        int mx = 0;
        int pos;
        int cnt;
        for(int i = 1; i<=n; i++)
        {
            if(call[i]==-1) cnt= dfs(i);
            if(cnt>mx)
            {
                pos = i;
                mx = cnt;
            }
        }
        printf("Case %d: %d\n",cas,pos);
    }
}
*/
