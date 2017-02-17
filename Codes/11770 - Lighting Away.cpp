#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
using namespace std;
map<int ,vector<int > > graph;
set<int> order;
map<int ,int > visited;

void visit(int p)
{
    if(visited[p]) return ;
    visited[p]=1;
    for(int i = 0; i<graph[p].size(); i ++)
    {
        visit(graph[p][i]);
    }

}
int main()

{
    int test;
    int a,b;
    stack<int > s;
    int n,m;
    int i = 0;
    scanf("%d",&test);
    int cas=1;
    while(test--)
    {
        cin>>n>>m;
        for(i= 0; i<m; i++)
        {
            cin>>a>>b;
            graph[a].push_back(b);
            order.insert(a);
            order.insert(b);

        }
        int swch=0;
        // cout<<order.size();
        for(int i =1; i<=n; i++)
        {
            // cout<<*it<<endl;
            if(!visited[i])
            {
                s.push(i);
                visit(i);
            }
        }
        visited.clear();
        while(!s.empty())
        {
            int p  = s.top();
            //cout<<p<<endl;
            s.pop();
            if(!visited[p])
            {
                swch++;
                visit(p);
            }
        }
        printf("Case %d: %d\n",cas++,swch);
        graph.clear();
        visited.clear();
        order.clear();
    }
    return 0;


}

/*#include<cstring>
#include<iostream>
#include<map>
#include<stack>
#include<iterator>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
map<int,vector<int> > graph;
int ind[1000];
int lowlink[1000];
int visited[10000];
stack<int> s;
int ite=1;
int res;
void torjan(int v)
{
    ind[v]=lowlink[v]=ite++;
    s.push(v);
    visited[v]=1;
    for(int i = 0; i<graph[v].size(); i++)
    {
        int w = graph[v][i];
        if(ind[w]==0)
        {
            torjan(w);
            lowlink[v]=min(lowlink[v],lowlink[w]);

        }
        else if(visited[w])
        {
            lowlink[v]=min(lowlink[v],ind[w]);
        }
    }

    if(ind[v]==lowlink[v])
    {
        int w;
        while(s.empty()==0)
        {
            w=s.top();
            s.pop();
            visited[w]=0;
            if(v==w) break;
        }
        res++;
    }
}
int main()
{
    int n,m;
    int test;
    int a,b;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }
        for(int i =1; i<=n; i++)
        {
            if(ind[i]==0) torjan(i);
        }
        cout<<res<<endl;
    }

}

*/
