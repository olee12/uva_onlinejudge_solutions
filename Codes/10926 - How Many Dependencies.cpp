#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define M 150
vector<int> graph[M];
int sum[M];
bool visited[M];
void init(int& n)
{
    for(int i = 0; i<M; i++)
    {
        graph[i].clear();
        visited[i]=false;
    }
}
int dfs(int u)
{
    visited[u]=true;
    int sz = graph[u].size();
    for(int i= 0; i<sz; i++)
    {
        int v = graph[u][i];
        if(visited[v]==false) dfs(v);
    }

}
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    while(scanf("%d",&n),n)
    {
        init(n);
        for(int i = 1; i<=n; i++)
        {
            int t;
            scanf("%d",&t);
            for(int j = 0; j<t; j++)
            {
                int u;
                scanf("%d",&u);
                graph[i].push_back(u);
               // cout<<i<<' '<<u<<endl;
            }
        }
        int mx = -50000;
        int pos ;
        for(int i= 1; i<=n; i++)
        {

            dfs(i);
            int cnt = 0;
            for(int j = 1; j<=n; j++)
            {
                if(visited[j])
                {
                    cnt++;
                    visited[j]=false;
                }
            }

            if(cnt>mx)
            {
                mx = cnt;
                pos = i;
            }
        }

        printf("%d\n",pos);
    }
    return 0;
}
