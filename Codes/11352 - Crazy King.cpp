//11352 - Crazy King
#include<cstring>
#include<cstdio>
#include<iostream>
#include<iterator>
#include<vector>
#include<queue>
#include<iterator>
using namespace std;
char graph[110][110];
int row,col;
int taken[110][110];
int disten[110][110];
int x[]= {1,2,-2,-2, 2,-1,-1, 1};
int y[]= {2,1, 1,-1,-1, 2,-2,-2};
int x_axis[8]= {-1,-1,-1,0, 0,1,1, 1};
int y_axis[8]= { 0, 1,-1,1,-1,0,1,-1};
void colour(int i,int j)
{
    for(int k = 0; k<8; k++)
    {
        int nx = i+x[k];
        int ny = j + y[k];
        if(nx>=0&&nx<row&&ny>=0&&ny<col&&graph[nx][ny]!='A'&&graph[nx][ny]!='B'&&graph[nx][ny]!='Z' )
        {
            graph[nx][ny]='1';
        }
    }
}
int bfs(int dx,int dy,int sx,int sy)
{
    queue<int> Q;
    memset(taken,0,sizeof taken);
    taken[dx][dy]=1;
    disten[dx][dy]=0;
    Q.push(dx);
    Q.push(dy);
    int nx,ny,tx,ty;
    while(!Q.empty())
    {
        nx=Q.front();
        Q.pop();
        ny=Q.front();
        Q.pop();
        for(int i = 0; i<8; i++)
        {
            tx=nx+x_axis[i];
            ty=ny+y_axis[i];
            if(tx>=0&&tx<row&&ty>=0&&ty<col&&graph[tx][ty]!='Z'&&graph[tx][ty]!='1')
            {
                if(!taken[tx][ty])
                {
                    taken[tx][ty]=1;
                    disten[tx][ty]=disten[nx][ny]+1;
                    if(tx==sx && ty==sy) return disten[sx][sy];
                    Q.push(tx);
                    Q.push(ty);
                }
            }
        }
    }
    return -1;


}

int main()
{
    //freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    int i,j,k,l;
    int dx,dy;
    int sx,sy;
    while(test--)
    {
        scanf("%d %d ",&row,&col);
        int s=0;
        int f=0;
        // getchar();
        for(i= 0; i<row; i++)
        {
            gets(graph[i]);
            if(!s)
                for(j=0; graph[i][j]; j++)
                {
                    if(graph[i][j]=='A')
                    {
                        dx = i;
                        dy = j;
                        s=1;
                    }
                }
            if(!f)
            {
                for(j=0; graph[i][j]; j++)
                {
                    if(graph[i][j]=='B')
                    {
                        sx=i,sy=j;
                        f=1;
                    }
                }
            }

        }
        for(i = 0; i<row; i++)
        {
            for(j = 0; j<col; j++)
            {
                if(graph[i][j]=='Z')
                {
                    colour(i,j);
                }
            }
        }
       // for(i=0;i<row;i++) puts(graph[i]);
        int res = bfs(dx,dy,sx,sy);
        if(res<0) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",res);


    }
    return 0;
}

