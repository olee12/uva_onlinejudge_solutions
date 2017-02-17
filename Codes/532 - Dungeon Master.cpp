#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<map>
#include<queue>
using namespace std;
char graph[40][40][40];
class Node
{
public:
    int x;
    int y;
    int z;
};
int l,r,c;
int x_axis[] = {-1,1,0,0,0,0};
int y_axis[] = {0,0,0,0,-1,1};
int z_axis[] = {0,0,1,-1,0,0};
int bfs(int dx,int dy,int dz)
{
    Node N;
    N.x = dx;
    N.y = dy;
    N.z = dz;
    queue< Node > Q;
    int nx,ny,nz;
    int tx,ty,tz;
    Q.push(N);
    int disten[40][40][40];



    disten[dx][dy][dz]=0;
    while(!Q.empty())
    {
        N = Q.front();
        Q.pop();
        nx = N.x;
        ny=N.y;
        nz=N.z;
        for(int i = 0; i<6; i++)
        {
            tx = nx+x_axis[i];
            ty = ny+y_axis[i];
            tz = nz+z_axis[i];
            //printf("tx %d ty %d tz %d\n",tx,ty,tz);

            // cout<<"in"<<endl;
            if(tx>=0 && tx<l && ty>=0 &&ty<r && tz>=0 && tz<c && graph[tx][ty][tz]!='#')
            {
                // if(!taken[tx][ty][tz])
                //{

                //cout<<"in\n"<<endl;

                disten[tx][ty][tz]=disten[nx][ny][nz]+1;
                // cout<<graph[tx][ty][tz]<<endl;
                if(graph[tx][ty][tz]=='E')
                {

                    return disten[tx][ty][tz];
                }
                graph[tx][ty][tz]='#';
                N.x=tx;
                N.y=ty;
                N.z=tz;
                Q.push(N);

                // }
            }
        }
    }
    return -1;
}


int main()
{
    int dx,dy,dz;
    int i,j,k;
    char newline[10];
    int test;
    int s=0;
    while(scanf("%d %d %d",&l,&r,&c))
    {
        s=0;
        getchar();
        if(l==0&&r==0&&c==0) break;
        for(i= 0; i<l; i++)
        {
            for(j=0; j<r; j++)
            {
                gets(graph[i][j]);
                if(!s)
                {
                    for(k=0; graph[i][j][k]; k++)
                        if(graph[i][j][k]=='S')
                        {
                            s=1;
                            dx = i;
                            dy=j;
                            dz=k;

                        }
                }
            }
            gets(newline);
        }
        int res = bfs(dx,dy,dz);
        // cout<<res<<endl;
        if(res<0) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n",res);

    }
    return 0;

}
