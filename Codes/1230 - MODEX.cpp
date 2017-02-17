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
typedef long long ll;
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
int mood;
ll pow_mood(int n, int k)
{
    if (k == 0) return 1;
    ll temp = pow_mood(n, k >> 1);
    temp = temp * temp % mood;
    if (k & 1) temp = temp * n % mood;
    return temp;
}
int main()
{
    int n,x,y;
    while(scanf("%d",&n),n)
    {
        while(n--){
            scanf("%d %d %d",&x,&y,&mood);
            printf("%lld\n",pow_mood(x,y));
        }
    }
    return 0;
}
