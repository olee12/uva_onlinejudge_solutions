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
#include<sstream>
#include<stack>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 1000005
#define sf scanf
#define pf printf
#define INF 1e9
#define M 1299800
bool flag[M];
int prime[100080];
int c;
void sieve()
{
    int add;
    int sq = (int) sqrt(M);
    prime[c++]=2;
    for(int i = 4; i<M; i+=2) flag[i]=true;
    for(int i = 3; i<M; i+=2)
    {
        if(flag[i]==false)
        {
            prime[c++]=i;
            if(sq >=i)
            {
                int add = i*2;
                for(int j = i*i; j<M; j+=add) flag[j]=true;
            }
        }
    }
}
int main()
{
    sieve();
 //   cout<<c<<endl;
    int n;
    int * p;
    while(sf("%d",&n),n)
    {
        if(flag[n]==0)
        {
            pf("0\n");
            continue;
        }
        p = lower_bound(prime,prime+c,n);
        //cout<<*p - *(p-1)<<endl;
        int res = *p - *(p-1);
        if(res>1)
        {
            pf("%d\n",res);
        }
        else pf("0\n");
    }
    return 0;

}
