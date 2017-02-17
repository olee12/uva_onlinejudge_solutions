#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int sum[15];
int main()
{
    int ara[100][100];
    int col,i,count=1,k,j;
    int row,size;
    while(scanf("%d",&size)==1&&size){
        for(row=1;row<size+1;row++)
            for(col=1;col<size+1;col++) scanf("%d",&ara[row][col]);
            row=1;
             i=0;
             k=ceil(size/2.0);
        while(i!=k){
            for(col=row;col<size+1;col++) sum[i]+=ara[row][col];
            for(col=row+1;col<size+1;col++) sum[i]+=ara[col][size];
            for(col=col=size-1;col>row-1;col--) sum[i]+=ara[size][col];
            for(col=size-1;col>row;col--) sum[i]+=ara[col][row];
            i++;
            row+=1;
            size-=1;
        }
        printf("Case %d: ",count++);
        for(j=0;j<i-1;j++){
                printf("%d ",sum[j]);
        sum[j]=0;

        }
        printf("%d",sum[j]);
        sum[j]=0;
        printf("\n");

    }
    return 0;
}
