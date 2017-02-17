#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
int a[1000010];
int main()
{
    map<int,int> mp;
    mp.clear();
    int test,k,n,m,i,j,ans,maxi;
    scanf("%d",&test);
    while(test--)
    {
        mp.clear();
        ans=0,maxi=0;
        scanf("%d",&n);
        for(k=1; k<=n; k++)
        {
            scanf("%d",&a[k]);
        }

        for(k=1; k<=n; k++)
        {
            if(!mp[a[k]])
            {
                mp[a[k]]=k;
                ans++;
                if(ans>maxi) maxi=ans;
            }
            else
            {
                if(ans>maxi) maxi=ans;
                k = mp[a[k]];
                ans=0;
                mp.clear();
            }
        }
        printf("%d\n",maxi);
    }
    return 0;

}
