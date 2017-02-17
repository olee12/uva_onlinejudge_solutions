#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int row,col;
int count;
char ara[105][105];
void dfs(int i,int j);
int main()
{
    char ch;
    int i,j,k,l,t;
    while(scanf("%d %d",&row,&col)==2 && row && col)
    {
        l=0;
        for(i=0; i<row; i++){
             scanf("%s",ara[i]);
            }
        for(i=0; i<row; i++)
        {
            for (j=0; j<col ; j++ )
            {
                if(ara[i][j]=='@'){
                count=0;
                dfs(i,j);
                if(count) l++;
                }
            }
        }
        printf("%d\n",l);
    }
    return 0;
}
void dfs(int i,int j)
{
    if(i<0 || i>=row || j<0 || j >= col) return ;
    if( ara[i][j]=='*')
        return ;


        ara[i][j]='*';
        dfs(i,j+1);
        dfs(i,j-1);
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i-1,j+1);
        dfs(i-1,j-1);
        dfs(i+1,j+1);
        dfs(i+1,j-1);
        count=1;


}
