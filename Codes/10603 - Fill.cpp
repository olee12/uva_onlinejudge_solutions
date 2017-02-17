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
#define M 205
#define sf scanf
#define pf printf
#define INF 100000
#define mp make_pair
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
int graph[M];
struct jug
{
    int a,b,c;
};
struct node
{
    jug u;
    int w;
    node() {}
    node(jug _u,int _w):u(_u),w(_w) { }
    bool operator < (const node& p) const
    {
        return p.w < w;
    }
};
int dist[M][M][M];
void init()
{
    int i,j,k;
    REP(i,M) REP(j,M) REP(k,M) dist[i][j][k]=INF;
}
jug sol;
int close = -1;
int N;
void cheak(jug& v);
int main()
{
    int test;
    jug inp,u,v;

    sf("%d",&test);
    while(test--)
    {
        sf("%d %d %d %d",&inp.a,&inp.b,&inp.c,&N);
        init();
        // cout<<"sdfaddf";
        priority_queue<node> Q;
        u.a = 0;
        u.b = 0;
        u.c = inp.c;
        Q.push(node(u,0));
        dist[u.a][u.b][u.c]=0;
        int cst = 0;
        bool res = 0;
        close = 0;
        while(Q.empty()==false)
        {
            u =  Q.top().u;
            Q.pop();
           // pf("%d %d %d\n",u.a,u.b,u.c);
            ///c to a
            //cout<<"asfas";
            if(u.a==N || u.b==N|| u.c==N)
            {
                res = 1;
              //  cout<<"in : ";
                cout<<dist[u.a][u.b][u.c]<<' '<<N<<endl;
                break;
            }

            /// c to a;
            /// hello world
            if((u.a + u.c) >= inp.a)
            {
                v.c = u.c - abs(inp.a - u.a);

                v.a = inp.a;
                cst = inp.a - u.a;
            }
            else
            {
                v.a = u.a+u.c;
                cst = u.c;
                v.c = 0;
            }
            v.b = u.b;

            if(dist[v.a][v.b][v.c] > dist[u.a][u.b][u.c] + cst )
            {
                dist[v.a][v.b][v.c] = dist[u.a][u.b][u.c] + cst;
                Q.push(node(v,dist[v.a][v.b][v.c]));
                cheak(v);
            }


           // cout<<v.a<<' '<<v.b<<' '<<v.c<<' '<<dist[v.a][v.b][v.c]<<endl;

            // cout<<"daf";
            ///c to b
            if((u.b + u.c) >= inp.b)
            {
                v.c = u.c - abs(inp.b - u.b);

                v.b = inp.b;
                cst = inp.b - u.b;
            }
            else
            {
                v.b = u.b+u.c;
                cst = u.c;
                v.c = 0;
            }
            v.a =u.a;
            if(dist[v.a][v.b][v.c] > dist[u.a][u.b][u.c] + cst )
            {
                dist[v.a][v.b][v.c] = dist[u.a][u.b][u.c] + cst;
                Q.push(node(v,dist[v.a][v.b][v.c]));
                cheak(v);
            }
           // cout<<v.a<<' '<<v.b<<' '<<v.c<<' '<<dist[v.a][v.b][v.c]<<endl;
            ///b to c
            if((u.b + u.c) >= inp.c)
            {
                v.b = u.b - abs(inp.c - u.c);

                v.c = inp.c;
                cst = inp.c - u.c;
            }
            else
            {
                v.c = u.b+u.c;
                cst = u.b;
                v.b = 0;
            }
            v.a = u.a;
            if(dist[v.a][v.b][v.c] > dist[u.a][u.b][u.c] + cst )
            {
                dist[v.a][v.b][v.c] = dist[u.a][u.b][u.c] + cst;
                Q.push(node(v,dist[v.a][v.b][v.c]));
                cheak(v);
            }
           // cout<<v.a<<' '<<v.b<<' '<<v.c<<' '<<dist[v.a][v.b][v.c]<<endl;
            ///b to a
            if((u.b + u.a) >= inp.a)
            {
                v.b = u.b - abs(inp.a - u.a);

                v.a = inp.a;
                cst = inp.a - u.a;
            }
            else
            {
                v.a = u.b+u.a;
                cst = u.b;
                v.b = 0;
            }
            v.c = u.c;
            if(dist[v.a][v.b][v.c] > dist[u.a][u.b][u.c] + cst )
            {
                dist[v.a][v.b][v.c] = dist[u.a][u.b][u.c] + cst;
                Q.push(node(v,dist[v.a][v.b][v.c]));
                cheak(v);
            }
          //  cout<<v.a<<' '<<v.b<<' '<<v.c<<' '<<dist[v.a][v.b][v.c]<<endl;
            ///a to c

            if((u.a + u.c) >= inp.c)
            {
                v.a = u.a - abs(inp.c - u.c);

                v.c = inp.c;
                cst = inp.c - u.c;
            }
            else
            {
                v.c = u.a+u.c;
                cst = u.a;
                v.a = 0;
            }
            v.b = u.b;
            if(dist[v.a][v.b][v.c] > dist[u.a][u.b][u.c] + cst )
            {
                dist[v.a][v.b][v.c] = dist[u.a][u.b][u.c] + cst;
                Q.push(node(v,dist[v.a][v.b][v.c]));
                cheak(v);
            }
          //  cout<<v.a<<' '<<v.b<<' '<<v.c<<' '<<dist[v.a][v.b][v.c]<<endl;
            ///a to b
            if((u.a + u.b) >= inp.b)
            {
                v.a = u.a - abs(inp.b - u.b);

                v.b = inp.b;
                cst = inp.b - u.b;
            }
            else
            {
                v.b = u.a+u.b;
                cst = u.a;
                v.a = 0;
            }
            v.c = u.c;
            if(dist[v.a][v.b][v.c] > dist[u.a][u.b][u.c] + cst )
            {
                dist[v.a][v.b][v.c] = dist[u.a][u.b][u.c] + cst;
                Q.push(node(v,dist[v.a][v.b][v.c]));
                cheak(v);
            }
          //  cout<<v.a<<' '<<v.b<<' '<<v.c<<' '<<dist[v.a][v.b][v.c]<<endl;
        }
        if(res == 0)
            if(close==0) puts("0 0");
            else pf("%d %d",dist[sol.a][sol.b][sol.c],close);
    }

    return 0;

}
void cheak(jug& v)
{
    if(v.a>close && v.a < N)
    {
        close = v.a;
        sol.a = v.a;
        sol.b = v.b;
        sol.c = v.c;
    }
    if(v.b>close && v.b < N)
    {
        close = v.b;
        sol.a = v.a;
        sol.b = v.b;
        sol.c = v.c;
    }
    if(v.c>close && v.c < N)
    {
        close = v.c;
        sol.a = v.a;
        sol.b = v.b;
        sol.c = v.c;
    }
}
