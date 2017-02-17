#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<iterator>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include <memory.h>
using namespace std;
#define min(i,j) (i) > (j) ? (j) : (i)
map<string ,int > stoi;
map<int,string> itos;
map<int,vector<int> > graph;
int ind[30];
int low[30];
int ite = 1;
int visited[30];
stack<int> s;

void torjan(int v)
{
    ind[v]=low[v]=ite++;
    s.push(v);
    visited[v]=1;
    for(int i = 0;i<graph[v].size();i++){
        int w = graph[v][i];
        if(ind[w]==0){
            torjan(w);
            low[v]=min(low[v],low[w]);
        }
        else if(visited[w]) low[v]=min(low[v],ind[w]);
    }
    if(low[v]==ind[v]){
        vector<int> out;
        int w ;
        while(!s.empty()){
            w = s.top();
            visited[w]=0;
            s.pop();
            out.push_back(w);
            if(w==v) break;
        }
        for(int k = 0;k<out.size();k++){
            if(k) printf(", ");
            printf("%s",itos[out[k]].c_str());
        }
        printf("\n");
    }

}
int main()
{
    int f=0;
    int cas=1;
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
   // #endif // ONLINE_JUDGE

    int n,m;
    char str1[50],str2[50];
    while(scanf("%d %d",&n,&m)){
            if(n==0 && m == 0) break;
        int val = 0;
        while(m--){
            scanf("%s %s",str1,str2);
            string a(str1);string b(str2);
            if(stoi.find(a)==stoi.end()){
                stoi[a]=val;
                itos[val]=a;
                val++;
            }
            if(stoi.find(b)==stoi.end()){
                stoi[b]=val;
                itos[val]=b;
                val++;
            }
            graph[stoi[a]].push_back(stoi[b]);
        }
        if(f) puts("");
        f = 1;
        printf("Calling circles for data set %d:\n",cas++);

        for(int i = 0;i<n;i++){
            if(ind[i]==0 ) torjan(i);
        }
        memset(ind,0,sizeof ind);
        memset(low,0,sizeof low);
        memset(visited,0,sizeof visited);
        itos.clear();
        stoi.clear();
        ite=1;
        while(!s.empty()) s.pop();
        graph.clear();

    }
    return 0;

}
