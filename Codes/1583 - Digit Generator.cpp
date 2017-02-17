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
typedef pair<int,ii> iii;
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
#define M 120000
#define sn scanf
#define pf printf
int ara[M];
void func()
{
    int tmp;
    int sum = 0;
    for(int i= 100000; i>=0; i--)
    {
        sum = 0;
        tmp = i;
        sum+=i;
        while(tmp)
        {
            sum+=(tmp%10);
            tmp/=10;
        }
        ara[sum]=i;
    }
}
int main()
{
    memset(ara,-1,sizeof ara);
    func();
    int n;
    int t;
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        if(ara[n]!=-1) pf("%d\n",ara[n]);
        else printf("0\n");
    }
    return 0;
}
