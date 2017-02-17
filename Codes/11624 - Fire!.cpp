#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<iterator>
#include<string>
#include<cstring>
#include<vector>

using namespace std;
int out;
int x_axis[] = {0,0,-1,1};
int y_axis[] = {1,-1,0,0};
char graph[1005][1050];
int fire[1001][1001];
int dis[1001][1001];


int r,c;

void agun();
int jx;
int jy;

bool judge(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c)
    {
        return true;
    }
    return false;
}

bool is_ok(int x,int y)
{
    if(x==0||x==r-1||y==0||y==c-1)
    {
        return true;
    }
    return false;
}

void agun()
{
    int i,j;
    queue<int> q;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(graph[i][j]=='F')
            {
                q.push(i);
                q.push(j);
                fire[i][j]=0;
            }
        }
    }

    int x,y;
    int nx,ny;
    while(!q.empty())
    {

        x=q.front();
        q.pop();
        y=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            nx=x+x_axis[i];
            ny=y+y_axis[i];
            if(!judge(nx,ny))
            {
                continue;
            }
            if(graph[nx][ny]=='#')
            {
                continue;
            }

            if(fire[x][y]+1<fire[nx][ny])
            {

                fire[nx][ny]=fire[x][y]+1;
                q.push(nx);
                q.push(ny);
            }
        }
    }
}
void joo()
{
    queue<int> Q;
    memset(dis,-1,sizeof dis);
     dis[jx][jy]=0;
    int nx,ny;
    Q.push(jx);
    Q.push(jy);

    int tx,ty;



    while(!Q.empty())
    {
        nx = Q.front();
        Q.pop();
        ny = Q.front();
        Q.pop();
        if(nx==r-1 || ny == c-1 || nx == 0 || ny == 0)
        {
            printf("%d\n",dis[nx][ny]+1);
            return;
        }

        for(int i = 0; i<4; i++)
        {
            tx = nx + x_axis[i];
            ty = ny + y_axis[i];

            if(dis[tx][ty]!=-1)
            {
                continue;
            }
            if(graph[tx][ty]=='#'||graph[tx][ty]=='F')
            {
                continue;
            }

            if(dis[nx][ny]+1 >= fire[tx][ty])
            {

                continue;
            }
            dis[tx][ty]=dis[nx][ny]+1;

            Q.push(tx);
            Q.push(ty);
        }
    }
    puts("IMPOSSIBLE");
}

int main()
{

    int i = 0,j,k,l=0;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        l=0;

        scanf("%d %d",&r,&c);
        for(i = 0; i<r; i++) scanf(" %s",graph[i]);


        for(i= 0; i<r; i++)
        {
            for(j = 0; j<c; j++)
            {
                fire[i][j]=1e7;
                if(graph[i][j]=='J')
                {
                    l=1;
                    jx=i;
                    jy=j;
                }
            }
        }
        if(l==0)
        {
            printf("1\n");
            continue;
        }
        agun();
        joo();
    }
    return 0;

}

