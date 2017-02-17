#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<iterator>
#include<cstring>
#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;
typedef set<int> si;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,ii> piiii;
#define mem(a,b) memset(a,b,sizeof(a))
#define sz(a) (int)a.size()
#define pb push_back
#define REP(i,j,k) for(i = j;i<=(k);i++)
#define VII vi :: iterator
#define SII si :: iterator
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int test;
    scanf("%d",&test);
    while(test--)
    {
        map<int,si> graph;
        int node;
        int cnt;
        scanf("%d",&node);
        for(int u=1; u<=node; u++)
        {

            scanf("%d",&cnt);
            for(int j = 0; j<cnt; j++)
            {
                int v;
                scanf("%d",&v);

                graph[u].insert(v);
                graph[v].insert(u);
            }
        }
       vi colour(node+2 , 1e9);


        int ans = 0;
        for(int s = 1; s<=node; s++)
        {
           // cout<<colour[s]<<endl;
            if(colour[s]!=1e9) continue;
            //cout<<s<<endl;
            bool isbipartite = true;
            queue<int> Q;
            Q.push(s);
            int mx_col[2]= {0,0};
            mx_col[0]++;
            colour[s] = 0;
            while(Q.empty()==false)
            {
                int u = Q.front();
               // cout<<u<<endl;
                Q.pop();
                SII i;
                for(i = graph[u].begin(); i!=graph[u].end(); i++)
                {
                    int v = *i;
                    if(colour[v]==1e9)
                    {
                        colour[v] = 1 - colour[u];
                        //cout<<v<<endl;
                        Q.push(v);
                        mx_col[colour[v]]++;
                    }
                    if(colour[v]==colour[u])
                    {
                        isbipartite = false;
                    }
                }

            }
            if(isbipartite) ans += max(mx_col[0],mx_col[1]);

        }
        printf("%d\n",ans);
        graph.clear();


    }
    return 0;
}
