#include<stdio.h>

int main()
{
    int t,c;
    int r;
    int l,d,x1,x2,y1,y2;
    while(scanf("%d",&t)==1)
    {
        c=1;
        while(t--)
        {
            scanf("%d",&r);

            l=r*5;
            d=l*(float)(60./100.);
            x1=l*.45;
            x2=l*.55;
            printf("Case %d:\n",c++);
            printf("-%d %d\n",x1,d/2);
            printf("%d %d\n",x2,d/2);
            printf("%d -%d\n",x2,d/2);
            printf("-%d -%d\n",x1,d/2);
        }
    }
    return 0;
}

/*Case 1:
-45 30
55 30
55 -30
-45 -30
Case 2:
-225 150
275 150
275 -150
-225 -150*/

