/*#include<iostream>
#include<cstdio>
#include<iterator>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<vector>
*/
#include<bits/stdc++.h>
using namespace std;
int ind[2005];
int lowlink[2005];
int visited[2005];
map<int,vector<int> > graph;
int ite;
stack<int> s;
int scc;
void torjan(int v)
{
    ind[v]=lowlink[v]=ite++;
    s.push(v);
    visited[v]=1;
    for(int i = 0;i<graph[v].size();i++){
        int w = graph[v][i];
        if(ind[w]==0){
            torjan(w);
            lowlink[v]=min(lowlink[v],lowlink[w]);

        }
        else if(visited[w]) lowlink[v]=min(lowlink[v],ind[w]);
    }
    if(ind[v]==lowlink[v]){
        while(!s.empty()){
            int w = s.top();
            s.pop();
            visited[w]=0;
            if(w==v) break;
        }
        scc++;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,m;
    int test;
    int v,w,p;
    while(scanf("%d %d",&n,&m) && (m+n)){
        for(int i = 0;i<m ;i++){
            scanf("%d %d %d",&v,&w,&p);
            if(p==1) graph[v].push_back(w);
            else
            {
                graph[v].push_back(w);
                graph[w].push_back(v);
            }
        }
        scc=0;
        for(int i = 1;i<=n;i++ ){
            if(ind[i]==0) torjan(i);
        }
        if(scc==1) cout<<"1\n";
        else cout<<"0\n";
        memset(ind,0,sizeof ind);
        memset(lowlink,0,sizeof lowlink);
        graph.clear();
        memset(visited,0,sizeof visited);

    }
    return 0;

}



/*#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iterator>
#include<stack>
#include<iostream>
using namespace std;
map<int,int> visited;
map<int, vector<int > > graph;

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
    int n,m;
    int v,w,p;
    while(scanf("%d %d",&n,&m)){
        for(int i = 0;i<m;i++){
            scanf("%d %d %d",&v,&w,&p);
            if(p==1) graph[v].push_back(w);
            else {
                graph[v].push_back(w);
                graph[w].push_back(v);
            }
        }
        stack<int> s;
        visited.clear();
        for(int i = 1;i<=n;i++){
            if(visited[i]==0){
                s.push(i);
               // cout<<i<<endl;
                visit(i);
            }
        }
        visited.clear();
        int ans=0;
        while(!s.empty()){
            int p = s.top();
            s.pop();
            if(visited[p]==0){
                  ans++;
                visit(p);
            }
        }
        if(ans==1) printf("1\n");
        else printf("0\n");
        graph.clear();

    }
    return 0;
}
*/
