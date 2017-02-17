#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX 120
using namespace std;
int tower1[MAX];
int tower2[MAX];
int m,n;
int c[MAX][MAX],b[MAX][MAX];
int i,j,k,l;
int LCSlength()
{

    for (i=1; i<=m; i++) c[i][0]=0;
    for (j=0; j<=n; j++) c[0][j]=0;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        {
            if (tower1[i-1]==tower2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1; /* from north west */
            }
            else if (c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2; /* from north */
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3; /* from west */
            }
        }


    return c[m][n];
}

int main()
{

    int cas=1;

    while(scanf("%d %d",&m,&n) && m && n){
            printf("Twin Towers #%d\n",cas++);
        for(i=0;i<m;i++) scanf("%d",&tower1[i]);
        for(i=0;i<n;i++) scanf("%d",&tower2[i]);
        printf("Number of Tiles : %d\n",LCSlength());
        printf("\n");
    }
    return 0;
}
