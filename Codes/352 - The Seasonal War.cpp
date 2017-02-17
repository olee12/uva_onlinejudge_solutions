#include<stdio.h>
#include<iostream>
using namespace std;
char ara[30][30];
int count;
int row;
void dfs(int i,int j);
void bf(int i,int j);
int x_axis[8]={-1,-1,-1,0,0,1,1,1};
int y_axis[8]={0,1,-1,1,-1,0,1,-1};
int nx,ny;
int main()
{
    int i,j,k,l,c=1;
    while(scanf("%d",&row)!=EOF && row){
            count=0;
        for(i=0;i<row;i++) scanf("%s",&ara[i]);
        for(i=0;i<row;i++)
        for(j=0;j<row;j++){
            if(ara[i][j]=='1'){
               count++;
               bf(i,j);
            }
        }

            printf("Image number %d contains %d war eagles.\n",c++,count);
    }
    return 0;

}
void dfs(int i,int j)
{

    if(i<0||i>=row||j<0||j>=row) return ;
    if(ara[i][j]=='0') return ;
        ara[i][j]='0';
        count = 1;
        dfs(i,j+1);
        dfs(i,j-1);
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i-1,j-1);
        dfs(i-1,j+1);
        dfs(i+1,j-1);
        dfs(i+1,j+1);


}

void bf(int i,int j)
{
      ara[i][j]='0';
    int k;

    for(k=0;k<8;k++){
        nx=i+x_axis[k];
        ny=j+y_axis[k];
        if(nx>=0&&nx<row&&ny>=0&&ny<row && ara[nx][ny]=='1')
            bf(nx,ny);
    }

}

/*#include<stdio.h>
char ara[30][30];
int count;
int row;
void dfs(int i,int j);
int x_axis[8]={-1,-1,-1,0,0,1,1,1};
int y_axis[8]={0,1,-1,1,-1,0,1,-1};
int nx,ny;
int main()
{
    int i,j,k,l,c=1;
    while(scanf("%d",&row)!=EOF && row){
            l=0;
        for(i=0;i<row;i++) scanf("%s",&ara[i]);
        for(i=0;i<row;i++)
        for(j=0;j<row;j++){
            if(ara[i][j]=='1'){
                count =0;
                dfs(i,j);
                if(count) l++;
            }
        }

            printf("Image number %d contains %d war eagles.\n",c++,l);
    }
    return 0;

}
void dfs(int i,int j)
{

    if(i<0||i>=row||j<0||j>=row) return ;
    if(ara[i][j]=='0') return ;
        ara[i][j]='0';
        count = 1;
        dfs(i,j+1);
        dfs(i,j-1);
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i-1,j-1);
        dfs(i-1,j+1);
        dfs(i+1,j-1);
        dfs(i+1,j+1);


}

void bf(int i,int j)
{
    ara[i][j]='0';
    for(int k=0;k<8;k++){
        nx=i+x_axis[i];
        ny=j+y_axis[i];
        if(nx>=0&&nx<row&&ny>=0&&ny<col && ara[nx][ny]=='1')
            bf(nx,ny);
    }

}*/
