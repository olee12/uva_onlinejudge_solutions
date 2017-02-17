#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
typedef long long ll;

void RD(int &x)
{
    scanf("%d",&x);
}
void RD(ll &x)
{
    scanf("%I64d",&x);
}
void RD(double &x)
{
    scanf("%lf",&x);
}
void RD(int &x,int &y)
{
    scanf("d",&x,&y);
}
void RD(ll &x,ll &y)
{
    scanf("I64d",&x,&y);
}
void RD(double &x,double &y)
{
    scanf("lf",&x,&y);
}
void RD(char *s)
{
    scanf("%s",s);
}
void RD(char &s)
{
    scanf("%c",&s);
}
void RD(string &s)
{
    cin>>s;
}

void PR(int x)
{
    printf("%d\n",x);
}
void PR(int x,int y)
{
    printf("%d %d\n",x,y);
}
void PR(ll x)
{
    printf("%I64d\n",x);
}
void PR(char x)
{
    printf("%c\n",x);
}
void PR(char *x)
{
    printf("%s\n",x);
}
void PR(string x)
{
    cout<<x<<endl;
}

#define clr(a) (a.clear())

#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 250
#define sf scanf
#define pf printf
#define INF 2147483645

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
typedef pair<ll , ll> pll;


#define SZ 100010
struct node
{
    int u,w;
    node() {}
    node(int _u,int _w):u(_u),w(_w) {}
    bool operator < (const node& p) const
    {
        p.w<w;
    }
};
int dist[M];
int main()
{
#ifdef OLEE
// freopen("1.txt", "r", stdin);
// freopen("2.txt", "w", stdout);
#endif
    int n,s,t;
    int ara[M];
    while(sf("%d",&n),n)
    {

        sf("%d %d",&s,&t);
        for(int i=1 ; i<=n; i++) sf("%d",ara+i);
        priority_queue<node> Q;
        for(int i = 0; i<n+5; i++) dist[i]=INF;
        dist[s]=0;
        Q.push(node(s,0));
        int u,v,cst ;
        while(!Q.empty())
        {
            u = Q.top().u;
            Q.pop();
            //cout<<u-ara[u]<<endl;
            if( u - ara[u] >=1 )
            {
                v = u - ara[u];
                if(dist[v]>dist[u]+1)
                {
                    dist[v]=dist[u]+1;
                    Q.push(node(v,dist[v]));
                    // cout<<u<<' '<<v<<' '<<dist[v]<<endl;
                }
            }
            if(u + ara[u] <=n)
            {
                v = u+ara[u];
                if(dist[v]> dist[u]+1)
                {
                    dist[v]=dist[u]+1;
                    Q.push(node(v,dist[v]));
                    //  cout<<u<<' '<<v<<' '<<dist[v]<<endl;
                }
            }
        }
        if(dist[t]!=INF)
            pf("%d\n",dist[t]);
        else puts("-1");
    }
    return 0;
}
