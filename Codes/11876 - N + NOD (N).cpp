#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<iterator>
#include<set>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
typedef vector<int> vi;
#define MAX 500000
#define M 1000100
#define L 100000
#define pb push_back
#define VII vi :: iterator
int c;
bool flag[MAX];
int prime[L];
void sieve()
{
    prime[c++]=2;
    register int i,j,add;
    for(i = 4; i<MAX; i+=2) flag[i]=true;
    for(i = 3; i<MAX; i+=2)
    {
        if(flag[i]==false)
        {
            prime[c++]=i;
            if(MAX/i >= i)
            {
                add = i*2;
                for(j = i*i; j<MAX; j+=add) flag[j]=true;
            }
        }
    }
}
int NOD(int n)
{
    int divisor = 1;
    for(int i = 0; n!=1; i++)
    {

        if(n%prime[i]==0)
        {
            int cnt=1;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            divisor*=cnt;
        }
    }
    //cout<<n<<endl;
    return divisor;
}
vector<int> result;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    sieve();
    //cout<<c<<endl;
    result.push_back(1);
    result.push_back(2);
    for(int i = 2; result[i-1]<M; i++)
    {
        result.pb(result[i-1]+NOD(result[i-1]));
    }

    VII lo ,hi;
    int m,n;
    int test;
    scanf("%d",&test);
    int cas=1;
    while(test--)
    {
        scanf("%d %d",&m,&n);
        lo = lower_bound(result.begin(),result.end(),m);
        hi=lower_bound(result.begin(),result.end(),n);

        int cnt=0;

        while(*hi <= n) hi++;
        printf("Case %d: %d\n",cas++,hi-lo);
    }
    return 0;
}

