#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;
#define ROO 35
#define COO 85
char graph[ROO][COO];
int row,col;
int x[]={-1,0,0,1};
int y[]={0,1,-1,0};
void dfs(int i,int j)
{
    //cout<<" dfa"<<graph[i][j]<<"fasdf\n";
    if(graph[i][j]!=' ') return;
    graph[i][j]='#';
    //cout<<i<<j<<endl;
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
   /* int nx,ny;
    graph[i][j]='#';
    for(int k = 0;k<4;k++){
        nx = i+x[k];
        ny = j + y[k];
        if(graph[nx][ny]==' ') dfs(nx,ny);
    }*/

}

int main()
{
    int m,n,i,j,k,l;
    int t;

    scanf("%d\n",&t);
    row=-1;

    while(t--)
    {
        while(gets(graph[++row]))
        {
            if(graph[row][0]=='_')
            {
                break;
            }

        }
       // cout<<row<<endl;
        for(i=0; i<row; i++)
        {
            col = strlen(graph[i]);
            for(j=0; j<col; j++)
            {

                if(graph[i][j]=='*')
                {
                    //cout<<"in\n";
                    graph[i][j]=' ';
                    dfs(i,j);
                    break;
                }
            }
        }
        for(i=0; i<=row; i++)
            printf("%s\n",graph[i]);
        row=-1;
    }
    return 0;
}
