#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,c,ans;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        ans = 1;
       // printf("%lld %lld\n",n,m);
        //if(m==0) puts("1");
        c = n - m + 1;
        for(ll i = n;i>=c;i--)
        {
           // printf("fdsd");
            ans*= i;
            while(ans%10 == 0) ans/=10;
            ans = ans % 1000000000;
        }
        printf("%lld\n",ans%10);
    }
    return 0;
}
