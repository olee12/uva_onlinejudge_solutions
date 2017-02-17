
#include<bits/stdc++.h>
using namespace std;
int row,col;
bool graph[205][205];
inline bool is_ok(int i,int j)
{
    return (i>=1 && i<=row && j>=1 && j<=col);
}
int x_axis[]= {-1,0,1,0};
int y_axis[]= {0, 1,0,-1};

int disten[205][205];
int bfs()
{
    if(row==1 && col==1) return 0;

    memset(disten,-1,sizeof disten);
    queue<int> Q;
    int tx,ty,nx,ny;

    disten[1][1]=0;
    Q.push(1);
    Q.push(1);
    while(!Q.empty())
    {
        nx = Q.front();
        Q.pop();
        ny = Q.front();
        Q.pop();
        for(int i = 0; i<4; i++)
        {
            tx = nx + x_axis[i];
            ty = ny + y_axis[i];
            if(is_ok(tx,ty) && !graph[tx][ty])
            {
                //cout<<tx<<' '<<ty<<disten[tx][ty]<<endl;
                if(disten[tx][ty]==-1)
                {


                    Q.push(tx);
                    Q.push(ty);
                    disten[tx][ty]=disten[nx][ny]+1;
                    if(tx==row&& ty==col) return disten[tx][ty];
                }
            }
        }
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int m,n,k;
    int x,y,l;
    while(scanf("%d %d",&row,&col),(row|col))
    {
        scanf("%d",&m);
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            graph[x][y]=1;

        }
        scanf("%d",&n);
        int r,c,l;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d", &r, &c, &l);
            for (int i = r - l; i <= r + l; i++)
            {
                for (int j = c - l; j <= c + l; j++)
                {
                    if (((i - r) * (i - r) + (j - c) * (j - c) <= l * l) && i > 0 && i <= row && j > 0 && j <= col)
                    {
                        graph[i][j] = true;
                    }
                }
            }
        }
        /*for(int i = 1; i<=row; i++)
        {
            for(int j = 1; j<=col; j++) printf("%d",graph[i][j]);
            printf("\n");

        }*/
        int res= bfs();
        if(res!=-1)
        {
            printf("%d\n",res);
        }
        else printf("Impossible.\n");

        memset(graph,0,sizeof graph);
    }
    return 0;

}
