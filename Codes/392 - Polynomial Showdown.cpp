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
int ara[15];
int main()
{
    bool f;
    while(sf("%d",ara)==1)
    {
        f = true;
        for(int i = 1; i<9; i++) sf("%d",ara+i);
        int i;
        for( i = 0; i<8; i++)
        {
            // cout<<ara[i]<<endl;
            if(ara[i])
            {
                f=false;
                if(ara[i]<0) printf("-");
                if(abs(ara[i])!=1) pf("%d",abs(ara[i]));
                if((8-i)!=1)
                pf("x^%d",8-i);
                else pf("x");
                break;
            }

        }
        i++;
        for(i; i<8; i++)
        {
            if(ara[i])
            {
                f=false;
                if(ara[i]<0) pf(" - ");
                else pf(" + ");
                if(abs(ara[i])!=1) pf("%d",abs(ara[i]));
                if((8-i)!=1)
                pf("x^%d",8-i);
                else pf("x");
            }
        }
        if(f==true) pf("%d",ara[8]);
        else
        {
            if(ara[8])
            {
                if(ara[8]<0) pf(" - ");
                else pf(" + ");
                pf("%d",abs(ara[8]));
            }
        }
        puts("");

    }
    return 0;
}
