//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
//#include <bits/stdc++.h>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define csprnt printf("Case %d: ", cas++);
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define popc(i) (__builtin_popcount(i))
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define sz(a) (int)a.size()
#define sf scanf
#define pf printf
#define NL pf("\n")
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d", &a,&b, &c)
/*--------------------------------------------------------------------------------------------------*/
#define MOD 1000000007
#define M 16050
#define oo (1<<30)
//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

template<class T1> void deb(T1 e)
{
    cout << e << endl;
}
template<class T1, class T2> void deb(T1 e1, T2 e2)
{
    cout << e1 << " " << e2 << endl;
}
template<class T1, class T2, class T3> void deb(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << " " << e2 << " " << e3 << endl;
}
template<class T1, class T2, class T3, class T4> void deb(T1 e1, T2 e2, T3 e3,
        T4 e4)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template<class T1, class T2, class T3, class T4, class T5> void deb(T1 e1,
        T2 e2, T3 e3, T4 e4, T5 e5)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template<class T1, class T2, class T3, class T4, class T5, class T6> void deb(
    T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6)
{
    cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
         << endl;
}
template<typename T> inline T sqr(T n)
{
    return n * n;
}
inline double hypot(double x, double y)
{
    return sqrt(sqr(x) + sqr(y));
}
template<typename T> inline T pmod(T n, T m)
{
    return ((n % m) + m) % m;
}
template<typename T> T power(T n, int p)
{
    return (p == 0) ?
           (T) (1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1));
}
template<typename T> T bigmod(T n, int p, T m)
{
    return (p == 0) ?
           (T) (1) :
           ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m;
}
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

//#include<conio.h>
//#define wait getch()
vector<int> graph[1005];
vector<int> rrr[1005];
int vis[1005];
int flag = 0;
int outdeg[1005];
map<ii,bool> same;

int cycle;

void dfs_visit(int u)
{
    if(vis[u]==2) return;

    if(vis[u]==1)
    {
        cycle = 1;
        return ;
    }
    vis[u]=1;
    for(int i = 0; i<sz(graph[u]); i++)
    {
        int v = graph[u][i];
        dfs_visit(v);
    }
    vis[u]=2;
}
stack<int> st;
void dfs(int u,int id)
{
    if(vis[u]==id) return;
    if(vis[u] && vis[u]!=id)
    {
        flag = 1;
        return ;
    }
    if(vis[u]==0) vis[u]=id;
    for(int i = 0; i<sz(rrr[u]); i++)
    {
        int v = rrr[u][i];
        dfs(v,id);
    }
    //st.push(u);

}

int main()
{
    int u,v,w,n,m,out;
    while(sf2(n,m) , (n|m))
    {
        flag = 0;
        same.clear();
        clr(vis);
        clr(outdeg);
        cycle = 0;
        out = 0;

        REPE(i,0,1000) graph[i].clear(),rrr[i].clear();

        REP(i,0,m)
        {
            sf2(u,v);
            // flag[u]=1;
            //flag[v]=1;

            if(same.find(mp(u,v))==same.end())
            {
                graph[u].pb(v);
                rrr[v].pb(u);
                same[mp(u,v)]=true;
                outdeg[u]++;

            }
        }
        for(int i = 0; i<n; i++)
        {
            if(outdeg[i]==0) out++;
            if(vis[i]==0) dfs_visit(i);
        }
        //  deb("cycle : ",cycle);
        if(cycle)
        {
            pf("0\n");
        }
        else
        {
            int id = 1;
            clr(vis);
            flag = 0;
            REP(i,0,n) if(outdeg[i]==0 && !flag) dfs(i,id++);

            pf("%d\n",!flag);

            /* int comp = 0;
             clr(vis);
             while(st.empty()==0)
             {
                 u = st.top();
                 st.pop();
                 if(vis[u]==0)
                 {
                     comp++;
                     dfs(u);
                 }
             }
            // deb(comp,out);
             if(out==comp) pf("1\n");
             else pf("0\n");*/
        }

    }
    return 0;
}

