#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int shop[25];
    int test;
    int n;
    scanf("%d",&test);

        for(int i = 0; i<test; i++)
        {
            scanf("%d",&n);
            for(int j = 0; j<n; j++) scanf("%d",&shop[j]);
            sort(shop,shop+n);
            printf("%d\n",(shop[n-1]-shop[0])*2);
        }

    return 0;
}
