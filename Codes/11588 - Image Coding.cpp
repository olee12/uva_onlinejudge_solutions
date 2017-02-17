#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGWE
    int r,c,m,n;
    int test;
    int ara[28];
    char ch;
    int cas=1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d %d ",&r,&c,&m,&n);

        mem(ara);
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                scanf(" %c",&ch);
                ara[ch-'A']++;
               // cout<<ch;
                //   if(i%c==0) puts("");
            }
           // cout<<endl;
        }
        int mx=0;
        int sum = 0;
        for(int i = 0; i<28; i++) if(ara[i]>mx) mx = ara[i];
        for(int i = 0; i<28; i++)
        {
            if(ara[i]==mx) sum +=(m*ara[i]);
            else sum+= (ara[i]*n);
        }
        printf("Case %d: %d\n",cas++,sum);
    }
    return 0;
}

