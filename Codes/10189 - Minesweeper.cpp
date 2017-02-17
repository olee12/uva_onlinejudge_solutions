#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int count;
int row,col;
char ara[150][150];
void bf(int i,int j);
int x_axis[8]={-1,-1,-1,0,0,1,1,1};
int y_axis[8]={0,1,-1,1,-1,0,1,-1};
int nx ,ny;
void bf(int i,int j)
{

    int k;

    for(k=0;k<8;k++){
        nx=i+x_axis[k];
        ny=j+y_axis[k];
        if(nx>=0&&nx<row&&ny>=0&&ny<col&& ara[nx][ny]=='*')
            count++;
    }

}
int main()
{
    int test=1;
    int i,j,k,l;
    while(scanf("%d %d",&row,&col) && (row || col ) ){
            if(test>1) printf("\n");
        for(i=0;i<row;i++) scanf("%s",ara[i]);
        for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(ara[i][j]=='.'){
                bf(i,j);

                ara[i][j]=count+'0';

                count=0;
            }

        }

        }
        printf("Field #%d:\n",test++);
        for(i=0;i<row;i++)
            printf("%s\n",ara[i]);

    }
    return 0;
}


