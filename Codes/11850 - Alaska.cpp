#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
    int n;
    int ara[1422+20];
    while(scanf("%d",&n)&&n)
    {

        int a;
        bool flag = false;

        for(int i = 0; i<n; i++)
        {
            scanf("%d",ara+i);

        }

        sort(ara,ara+n);
        for(int i = 1; i<n; i++)
        {
            if(ara[i]-ara[i-1] > 200)
            {
                flag = true;
                break;
            }
        }
        if(1422 - ara[n-1] > 100) flag = true;
        if(flag) puts("IMPOSSIBLE");
        else puts("POSSIBLE");
    }
    return 0;
}
