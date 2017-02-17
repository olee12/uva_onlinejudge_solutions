#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
#define M 100005
int ara[M];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i = 0; i<n; i++) scanf("%d",&ara[i]);
        int q;
        scanf("%d",&q);
        for(int i = 0; i<q; i++)
        {
            int num;
            scanf("%d",&num);

            int *lo = lower_bound(ara,ara+n,num);
            int *hi = upper_bound(ara,ara+n,num);

            if(n==1 && num == ara[0])
            {
                puts("X X");
                continue;
            }
            if(lo==ara && hi != ara+n) printf("X %d\n",*hi);
            else if(hi== ara+n) printf("%d X\n",*(--lo));
            else
            {
                lo--;
                printf("%d %d\n",*lo,*hi);
            }

        }
    }
    return 0;

}
