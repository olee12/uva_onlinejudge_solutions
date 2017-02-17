#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 60
typedef struct
{
    char ch;
    int num;
} bear;
int hole;
char ch=0;
bear ara[2050];
char graph[MAX][MAX];
char flag[MAX][MAX];
int row,col;
int x[]={-1,0,0,1};
int y[]={0,1,-1,0};
void dfs(int i,int j)
{

    graph[i][j]='.';
    hole++;
    int nx,ny;
    for(int k = 0;k<8;k++){
        nx = i + x[k];
        ny= j + y[k];
        if(nx>=0 && nx<row && ny>=0 && ny<col && graph[nx][ny]==ch)
            dfs(nx,ny);
    }

}
bool comp(bear a,bear b)
{
    if(a.num != b.num) return a.num>b.num;
    return a.ch<b.ch;
}
int main()
{
    int i,j,k,l,c=1;
    int n;
    while(scanf("%d %d",&row,&col) && row && col){
            n=0;
        for(i=0;i<row;i++) scanf(" %s",graph[i]);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(isalpha(graph[i][j])){
                    hole =0;
                    ch = graph[i][j];
                    dfs(i,j);
                    ara[n].ch=ch;
                    ara[n].num=hole;
                    n++;
                }
            }
        }
         printf("Problem %d:\n",c++);
        sort(ara,ara+n,comp);
        for(int i = 0;i<n;i++){
            printf("%c %d\n",ara[i].ch,ara[i].num);
        }
    }
    return 0;
}
