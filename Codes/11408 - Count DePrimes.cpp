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
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 5000005
#define sf scanf
#define pf printf
#define INF 2061109567
bool prime[M];
int DePrime[M];
int ara[M];
void sieve()
{
    int add;
    int sq = sqrt(5000005);
    for(int i = 4; i<M; i+=2) prime[i]=true;
    for(int i = 3; i<M; i+=2)
    {
        if(prime[i]==false)
        {
            if(sq>=i)
            {
                add = i*2;
                for(int j = i*i; j<M; j+=add) prime[j]=true;
            }
        }
    }
}
void func()
{
    int cnt = 0;
    for(int i = 2;i<M;i++)
    {
        if(prime[i]==false)
        {
            for(int j = i;j<M;j+=i) DePrime[j]+=i;
        }
    }

    for(int i = 2;i<M;i++)
    {
        if(prime[DePrime[i]]==false)
            DePrime[i]=++cnt;
        else DePrime[i]=cnt;
    }
}
int main()
{
    sieve();
    func();
   // for(int i=0;i<50;i++) pf("%d %d\n",i,prime[i]);
    int a,b;
    while(sf("%d",&a),a){
            sf("%d",&b);
        pf("%d\n",DePrime[b]-DePrime[a-1]);
    }
    return 0;
}
