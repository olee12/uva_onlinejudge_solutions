#include<cstring>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int row,col;
char graph[105][105];
int x_axis[] = {0,0,-1,1};
int y_axis[] = {1,-1,0,0};
int cnt =0;
inline bool valid(int x,int y)
{
    return (x>=0&&x<row && y>=0&&y<col);
}
void dfs(int i,int j)
{

    graph[i][j]='1';
    cnt++;
    for(int k=0; k<4; k++)
    {
        int tx = i+x_axis[k];
        int ty = j+y_axis[k];
        if(valid(tx,ty)) if(graph[tx][ty]=='0') dfs(tx,ty);

    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    int test;
    int dx,dy;
    bool f = false;
    scanf("%d",&test);
    getchar();/// for new line after scanf
    getchar();    /// a blank line after data set number
    while(test--)
    {

        if(f) puts("");
        f = true;
        int m = 0;
        scanf("%d %d\n",&dx,&dy);
      //  cout<<dx<<' '<<dy<<endl;
       // gets(graph[0]);

        while(gets(graph[m]) && graph[m][0]!='\0')
        {
          //  puts(graph[m]);
           // if(strlen(graph[m])==0) break;
            m++;
        }
        //for(int i = 0; i<m; i++) puts(graph[i]);
        row = m;
       // cout<<row<<endl;
        col = strlen(graph[0]);
        cnt = 0;
        if(graph[dx-1][dy-1]=='0')
        dfs(dx-1,dy-1);
        printf("%d\n",cnt);


    }
    return 0;
}


