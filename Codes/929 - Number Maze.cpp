#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<math.h>
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define M 1005
#define INF 2147483640
int graph[M][M],d[M][M],row,col;
bool visited[M][M];
int x_axis[]= {0,0,1,-1};
int y_axis[]= {1,-1,0,0};
struct node
{
    int cost,x,y;
    bool operator < (const node& p) const
    {
        return cost > p.cost;
    }
};
inline bool bound(int i, int j)
{
    return (i>=1&&i<=row&&j>=1&&j<=col) ;
}
int djkastra(int m,int n)
{
  //  memset(d,1e6,sizeof d);
    d[1][1]=graph[1][1];
    int x,y,i,j,k,tx,ty,t_cost;
    node tmp ;
    tmp.cost=0;
    tmp.x=tmp.y=1;
    priority_queue<node> Q;
    Q.push(tmp);
    while(Q.empty()==false)
    {
        tmp = Q.top();
        Q.pop();
        x = tmp.x;
        y = tmp.y;
        visited[x][y]=true;
        for(k = 0; k<4; k++)
        {

            tx = x+x_axis[k];
            ty = y+y_axis[k];
            // cout<<tx<<' '<<ty<<endl;
            if(bound(tx,ty) && !visited[tx][ty])
            {
                t_cost = d[x][y]+graph[tx][ty];
                if(t_cost < d[tx][ty])
                {
                    d[tx][ty]=t_cost;
                   // cout<<t_cost<<endl;
                    tmp.x=tx;
                    tmp.y=ty;
                    tmp.cost = d[tx][ty];
                    Q.push(tmp);
                }
            }
        }
    }
    return d[m][n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    // cout<<INF<<endl;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&row,&col);
        for(int i = 1; i<=row; i++)
            for(int j = 1; j<=col; j++)
            {
                scanf("%d",&graph[i][j]);
                d[i][j]=INF;
                visited[i][j]=false;
            }
        int c = djkastra(row,col);
        printf("%d\n",c);
    }
    return 0;
}

