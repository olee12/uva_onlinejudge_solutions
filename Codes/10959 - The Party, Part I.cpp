#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<iterator>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int P,D;
void bfsQ(int start,vector<int> graph[])
{
    queue<int> Q;
    Q.push(start);
    int top;
    int n;
    int visited[1010]= {0};
    int disten[1010];
    disten[start]=0;
    visited[start]=0;
    while(!Q.empty())
    {
        top=Q.front();
        int sz=graph[top].size();
        for(int i = 0; i<sz; i++)
        {
            n = graph[top][i];
            if(!visited[n])
            {
                visited[n]=1;
                disten[n]=disten[top]+1;
                Q.push(n);

                for(int k = 0; k<graph[n].size(); k++)
                {
                    if(visited[graph[n][k]])
                    {
                        if(disten[n]>disten[graph[n][k]])
                        {
                            disten[n]=disten[graph[n][k]]+1;
                        }
                    }
                }
            }
        }
        Q.pop();
    }
    for(int i = 1; i<P; i++)
    {
        printf("%d\n",disten[i]);
    }
}

int main()
{

    int t;
    int x,y;
    scanf("%d",&t);
    {
        while(t--)
        {
            scanf("%d %d",&P,&D);
            map<int,int> duplicate;
            vector<int> graph[P+2];
            for(int i = 0; i<D; i++)
            {
                scanf("%d %d",&x,&y);

                graph[x].push_back(y);
                graph[y].push_back(x);
            }
            bfsQ(0,graph);
            if(t) printf("\n");
        }
    }
    return 0;
}
