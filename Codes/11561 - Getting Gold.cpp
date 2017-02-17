#include<cstdio>
#include<cstring>
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define M 55
int row,col;
char graph[M][M];
int x_axis[]= {1,-1,0,0};
int y_axis[]= {0,0,1,-1};
int gold;
inline bool valid(int i,int j)
{
    return (graph[i][j]=='.' || graph[i][j]=='G');
}
void dfs(int i,int j)
{
    int tx,ty;
    if(graph[i][j]=='G') gold++;
    graph[i][j]='A';
    for(int k = 0; k<4; k++)
    {
        tx = i+x_axis[k];
        ty = j+y_axis[k];
        if(graph[tx][ty]=='T') return;
    }
    for(int k = 0; k<4; k++)
    {
        tx = i+x_axis[k];
        ty = j+y_axis[k];
        if(valid(tx,ty)) dfs(tx,ty);
    }


}
int main()
{
    // freopen("input.txt","r",stdin);
    while(scanf("%d %d",&col,&row)==2)
    {
        for(int i = 0; i<row; i++)
            scanf(" %s",graph[i]);
        for(int i = 0; i<row; i++)
            for(int j = 0; j<col; j++)
            {
                if(graph[i][j]=='P')
                {
                    gold = 0;
                    dfs(i,j);
                    goto out;
                }
            }
out:
        printf("%d\n",gold);
    }
    return 0;
}
