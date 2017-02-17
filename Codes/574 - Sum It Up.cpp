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
vector<int> res;
bool taken[M];
int ara[M];
int n,t;
int sum=0;
map<vi,int> mp;
int call(int start)
{
    if(sum==t)
    {
        //  cout<<sum<<endl;
        mp[res]=1;
    }
    for(int i = start; i<=n; i++)
    {
        if(taken[i]==false)
        {
            taken[i]=true;
            res.push_back(ara[i]);
            sum+=ara[i];
            call(i+1);
            sum-=ara[i];
            taken[i]=false;
            res.pop_back();
        }
    }
}
int main()
{
    while(sf("%d %d",&t,&n))
    {
        if(n==0) return 0;
        pf("Sums of %d:\n",t);
        for(int i =1; i<=n; i++)
        {
            sf("%d",ara+i);
        }
        sum = 0;
        res.clear();
        mp.clear();
        call(1);
        if(mp.size()==0)
        {
            pf("NONE\n");
            continue;
        }
        map<vi,int> :: iterator it = mp.end();
        it--;

        for(; ; it--)
        {
            //  VII vv = it->fr.begin();
            bool f = false;
            for(int i = 0; i<it->fr.size(); i++)
            {
                if(f)pf("+");
                f=1;
                pf("%d",it->fr[i]);
            }
            puts("");
            if(it==mp.begin()) break;
        }
    }
    return 0;
}
