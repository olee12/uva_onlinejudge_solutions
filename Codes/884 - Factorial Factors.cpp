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
bool flag[M];
int prime[M];
int c;
void sieve()
{
    prime[c++]=2;
    int sq = sqrt(1010);
    int i,j,add;
    for(i = 4; i<=1010; i+=2) flag[i]=true;
    for(i =3; i<1010; i+=2)
    {
        if(flag[i]==false)
        {
            prime[c++]=i;
            if(sq>=i)
            {
                add=i*2;
                for(j= i*i; j<1010; j+=add) flag[j]=true;
            }
        }
    }
}
int ara[M];
int save[M];
int main()
{
    sieve();
    //  for(int i = 0; i<25; i++) cout<<prime[i]<<endl;
    int num,n,tmp;
    int cnt;
    for(int i = 2; i<M; i++)
    {
        n = i;
        tmp = sqrt(n);
        cnt=0;
        for(int j =0; prime[j]<=tmp; j++)
        {
            if(n%prime[j]==0)
            {
                while(n%prime[j]==0)
                {
                    n/=prime[j];
                    cnt++;
                }
                tmp = sqrt(n);
            }
        }
        if(n>1) cnt++;
        ara[i]=cnt;
    }
    save[2]=ara[2];
    for(int i = 3;i<M;i++) save[i]=save[i-1]+ara[i];
    while(sf("%d",&n)==1)
    {
        cnt = 0;
        pf("%d\n",save[n]);
    }
    return 0;
}
