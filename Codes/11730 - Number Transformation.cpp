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
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
#define M 1010
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define fr first
#define sc second
int prime[M];
vi graph[M];
bool flag[M];
int c;
vi factors[M];
void sieve()
{

    register int i,j,add;
    prime[c++] = 2;

    for(i = 4; i<M; i+=2) flag[i] = true;
    for(i = 3; i<M; i+=2)
    {
        if(flag[i]==false)
        {
            prime[c++]=i;
            if(M/i>=i)
            {
                add = i*2;
                for(j = i*i; j<M; j+=add) flag[j] = true;
            }
        }
    }
   // cout<<"\nsdfasf";


}
void redy()
{
    for(int i = 1; i<M; i++)
    {
        int ind = 0;
        int num = i;
        factors[i].clear();
        int sq = sqrt(num);
        for(int j = 0; prime[j]<=sq+2; j++)
        {
            if(num % prime[j] == 0)
            {
                factors[i].pb(prime[j]);
                while(num % prime[j] == 0)
                    num/=prime[j];
            }

        }
        if(num>1) factors[i].pb(num);
    }
}
int bfs(int start,int to)
{
    queue<ii> Q;
    Q.push(mp(start,0));
    bool taken[M];
    memset(taken,false,sizeof taken);
    while(Q.empty()==false)
    {
        ii p = Q.front();
        Q.pop();
        if(p.fr==to) return p.sc;
        if(taken[p.fr]) continue;
        taken[p.fr] = true;
        VII it = factors[p.fr].begin();
        for(;it!=factors[p.fr].end();it++)
        {
            int sum = *it + p.fr;
            if(sum<=to && *it != p.fr) {
                Q.push(mp(sum,p.sc+1));
            }
        }

    }
    return -1;

}
int main()
{
   //// cout<<"adf";
    sieve();

    redy();

    int s,t;
    int cas = 1;
    while(scanf("%d %d",&s,&t))
    {
        if(s==0 && t==0) break;
        printf("Case %d: %d\n",cas++,bfs(s,t));
    }
    return 0;
}













