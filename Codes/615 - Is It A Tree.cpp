#include<cstring>
#include<map>
#include<cstdio>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<queue>
using namespace std;
#define MII map<int,int> :: iterator
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int a,b;
    int cas=1;
    while(1)
    {
        int zz = 0;
        bool flag = false;
        int cnt=0;
        map<int,vector<int> >graph;
        map<int,int> ind;

        while(scanf("%d %d",&a,&b))
        {
            if(a==0 && b==0) break;
            if(a<0 && b<0) return 0;
            zz++;
            if(a==b) cnt++;
            graph[a].push_back(b);
            ind[a];
            ind[b]++;
        }
        MII i;
        int root=-1;
        for(i = ind.begin();i!=ind.end(); i++)
        {
            //cout<<i->second<<' ';
            if(i->second==0) {
                    root = i->first;
                    cnt++;
            }
            if(i->second>1) {
                root=-1;break;
            }
        }
       // cout<<root<<endl;
        if((root==-1 || cnt>1) && zz!=0 )
        {
            printf("Case %d is not a tree.\n",cas++);
            continue;
        }
        queue<int> Q;
        int edge=0;
        map<int,int> visited;
        visited.clear();
        Q.push(root);
        visited[root]= true;
        while(Q.empty()==false)
        {
            int u = Q.front();
            Q.pop();
            for(int i = 0; i<(int)graph[u].size(); i++)
            {
                int v = graph[u][i];
               // cout<<v<<' ';
                if(visited[v]==true)
                {
                    flag = true;
                    break;
                }
                visited[v]=true;
                edge++;
                Q.push(v);
            }
            if(flag) break;
        }
        if(flag==true || edge!=zz) printf("Case %d is not a tree.\n",cas++);
        else printf("Case %d is a tree.\n",cas++);
    }
    return 0;

}


