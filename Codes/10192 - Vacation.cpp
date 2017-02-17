#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define MAX 110
char X[MAX],Y[MAX];
int i,j,k,l,c[MAX][MAX],b[MAX][MAX];
int LCSlength()
{
    int m = strlen(X);
    int n = strlen(Y);
    for(i = 1;i<=m;i++) c[i][0]=0;
    for(j = 0;j<=n;j++) c[0][j]=0;
    for(i = 1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1;
            }
            else if(c[i-1][j]>= c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
    return c[m][n];
}
int main()
{
    int cas=1;
    while(gets(X) && X[0] != '#'){
        gets(Y);
        printf("Case #%d: you can visit at most %d cities.\n",cas++,LCSlength());
    }
    return 0;
}
