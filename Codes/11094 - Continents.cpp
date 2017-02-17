#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
char graph[30][30];
int area;
int row,col;
char king;
int x[]={0,0,1,-1,1};
int y[]={1,-1,0,0};
void DFS(int i,int j);

int main()
{
    //freopen("input.txt","r",stdin);
    int i, j, k, l;
    int maxx;
    int x,y;
    while(scanf("%d %d",&row,&col)==2){
        for(i=0;i<row;i++) scanf(" %s",graph[i]);
        scanf("%d %d",&x,&y);
        king = graph[x][y];
        area = maxx=0;
        DFS(x,y);
        for(i=0;i<row;i++){
            for(j = 0;j<col;j++){
                if(graph[i][j]==king){
                    area=0;
                    DFS(i,j);
                    if(maxx<area) maxx=area;
                }
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}

void DFS(int i,int j)
{
    int tx,ty;
    graph[i][j]='.';
    area++;
    for(int k=0;k<4;k++){
        tx=i+x[k];
        ty = (j+y[k])%col;
        if(ty<0) ty = col-1;
        if(tx>=0&&tx<row&&graph[tx][ty]==king)
        DFS(tx,ty);
    }

}

