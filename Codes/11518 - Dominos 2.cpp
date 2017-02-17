#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
map<int ,vector<int> > graph;
map<int,int> visited;
int fall;
void visit(int p)
{
    if(visited[p]) return ;
    visited[p]=1;
    fall++;
    for(int i = 0; i<graph[p].size(); i++) visit(graph[p][i]);
}

int main()
{
    int test;
    int n,m,l;
    int z[10050];
    int a,b;
    while(scanf("%d",&test)==1)
    {
        while(test--)
        {
            fall = 0;
            scanf("%d %d %d",&n,&m,&l);
            for(int i = 0; i<m; i++)
            {
                scanf("%d %d",&a,&b);
                graph[a].push_back(b);
            }
            for(int i  = 0; i<l; i++)
            {
                scanf("%d",&z[i]);
            }
            for(int i =0; i<l; i++)
            {
                visit(z[i]);
            }
            printf("%d\n",fall);
            graph.clear();
            visited.clear();

        }
    }
    return 0;
}
