#include<cstdio>
#include<cstring>
#include<iterator>
#include<map>
#include<set>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
   // freopen("input.txt","r",stdin);
    int node;
    while(scanf("%d",&node)&&node)
    {
        map<int,vector<int> > graph;
        int u,v;
        while(scanf("%d %d",&u,&v) && (u!=0 && v!=0))
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> colour(node+2,5);
        bool isbipi = true;
        for(int s = 1; s<=node; s++)
        {
            if(colour[s]!=5) continue;
            //cout<<s<<endl;
            colour[s] = 0;
            queue<int> Q;
            Q.push(s);
            while(Q.empty()==false)
            {
                int u = Q.front();
                Q.pop();
                for(int i = 0; i<(int)graph[u].size(); i++)
                {
                    int v = graph[u][i];
                    if(colour[v]==5)
                    {
                        colour[v]=1-colour[u];
                        Q.push(v);
                    }
                    else if(colour[v]==colour[u])
                    {
                        //cout<<u<<endl;
                        isbipi=false;
                    }
                }
            }
            if(isbipi==false) break;
        }
        if(isbipi) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
