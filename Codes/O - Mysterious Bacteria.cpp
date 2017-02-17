#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
long long base(long long  x,long long i)
{

    for(; i*i<=x; i++)
    {
        cout<<i<<endl;
        if(x%i==0)
        {
            while(x%i==0) x/=i;
            if(x==1) return i;
            else return -1;
        }
    }
    return -1;
}
long long func(long long x)
{
    map<long long ,long long> prime;
    long long n = x;
    if(n<0) n*=-1;
    for(long long i = 2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            //
            while(n%i==0)
            {
                prime[i]++;
                n/=i;
            }
        }

    }
    if(n>1) prime[n]++;
    map<long long ,long long > :: iterator it;
    for(long long i = 32; i>=1; i--)
    {
        bool flag = true;
        for(it=prime.begin(); it!=prime.end(); it++)
        {
            if(it->second % i!=0)
            {
                flag = false;
                break;
            }
        }
        if(flag && x>=0) return i;
        if(x<0 &&flag && (i%2==1)) return i;
    }

}
int main()
{
   // freopen("input.txt","r",stdin);
  //  int cas = 1;
    int test;
    long long x;
    long long b;
    scanf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {
        scanf("%lld",&x);
        long long res = func(x);
        // cout<<res<<endl;
        printf("Case %d: %lld\n",cas,res);
        /*
        else
            b = base(x,2);

        //cout<<b<<endl;
        if(b==-1) printf("Case %d: 1\n",cas);
        else printf("Case %d: %.0lf\n",cas, log((double)x)/log((double)b));*/
    }
    return 0;
}
