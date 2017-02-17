#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<queue>
#include<sstream>
#include<string>
#include<vector>
#include<iterator>
#include<map>

using namespace std;
int bfsQ(int src,vector<int> graph[],int destinetion);
int main()
{
    vector<int>graph[50];
    int num;
    int node;
    int edge;
    int a,b;
    int count=1,cas = 1,numI,numJ;
    while(scanf("%d",&numI)!=EOF)
    {
        for(int j = 0; j<numI; j++)
        {
            scanf("%d",&numJ);
            graph[count].push_back(numJ);
            graph[numJ].push_back(count);
        }
        if(count == 19)
        {
            scanf("%d",&num);
            printf("Test Set #%d\n",cas++);
            for(int i =0; i<num; i++)
            {
                cin>>a>>b;
                printf("%2d to %2d: %d\n",a,b,bfsQ(a,graph,b));
            }
            printf("\n");
            count=0;
            for(int i = 0; i<=20; i++)
                graph[i].clear();
        }
        count++;
    }
    return 0;
}
int bfsQ(int src,vector<int> graph[],int destinetion)
{
    int taken[22]= {0};
    int desten[22]= {0};
    queue<int> Q;
    taken[src]=1;
    desten[src]=0;
    Q.push(src);
    while(!Q.empty())
    {
        int u = Q.front();
        for(int j=0; j<graph[u].size(); j++)
        {
            int v = graph[u][j];
            if(!taken[v])
            {
                Q.push(v);
                taken[v]=1;
                desten[v]=desten[u]+1;
            }

        }
        Q.pop();
    }
    return desten[destinetion];
    for(int i = 1; i<=20; i++)
    {
        printf("%d to %d dis is %d\n",src,i,desten[i]);
    }
    printf("\n");
}
