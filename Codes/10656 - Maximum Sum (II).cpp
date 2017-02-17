#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
int ara[10005];
int sum_ara[10005];
int main()
{
    // freopen("input.txt","r",stdin);
    int n;
    int x,y;
    while(scanf("%d",&n))
    {
        if(n==0) return 0;
        x=1,y=0;
        bool f = false;
        for(int i = 1; i<=n; i++)
        {
            scanf("%d",&x);
            if(x==0) f = true;
            if(x)
                sum_ara[y++] = x;
            // cout<<ara[i]<<'\n';
        }
        if(y==0 && f) printf("%d",0);
        else if(y>2)
        {


            for(int i = 0; i<y; i++)
            {
                if(i) printf(" ");

                printf("%d",sum_ara[i]);
            }
        }
        puts("");
    }
    return 0;

}
