#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
map<int,vector<int> >graph;
void visit(int p,vector<int> &visited)
{
    for(int i = 0; i<graph[p].size(); i++)
    {
        if(visited[graph[p][i]]==0)
        {
            visited[graph[p][i]]=1;

            visit(graph[p][i],visited);
        }
    }
}
bool comp(int a)
{
    return a==0;
}
int main()
{
    int node,u,v;

    while(scanf("%d",&node)==1 && node)
    {
        while(scanf("%d",&u) && u)
        {
            while(scanf("%d",&v) && v)
            {
                graph[u].push_back(v);

            }
        }
        int test;
        int start;
        scanf("%d",&test);
        while(test--)
        {
            vector<int> visited(node+1,0);
            scanf("%d",&start);
            visit(start,visited);
            int coun = count_if(visited.begin(),visited.end(),comp)-1;;
            printf("%d",coun);
            int x=0;
            for(int i = 1; x<coun && i<=node; i++)
            {
                if(visited[i]==0)
                {
                    x++;
                    printf(" %d",i);
                }
            }
            printf("\n");
        }
        graph.clear();
    }
    return 0;
}
