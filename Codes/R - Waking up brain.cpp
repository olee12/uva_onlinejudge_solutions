#include<iostream>
#include<iterator>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
#define M 50
int visited,rnk[M];
vector<int> graph[M];
queue<pair<int,int> > Q;

int main()
{
    int n,m;
    char a,b,c;
    int dist;
    while(scanf("%d",&n)==1)
    {
        dist = visited = 0;
        memset(rnk,0,sizeof rnk);
        for(int i= 0; i<30; i++) graph[i].clear();
        scanf("%d",&m);
        scanf(" %c %c %c",&a,&b,&c);
        Q.push(make_pair(a-'A',0));
        rnk[a-'A']=3;
        Q.push(make_pair(b-'A',0));
        rnk[b-'A']=3;
        Q.push(make_pair(c-'A',0));
        rnk[c-'A']=3;
        for(int i = 0; i<m; i++)
        {
            scanf(" %c %c",&a,&b);
            graph[a-'A'].push_back(b-'A');
            graph[b-'A'].push_back(a-'A');
        }
        while(Q.empty()==false)
        {
            int u = Q.front().first;
            int d = Q.front().second;
            Q.pop();
            visited++;
            for(int i = 0; i<(int)graph[u].size(); i++)
            {
                int v = graph[u][i];
                ++rnk[v];
                if(rnk[v]==3)
                {
                    Q.push(make_pair(v,d+1));
                    dist = d+1;
                }
            }
            if(visited==n) break;
        }
        if(visited==n) printf("WAKE UP IN, %d, YEARS\n",dist);
        else puts("THIS BRAIN NEVER WAKES UP");
        while(Q.empty()==false) Q.pop();

    }
    return 0;
}
