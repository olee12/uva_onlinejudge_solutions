#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define ROO 35
#define COO 95
char graph[ROO][COO];
char wall;
char ch;
int x[]={-1,0,0,1};
int y[]={0,1,-1,0};
void dfs(int i,int j)
{
    //cout<<" dfa"<<graph[i][j]<<"fasdf\n";
    if(graph[i][j]!=' ') return;
    graph[i][j]= ch;
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
    int row,col;
    int i,j,k,l;
    row = -1;

    while(gets(graph[++row])){

        while(graph[row][0]!='_')
                gets(graph[++row]);
            for(i=0;i<row;i++){
                col = strlen(graph[i]);
                for(j=0;j<col;j++){
                    if(graph[i][j]!=' '){
                        wall = graph[i][j];

                        break;
                    }
                    if(graph[i][j]!=' ') break;
                }
            }

    for(i=0;i<row;i++){
        col = strlen(graph[i]);
        for(j=0;j<col;j++){
            if(graph[i][j]!=' ' && graph[i][j]!=wall){
               ch = graph[i][j];
               graph[i][j]=' ';
                dfs(i,j);

            }

        }
    }
    for(i=0;i<=row;i++)
        printf("%s\n",graph[i]);
    row=-1;
    }
    return 0;

}
