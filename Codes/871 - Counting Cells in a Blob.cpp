#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
#include<cstdlib>

using namespace std;
char graph[30][30];
int x_axis[]= {-1,-1,-1,0,0,1,1,1};
int y_axis[]= {0,1,-1,1,-1,0,1,-1};
int best=0;
int row,col;
void dfs(int i,int j)
{
    graph[i][j]='0';
    best++;
    int nx,ny;
    for(int k = 0; k<8; k++)
    {
        nx = i + x_axis[k];
        ny = j + y_axis[k];
        if(nx>=0 && nx< row && ny >= 0 && ny < col && graph[nx][ny]=='1' )
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    int m=-1,n;
    int t;
    int bulb;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        bulb = 0;
        while(gets(graph[++m]))
        {
            if(graph[m][0]=='\0') break;
        }
        //cout<<m<<endl;
        row = m;
        col = strlen(graph[0]);
        //cout<<col;
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                if(graph[i][j]=='1')
                {
                    dfs(i,j);
                    if(best>bulb) bulb = best;
                    best=0;
                }

            }

        }
        printf("%d\n",bulb);
        m=-1;
        if(t) printf("\n");

    }
    return 0;

}
