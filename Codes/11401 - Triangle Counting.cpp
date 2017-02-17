#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    long long n;
    while(scanf("%lld",&n)&&n>=3)
    {
        if(n==3) puts("0");
        else if(n==4) puts("1");
        else if(n==5) puts("3");
        else
        {
            n-=4;
            printf("%lld\n",(((n+2)*(n+4)*(2*n+3))/24));
        }

    }

    return 0;
}
/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll ara[1000050];
void gen()
{
    ara[1]=1;
    ara[2]=3;
    for(ll i= 3;i<=1000000;i++)
    {
        ll val = (i*(i+1))/2;
        ara[i] = val + ara[i-2];
    }
}
int main()
{

    gen();
   // for(int i = 0;i<=20;i++) printf("%d ",ara[i]);

    long long n;
    while(scanf("%lld",&n)&&n>=3)
    {
            n-=3;//
            printf("%lld\n",ara[n]);


    }

    return 0;
}
*/
