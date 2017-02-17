#include<bits/stdc++.h>
using namespace std;
long long int hi,lo,a[92683];
typedef long long ll;
int c;
void bins(int n)
{
    lo = 0;
    hi = c-1;
    int mid;
    while(lo<hi)
    {
        mid = (hi+lo)/2;
        if(n>a[mid]) lo=mid+1;
        else hi = mid;
    }
}
int main()
{
    //a[1]= 0;
    a[0]=0;
    int i;
    long long ma = 1LL<<31;
    for(c = 1; a[c-1] < ma; c++)
    {
        a[c] = a[c-1] + ((c+1)>>1);
        //cout<<a[i]<<endl;;
    }
    for(int i = 0; i<10; i++) cout<<a[i]<<endl;
    ll x,y;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld %lld",&x,&y);

        int d = y-x;
        bins(d);
        cout<<lo<<endl;
    }
    return 0;
}

