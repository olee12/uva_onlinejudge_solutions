#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

class point
{
public:
    int x,y;
};
int res[2500000];
point ara[1050];
int dist[30005];
int main()
{
    for(int i = 0; i<=30001; i++) dist[i] = i*i;

    //freopen("input.txt","r",stdin);
    int n;
    int cas = 1;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        //si s;
        int cnt = 0;
        for(int i = 0; i<n; i++)
        {
            scanf("%d %d",&ara[i].x,&ara[i].y);
            for(int j = 0; j<i; j++)
            {
                res[cnt++] = dist[abs(ara[i].x - ara[j].x)] + dist[abs(ara[i].y- ara[j].y)];
            }
        }

        res[cnt] = -1;
        sort(res, res + cnt);
        int snd = 1;
        for(int i = 1; i <= cnt; ++i) snd += res[i] != res[i - 1];
        printf("Case %d: %d\n", cas++, snd);
    }
    return 0;
}
