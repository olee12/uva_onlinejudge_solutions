#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    while(scanf("%lld",&n) && n>=0)
    {
        if(n==1) printf("0%%\n");
        else printf("%lld%%\n",n*25);
    }
    return 0;
}
