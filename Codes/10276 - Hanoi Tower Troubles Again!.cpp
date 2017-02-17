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
//#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 105
#define sf scanf
#define pf printf
#define INF 2061109567
int N;
int ara[M];
int cnt ;
void func(int val,int p)
{
    if(p==N) return;
    if(ara[p]==0)
    {
        ara[p]=val;
        cnt++;
        return func(val+1,p);
    }
    for(int i = 0; i<=p; i++)
    {
        int sq= (int)sqrt(ara[i]+val);
        if(sq*sq==ara[i]+val)
        {
            cnt++;
            ara[i]=val;
            return func(val+1,p);
        }
    }
    return func(val,p+1);
}
int main()
{
    int test;
    int p;
    sf("%d",&test);
    while(test--)
    {
        memset(ara,0,sizeof ara);
        sf("%d",&N);
        cnt = 0;
        func(1,0);
        pf("%d\n",cnt);
    }

}
