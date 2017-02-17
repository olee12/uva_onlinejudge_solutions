#include<stdio.h>
int x_axis[8]={-1,-1,0,  0,1,1};
int y_axis[8]={0, -1,1, -1,0,1};
char black[210][210];
int row;
int flag;
void dfs(int i,int j);
int main()
{
    freopen("input.txt","r",stdin);
    int i,j,l=1;
    int b=0,w;
    while(scanf("%d",&row)==1 && row ){
        for(i=0;i<row;i++) scanf(" %s",black[i]);

        for(j=0;j<row && !flag;j++){
                if(black[0][j]=='b')
                    dfs(0,j);
        }
        if(flag) printf("%d B\n",l++);
        else printf("%d W\n",l++);
            flag = 0;
    }
    return 0;

}
void dfs(int i,int j)
{
    if(i<0||i>=row||j<0||j>=row) return ;
    if(black[i][j]=='w') return ;
        black[i][j] = 'w';
        if(i==(row-1)) flag=1;
        dfs(i-1,j-1);
        dfs(i+1,j+1);
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
        dfs(i,j+1);
}

void df(int i,int j)
{

}


/*4  {-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1 ,1}
bbwb
wwbw
bbwb
bwww
4
bbwb
wwbw
bwwb
wwbb
0*/
/*
#include<stdio.h>
int x_axis[8]={-1,-1,0,  0,1,1};
int y_axis[8]={0, -1,1, -1,0,1};
char black[210][210];
int row;
int flag;
void bfs(int i,int j);
int main()
{
    int i,j,l=1;
    int b=0,w;
    while(scanf("%d",&row)==1 && row ){
        for(i=0;i<row;i++) scanf(" %s",black[i]);

        for(j=0;j<row && !flag;j++){
                if(black[0][j]=='b')
                    bfs(0,j);
        }
        if(flag) printf("%d B\n",l++);
        else printf("%d W\n",l++);
            flag = 0;
    }
    return 0;

}


void bfs(int i,int j)
{
    if(i<0||i>=row||j<0||j>=row) return ;
    if(black[i][j]=='w') return ;

        black[i][j] = 'w';
        if(i==(row-1)) flag=1;
        bfs(i-1,j-1);
        bfs(i+1,j+1);
        bfs(i+1,j);
        bfs(i-1,j);
        bfs(i,j-1);
        bfs(i,j+1);

}*/
