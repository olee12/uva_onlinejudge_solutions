#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long factorials[23]=
{
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800,
    479001600,
    6227020800,
    87178291200,
    1307674368000,
    20922789888000,
    355687428096000,
    6402373705728000,
    121645100408832000,
    2432902008176640000

};
long long fact(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
   // freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
   /* for(int i = 0; i<21; i++)
    {
        factorials[i]=fact(i);
        printf("%lld,\n",factorials[i]);
    }*/

    char ara[30];
    int same[150];
    int test;
    ll val = 0;
    int i,j,l;
    int cas=1;
    scanf("%d",&test);
    while(test--)
    {
        memset(same,0,sizeof same);
        scanf("%s",ara);
        l = strlen(ara);
        for(i = 0; i<l; i++)
        {
            same[ara[i]-'A']++;
        }
        val = factorials[l];
        for(int i = 0; i<30; i++)
            if(same[i]>1)
            {
                val/=factorials[same[i]];
            }
        printf("Data set %d: %lld\n",cas++,val);

    }
    return 0;
}
