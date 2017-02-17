/*#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<iterator>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
int bfsQ(int src,map<int ,vector<int> > graph,int x);
int main()
{
    map<int,vector<int> > graph;
    int node,a,b;
    int TTI;
    int ca=1;
    while(cin>>node && node){
        for(int i = 0; i < node; i++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

    puts("");*/
    /*map<int ,vector<int> > :: iterator it;
    for(it=graph.begin();it!=graph.end();it++){
        cout<<(*it).first<<" - > ";
        for(int j= 0;j<(*it).second.size();j++){
            cout<<(*it).second[j]<<" ";
        }
        cout<<endl;
    }*/
    /*while(cin>>a>>TTI && (TTI!=0 || a!=0)){
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",ca++,bfsQ(a,graph,TTI),a,TTI);
    }

    graph.clear();
    }
    return 0;
}

int bfsQ(int src,map<int ,vector<int> > graph,int x)
{
    int count = 0;
    int taken[100]={0};
   map<int, int> disten;
    taken[src]=1;
    disten[src]=0;
    queue<int > Q;
    Q.push(src);
    int u = Q.front();
    while(!Q.empty())
    {
        int u = Q.front();
        map<int,vector<int> >:: iterator it;
        for(int i = 0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(!taken[v]){
                taken[v]=1;
                disten[v]=disten[u]+1;
                Q.push(v);
            }

        }
         Q.pop();

    }
    map<int,vector<int> >:: iterator it;
    for(it=graph.begin();it!=graph.end();it++){
            int u=(*it).first;
       // printf("%d to %d distance %d\n",src,(*it).first,disten[u]);
        if(disten[u]>x) count++;

    }
    return count;
}
//,distance[(*it).first]
*/
//accepted;
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<iterator>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
int bfsQ(int src,map<int ,vector<int> > graph,int x);
map<int,int>taken;
int main()
{

    int node,a,b;
    int TTI;
    int ca=1;
    while(cin>>node && node){
            map<int,vector<int> > graph;
        for(int i = 0; i < node; i++){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
       // cout<<"graph size : "<<graph.size()<<" ";


    while(cin>>a>>TTI && (TTI != 0 || a != 0)){
            taken.clear();
            int result = bfsQ(a,graph,TTI);
          //  cout<<"taken size : "<<taken.size()<<" ";
            result += graph.size()-taken.size();
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",ca++,result,a,TTI);
    }


    }
    return 0;
}

int bfsQ(int src,map<int ,vector<int> > graph,int x)
{
    int count = 0;

   map<int, int> disten;
    taken[src]=1;
    disten[src]=0;
    queue<int > Q;
    Q.push(src);
    int u = Q.front();
    while(!Q.empty())
    {
        int u = Q.front();
        int sz=graph[u].size();
        for(int i = 0;i<sz;i++){
            int v = graph[u][i];
            if(!taken[v]){
                taken[v]=1;
                disten[v]=disten[u]+1;
                Q.push(v);
            }

        }
         Q.pop();

    }
    map<int,vector<int> >:: iterator it;

    for(it=graph.begin();it!=graph.end();it++){
            int u=(*it).first;

        if(disten[u]>x) count++;

    }
    return count;
}
