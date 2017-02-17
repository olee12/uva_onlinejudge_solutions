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
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 10005
#define sf scanf
#define pf printf
#define INF 2061109567
int ara1[M],ara2[M];
int main()
{
    int test,m,n,i,j,res,sum;
    sf("%d",&test);
    while(test--)
    {
        res=0;
        sf("%d %d",&n,&m);
        for(i= 1;i<=n;i++) sf("%d",ara1+i);
        for(i= 1;i<=m;i++) sf("%d",ara2+i);
        i = j = 1;
        sort(ara2+1,ara2+m+1);
        sort(ara1+1,ara1+n+1);
        while(i<=n && j<=m)
        {
           // cout<<i<<' '<<j<<endl;
            if(ara1[i]>ara2[j])
            {
                j++;
                res++;
            }
            else if(ara1[i]<ara2[j])
            {
                i++;
                res++;
            }
            else {
                i++;
                j++;
            }
        }
        if(i!=n+1) res+= (n-i+1);
        else if(j!=m+1) res+=(m-j+1);
        pf("%d\n",res);
    }
    return 0;
}
