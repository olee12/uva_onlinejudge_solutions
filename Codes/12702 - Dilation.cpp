/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ara[120][120];
int tmp[120][120];
int main()
{

    int test;
    int cas = 1;
    int m,n,i,j,x,y,row,col,r,c;
    scanf("%d",&test);
    while(test--)
    {
        printf("Case %d:\n",cas++);

        scanf("%d %d",&row,&col);
        for(i = 0; i<row; i++)
            for(j = 0; j<col; j++) scanf("%d",&ara[i][j]);

        scanf("%d %d",&r,&c);
        x = r>>1;
        y = c>>1;
        for(i = 0; i<r; i++)
            for(j = 0; j<c; j++) scanf("%d",&tmp[i][j]);

        for(m=0; m<row; m++)
        {
            for(n = 0; n<col; n++)
            {
                if(ara[m][n]==1)
                {
                    int e = (m-x) <=0 ? 0 : m-x;
                    int ti = (x-m)<=0 ? 0 : x-m;
                    int pr = (x+m)>=row ? row-1: x+m;
                    int f,xx = (n-y) < 0 ? 0 : n-y;
                    int tj,yy = (n-y) >= 0 ? 0 : abs(n-y);
                    int pc = (y+n) >=col ? col-1: y+n;

                    for( ; e<=pr; e++,ti++)
                    {
                        int f = xx;
                        int tj = yy;
                        for( ; f<=pc; f++,tj++)
                        {

                            ara[e][f] = tmp[ti][tj] && ara[e][f]!=1 ? 5 : ara[e][f];

                        }
                    }
                }
            }
        }
        for(i = 0; i<row; i++)
        {
            for(j = 0; j<col-1; j++)
            {
                printf("%d ",ara[i][j]?1:0);
            }
            printf("%d\n",ara[i][j]?1:0);
        }


    }
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

short img[120][120];
short mask[20][20];

int main()
{
#ifdef DEBUG_LINE
    freopen("input.txt", "r", stdin);
#endif // DEBUG_LINE

    int test, cas, i, j;
    int r1, r2, c1, c2;
    int p, q, x,y;
    int e,f,ti,tj,pr,pc,xx,yy;
    queue<int> Q;

    scanf("%d", &test);
    for(cas = 1; cas <= test; ++cas)
    {
        //main image
        scanf("%d %d", &r1, &c1);
        for(i=0; i<r1; ++i)
            for(j=0; j<c1; ++j)
            {
                scanf("%d", img[i]+j);
                if(img[i][j])
                {
                    Q.push(i);
                    Q.push(j);
                }
            }

        //mask image
        scanf("%d %d", &r2, &c2);
        for(i=0; i<r2; ++i)
            for(j=0; j<c2; ++j)
                scanf("%d", mask[i]+j);

        //add mask
        x = r2>>1, y = c2>>1;
        while(Q.size())
        {
            p = Q.front();
            Q.pop();
            q = Q.front();
            Q.pop();

            e = max(0,p-x);
            ti = max(0,x-p);
            pr = min(r1-1, x+p);
            xx = max(0,q-y);
            yy =  (q-y) >= 0 ? 0 : abs(q-y);
            pc =min(c1-1,y+q);

            for( ; e<=pr; e++,ti++)
            {
                f = xx;
                tj = yy;
                for( ; f<=pc; f++,tj++)
                {

                    img[e][f] |= mask[ti][tj] ;

                }
            }


        }

        //print result
        printf("Case %d:\n", cas);
        for(int i=0; i<r1; ++i)
        {
            printf("%d", img[i][0]);
            for(int j=1; j<c1; ++j)
                printf(" %d", img[i][j]);
            putchar('\n');
        }
    }

    return 0;
}

