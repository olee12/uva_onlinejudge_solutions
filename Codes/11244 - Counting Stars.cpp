#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char ara[100][100];
int count;
int row;
int col;
void dfs(int i,int j);
int main()
{
    int i,j,k,l;
    while(scanf("%d %d",&row,&col)==2 && row && col){
            k=0;
        for(i=0;i<row;i++) scanf("%s",ara[i]);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(ara[i][j]=='*'){
                    dfs(i,j);

                }
                if(count==1) k++;
                count=0;
            }
        }
        printf("%d\n",k);


    }
    return 0;

}
void dfs(int i,int j)
{
    if(i<0 || j < 0 || i>=row || j>=col) return ;
    if(ara[i][j]=='.') return ;
    ara[i][j] = '.';
    count++;
    dfs(i+1,j+1);
    dfs(i-1,j+1);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i+1,j-1);
    dfs(i,j-1);
    dfs(i-1,j-1);

}
