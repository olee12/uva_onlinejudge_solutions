#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
#define M 10
int x_axis[]= {-1,0,0};
int y_axis[]= {0,1,-1};
char graph[M][M];
int row,col;
bool spe;
inline bool valid(int i,int j)
{
    bool f = graph[i][j]=='I'||graph[i][j]=='E'||graph[i][j]=='H'||graph[i][j]=='O'||graph[i][j]=='V'||graph[i][j]=='A' ||graph[i][j]=='#' ;
    return (i>=0&&i<row&&j>=0&&j<col && f);
}
///  forth
void bt(int i,int j)
{
    graph[i][j]='.';
    if(graph[i][j]=='#') return ;
    for(int k = 0; k<3; k++)
    {
        int tx = i + x_axis[k];
        int ty = j + y_axis[k];
        if(valid(tx,ty))
        {
            if(spe) printf(" ");spe=true;
            if(k==0) printf("forth");
            else if(k==1) printf("right");
            else printf("left");
            bt(tx,ty);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&row,&col);
        for(int i = 0; i<row; i++)
            scanf(" %s",graph[i]);
            for(int j = 0;j<col;j++)
                if(graph[row-1][j]=='@')
            {
                spe=false;
                bt(row-1,j);

            }

        puts("");
    }
    return 0;
}
