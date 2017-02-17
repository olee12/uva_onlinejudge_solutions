#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 200
#define sf scanf
#define pf printf
#define INF 2147483645
typedef long long ll;
int main()
{
    ll sum,n,a;
    while(scanf("%lld",&sum) && sum > 0)
    {
        //cout<<(sum<<1)<<endl;
        for(n = sqrt(2.0*sum); n>0; n--)
            if(((sum<<1) + n - n*n)%(n<<1)==0)
            {
               // cout<<n<<endl;
                a = ((sum<<1) + n - n*n)/(n<<1);
                printf("%lld = %lld + ... + %lld\n",sum,a,a+n-1);
               // break;
            }
        //printf("%lld = %lld + ... + %lld\n",sum,a,a+n-1);
    }
    return 0;

}
