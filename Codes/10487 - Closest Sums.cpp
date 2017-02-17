#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int ara[2000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int close;
    int n,q;

    int tmp;
    int res;
    int val;
    int cas = 1;
    while(scanf("%d",&n) && n)
    {
        printf("Case %d:\n",cas++);
        for(int i = 0; i<n; i++)
        {
            scanf("%d",&ara[i]);
        }
        vector<int> sum;
       // sum.clear();
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {

                sum.push_back(ara[i]+ara[j]);

            }
        }
        scanf("%d",&q);
        for(int i = 0; i<q; i++)
        {
            scanf("%d",&val);
            //cout<<val<<endl;
            close =1e7;
            // cout<<close<<endl;
            for(int j = 0; j<(int)sum.size(); j++)
            {
                tmp = abs(sum[j]-val);
                //cout<<tmp<<' '<<sum[j]<<endl;;
                if(tmp < close)
                {
                    close = tmp;
                    res = sum[j];
                }
            }
            //puts("");
            printf("Closest sum to %d is %d.\n",val,res);
        }
    }
    return 0;
}
