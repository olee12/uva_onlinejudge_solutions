#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
int row,col;
char graph[35][100];
bool flag[35][100];
char ch;
int x_axis[]= {1,-1,0,0};
int y_axis[]= {0,0,-1,1};
inline bool contour(char ch)
{
    return (ch==' ' || ch == '#' || ch == '*' || ch=='_');
}
inline bool paint(int i,int j)
{
    if(graph[i][j]==ch) return true;
    return false;
}
inline bool valid(int i,int j)
{
    if(graph[i][j]==0&&i>=0 &&j>=0&& j<col && i<row && flag[i][j]!=true) return false;
    if(graph[i][j]!='#' &&graph[i][j]!= ch && i>=0 &&j>=0&& j<col && i<row && flag[i][j]!=true) return false;
    return true;
}
void dfs(int i,int j)
{

    //cout<<i<<' '<<j<<endl;
    flag[i][j]=true;
    int tx,ty;
    for(int k = 0; k<4; k++)
    {
        tx = i + x_axis[k];
        ty = j + y_axis[k];
        if(paint(tx,ty)) graph[i][j]='#';
        if(valid(tx,ty)==false)
        {
            // cout<<i<<' '<<j<<endl;
            dfs(tx,ty);

        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int test;
    int m = -1;
    scanf("%d",&test);
    getchar();
    //getchar();
    int sz;
    int sx,sy;
    while(test--)
    {
        col = 0;
        memset(graph,0,sizeof graph);
        memset(flag,false,sizeof flag);
        while(gets(graph[++m]))
        {
            sz = strlen(graph[m]);
            if(graph[m][0]=='_') break;

            if( sz > col) col = sz;

        }
        // getchar();
        row = m;
        row++;
        col = col+5;
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; graph[i][j]; j++)
            {
                if(contour(graph[i][j])==false)
                {
                    ch = graph[i][j];
                }
                if(graph[i][j]=='*')
                {
                    sx = i;
                    sy = j;
                    graph[i][j]=' ';
                }
            }
        }
        int j;
        for(int i = 0; i<row; i++)
        {
            sz = strlen(graph[i]);
            for( j = sz; j<col; j++) graph[i][j]=' ';
            graph[i][j]='\0';
        }
        // cout<<ch<<endl;
        //cout<<row<<' '<<col<<endl;

        dfs(sx,sy);
        for(int i=0; i<row; i++)
        {
            sz = strlen(graph[i]);
            for(j=sz-1; graph[i][j]==' '; j--);
            graph[i][j+1] = '\0';
        }
        // printf("%s",graph[1]);cout<<"fsdfa\n";
        for(int i = 0; i<row; i++) printf("%s\n",graph[i]);
        m = -1;
        col = 0;

    }
    return 0;

}
