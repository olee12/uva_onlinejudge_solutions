/* BFS VERSION IS SLOWER THEN DFS VERSION , I GOT A LOT RW FOR MY BUG IN INDEXING <OLEE>*/
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 105
char graph[MAX][MAX];
int row , col;
int area=0;
int visited[MAX][MAX];
queue<int> Q;
int x_axis[]= {-1,-1,-1,0,0,1,1,1};
int y_axis[]= {0,1,-1,1,-1,0,1,-1};


void bfsQ(int i,int j)
{
    //col = strlen(graph[0]);
    for(col=0; graph[0][col]; col++);

    if(graph[i][j]=='L'||i>=row||j>=col)
    {
        area=0;
        return;
    }
    memset(visited,0,sizeof(visited));
    Q.push(i);
    Q.push(j);
    area=1;
    visited[i][j]=1;
    int nx,ny,xxx,yyy;
    while(!Q.empty())
    {
        nx = Q.front();
        Q.pop();
        ny = Q.front();
        Q.pop();
        for(int k=0; k<8; k++)
        {
            xxx=nx+x_axis[k];
            yyy = ny + y_axis[k];
            if(xxx >= 0&&yyy >=0 && xxx < row && yyy<col)
            {
                if(visited[xxx][yyy]==0 && graph[xxx][yyy]=='W')
                {
                    visited[xxx][yyy]=1;
                    area++;
                    Q.push(xxx);
                    Q.push(yyy);
                }
            }
        }
    }

}
int main()
{
    int m=0;
    int t;
    int a,b;
    scanf("%d\n\n",&t);
    while(t--)
    {
        while(gets(graph[m]))
        {
            if(graph[m][0]=='\0') break;
            if(graph[m][0] == 'L' || graph[m][0]=='W')
            {
                m++;
                row = m;
            }
            else
            {
                sscanf(graph[m],"%d %d",&a,&b);
                area=0;
                bfsQ(a-1,b-1);
                cout<<area<<endl;
            }
        }
        m=0;
        if(t) printf("\n");
    }
    return 0;
}


DFS VERSION;
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 105

string graph[MAX];
string v[MAX];
int row , col;
int area=0;
int x_axis[]= {-1,-1,-1,0,0,1,1,1};
int y_axis[]= {0,1,-1,1,-1,0,1,-1};

//void dfs(int i,int j,string v[])
//{
//    if(i<0 || i>=row || j<0 || j >= col) return ;
//    if( v[i][j]=='L')
//        return ;
//
//        area++;
//       v[i][j]='L';
//        dfs(i,j+1,v);
//        dfs(i,j-1,v);
//        dfs(i-1,j,v);
//        dfs(i+1,j,v);
//        dfs(i-1,j+1,v);
//        dfs(i-1,j-1,v);
//        dfs(i+1,j+1,v);
//        dfs(i+1,j-1,v);
//}

void dfs(int i,int j,string v[])
{
    if(i<0 || i>=row || j<0 || j >= col) return ;
    if(v[i][j]=='L') return;
    v[i][j]='L';
    area++;
    int nx,ny;
    for(int k = 0; k<8; k++)
    {
        nx = i + x_axis[k];
        ny = j + y_axis[k];
        if(nx>=0 && nx< row && ny >= 0 && ny < col && v[nx][ny]=='W' )
        {
            dfs(nx,ny,v);
        }
    }
}
int main()
{
    int m=0;
    int t;
    int a,b;
    scanf("%d\n\n",&t);
    while(t--){
        while(getline(cin,graph[m]),graph[m].size()){

            if(graph[m][0] == 'L' || graph[m][0]=='W') {
                    m++;
                row = m;
                //cout<<row<<"\n";
                col = graph[0].size();
            }
            else{
                    //cout<<row<<endl;

                sscanf(graph[m].c_str(),"%d %d",&a,&b);
                for(int i=0;i<row;i++) v[i]=graph[i];
                area=0;
                dfs(a-1,b-1,v);
                cout<<area<<endl;
            }
        }
    m=0;
        if(t) printf("\n");
    }
    return 0;
}
*/
