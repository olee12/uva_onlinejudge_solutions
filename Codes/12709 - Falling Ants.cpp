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
    int s1,sum;
    int mx ;
    int n;
    int l,w,h;
    while(sf("%d",&n), n)
    {
        mx = -1000;
        s1=0;sum = 0;
        for(int i = 0;i<n;i++)
        {
            scanf("%d %d %d",&l,&w,&h);
            if(h>=mx){
                sum = l*w*h;
                if(mx==h)
                {
                    if(sum>s1) s1 = sum;
                }
                if(h>mx){
                    mx = h;
                    s1=sum;
                }
            }
        }
        printf("%d\n",s1);
    }
}
