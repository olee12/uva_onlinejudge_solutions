#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#include<iterator>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int x[]= {1,2,-2,-2,2,-1,-1,1};
int y[]= {2,1,1,-1,-1,2,-2,-2};
int main()
{
    int row,to1;
    char col,to2;
    int fr1,go1;
    char fr2,go2;
    while(scanf(" %c%d %c%d",&col,&row,&to2,&to1)!=EOF)
    {
        fr2=col;
        fr1=row;
        go1=to1;
        go2=to2;
        int ara[8][8]= {0};
        to1-=1;
        to2-='a';
        queue<int>Q;
        col-='a';
        row-=1;
        ara[row][col]=1;
        int disten[8][8]= {0};
        disten[row][col]=0;
        int nx,ny;
        int tx,ty;
        Q.push(row);
        Q.push(col);
        while(!Q.empty())
        {
            nx = Q.front();
            Q.pop();
            ny = Q.front();
            Q.pop();
            for(int i =0; i<8; i++)
            {
                tx=nx+x[i];
                ty=ny+y[i];
                if(tx>=0&&tx<8 && ty>=0 && ty<8)
                {
                    if(!ara[tx][ty])
                    {
                        disten[tx][ty]=disten[nx][ny]+1;
                        Q.push(tx);
                        Q.push(ty);
                        ara[tx][ty]=1;
                        if(tx==to1 && ty == to2) break;

                    }
                }

            }
            if(tx==to1 && ty == to2) break;
        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n",fr2,fr1,go2,go1,disten[to1][to2]);
    }
    return 0;
}
