#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#include<iostream>
#include<iterator>
using namespace std;
int city[2001][2001];
int disten[2001][2001];


queue<pair<int,int> >Q;


int test1,test2;
int x_axis[]= {0,0,-1,1};
int y_axis[]= {-1,1,0,0};
bool is_valid(int x,int y)
{
    return   x>=0&&x<2000
             &&y>=0&&y<2000;

}



int bfs()
{
    while(!Q.empty())
    {
        pair<int,int> u;
        u = Q.front();


        Q.pop();
        for(int i= 0; i<4; i++)
        {
            int tx,ty;
            tx= u.first+x_axis[i];
            ty = u.second+y_axis[i];
            if(is_valid(tx,ty))
            {
                if(disten[tx][ty]==-1)
                {
                    disten[tx][ty]=disten[u.first][u.second]+1;

                    if(city[tx][ty]==2)
                    {

                        return disten[tx][ty];
                    }
                    pair<int,int> v = pair<int,int>(tx,ty);
                    Q.push(v);
                }
            }
        }


    }
    return -1;

}


int main()
{
   // freopen("input.txt","r",stdin);
    int i,j,k,l;
    int x,y;
    while(scanf("%d\n",&test1)&&test1)
    {
        memset(disten,-1,sizeof(disten));
        memset(city,0,sizeof city);
        Q = queue<pair<int,int> >();
        while(test1--)
        {
            scanf("%d %d",&x,&y);
            Q.push(pair<int,int>(x,y));
            city[x][y]=1;
            disten[x][y]=0;
        }
        scanf("%d",&test2);
        while(test2--)
        {
            scanf("%d %d",&x,&y);
            city[x][y]=2;
        }
        //cout<<x<<' '<<y<<endl;
        printf("%d\n",bfs());

    }
    return 0;

}
