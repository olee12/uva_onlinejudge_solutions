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
#define M 2000000000
#define sf scanf
#define pf printf
#define INF 2147483645
int flag[M/32+10];
bool cheak(int n,int pos)
{
    return (bool)(n&(1<<pos));
}
int Set(int n,int pos)
{
    return n = n | (1<<pos) ;
}
int c;
int prime[1000];
void sieve()
{
    int add;
    int sq = sqrt(M);
    // cout<<"dfasdf\n";
    for(int i = 4;i<M;i+=2) flag[i/32] = Set(flag[i/32],i%32);
    c++;


    for(int i=  3;i<M;i+=2)
    {
        if(cheak(flag[i/32],i%32)==0)
        {
            //cout<<i<<endl;
            c++;
            if(sq>=i)
            {
                for(int j = i*i;j<M;j+=(i<<1)) flag[j/32] = Set(flag[j/32],j%32);
            }
        }
    }

}
int main()
{
    pf("%d\n",M);
    sieve();
    cout<<c<<endl;
   // cout<<sizeof(flag)<<endl;

}
