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
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 1000005
#define MM 1010
#define sf scanf
#define pf printf
#define INF 2061109567
int main()
{
    int x,k;
    int p,q;
    int test;
    sf("%d",&test);
    while(test--)
    {
        sf("%d %d",&x,&k);
        q = x%k;
        if(!q) pf("0 %d\n",k);
        else pf("%d %d\n",k-q,q);
    }
    return 0;
}
