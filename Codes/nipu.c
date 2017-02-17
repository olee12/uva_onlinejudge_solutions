#include<stdio.h>
#include<math.h>
int main()
{
    int i=0, n, x, y;
    while(scanf("%d", &x)==1 && x>0)
    {
        for(n=0; n<15; n++)
        {
            y=pow(2,n+1);

            if(y<x)
                continue;
            else
                break;
            if(n == 0){
                n = -1;
            }
        }
        printf("Case %d: %d\n",++i, n+1);
    }
    return 0;
}
