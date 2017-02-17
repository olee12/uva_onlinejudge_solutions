#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int ara[1005];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int test;int n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        int cnt = 0;
        for(int i = 1;i<n;i++)
            for(int j = 0;j<i;j++)
        {
            if(ara[j]<=ara[i]) cnt++;
        }
        printf("%d\n",cnt);
    }
}
