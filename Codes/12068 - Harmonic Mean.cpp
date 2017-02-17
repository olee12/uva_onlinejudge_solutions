#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    ll ara[15];
    int test;
    int n;
    scanf("%d",&test);
    int i;
    ll lcm;int cas=1;
    ll top,bot,a,b;
    while(test--)
    {
        lcm = 1;
        top = 0;
        scanf("%d",&n);
        for(i = 0;i<n;i++)
        {
            scanf("%lld",&ara[i]);
            lcm*=ara[i];
        }
      //  cout<<lcm<<endl;
        for(int i = 0;i<n;i++){
            top += (lcm/ara[i]);
        }

        ll gcd = __gcd(top,lcm);
        //cout<<gcd<<endl;
        top/=gcd;
        lcm/=gcd;
        a = top;
        b = n*lcm;
        gcd = __gcd(b,a);
        b/=gcd;
        a/=gcd;
        //cout<<top<<endl;
        printf("Case %d: %lld/%lld\n",cas++,b,a);
    }
    return 0;
}
