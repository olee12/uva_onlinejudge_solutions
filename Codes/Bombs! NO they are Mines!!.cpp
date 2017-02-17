#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<vector>
#include<iterator>
#include<string>
#include<cstdlib>
using namespace std;
#define SIZE 100
int x[]= {0,0,-1,1};
int y[]= {1,-1,0,0};
int ara[SIZE][SIZE]= {0};
int main()
{

    int R,C;
    int num;
    int row,how,col;
    int nx;
    int ny;
    int tx;
    int ty;
    int fr1,fr2,to1,to2;
    while(cin>>R>>C &&(R|C))
    {
        for(int i =0;i<R;i++)
            for(int j = 0;j<C;j++)
            ara[i][j]=0;

        cin>>num;
        for(int i = 0; i<num; i++)
        {
            cin>>row;
            cin>>how;
            for(int j = 1; j<=how; j++)
            {
                cin>>col;
                ara[row][col]=1;
            }
        }
        cin>>fr1>>fr2>>to1>>to2;
        int disten[SIZE][SIZE]={0};

        queue<int>Q;
        disten[fr1][fr2]=0;
        ara[fr1][fr2]=1;
        Q.push(fr1);
        Q.push(fr2);
        ara[fr1][fr2]=1;
        while(!Q.empty())
        {
            nx=Q.front();
            Q.pop();
            ny = Q.front();
            Q.pop();
            for(int i =0; i<4; i++)
            {
                tx =  nx+x[i];
                ty =  ny+y[i];
                if(tx<R && tx>=0 && ty<C && ty>= 0)
                {
                    if(!ara[tx][ty])
                    {
                        Q.push(tx);
                        Q.push(ty);
                        ara[tx][ty]=1;
                        disten[tx][ty]=disten[nx][ny]+1;
                        if(tx==to1 && ty == to2) break;
                    }
                }
            }
            if(tx==to1 && ty == to2) break;
        }
        while(!Q.empty()) Q.pop();
        cout<<disten[to1][to2]<<endl;
    }
    return 0;
}
