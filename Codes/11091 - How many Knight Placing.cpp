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

#define oo (1<<30)
//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//int x[] = {0,0,-1,1};//4-way
//int y[] = {-1,1,0,0};//4-way
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
//#define wait getcho()
int mod = 10007;
class matrix
{
public:
    int mat[100][100];
    int row,col;
    matrix(int r = 0,int c = 0)
    {
        clr(mat);
        row = r;
        col = c;
    }
    int* operator[] (int i)
    {
        return mat[i];

    }

    matrix operator * (const matrix &b)
    {
        matrix res = matrix(row,b.col);

        REP(i,0,res.row)
        REP(j,0,res.col)
        {
            res[i][j] = 0;
            REP(k,0,col)
            {
                res[i][j]+=mat[i][k]*b.mat[k][j];
                res[i][j]%=mod;
            }
        }
        return res;
    }

};


struct point
{
    int x,y;
};

point ara[100];

int valid(int x,int y)
{
    if((x<<2)&y || (y<<2)&x) return 0;
    return 1;
}

int ok(int x,int y,int z)
{
    if(!valid(x,y) || !valid(y,z)) return 0;
    if((x<<1)&z || (z<<1)&x) return 0;
    return 1;
}

matrix graph;

vi vld;

int build()
{
    int control = (1<<6)-1;
    int n = 0;
    while(control--)
    {
        if(popc(control)==2) vld.pb(control);

    }
    // deb(sz(vld));

    for(int i = 0; i<15; i++)
        for(int j = 0; j<15; j++) if(valid(vld[i],vld[j]))
            {
                ara[n].x=vld[i];
                ara[n].y=vld[j];
                n++;
            }

    graph = matrix(n,n);
    int cnt = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            if(ara[i].y==ara[j].x)
            {
                if(ok(ara[i].x,ara[i].y,ara[j].y)) graph[i][j] = 1,cnt++;
            }
    // deb(cnt);
}

string binary(int p)
{
    string s = "";

    while(p>0){
        s+=(p&1)?"1":"0";
        p>>=1;
    }
    reverse(s.begin(),s.end());
    return s;
}

matrix power(matrix mat,int p)
{
    if(p==1) return mat;

    matrix ret = mat;

    string bin = binary(p);
//deb("olee");
    for(int i = 1;i<sz(bin);i++)
    {
        ret = ret*ret;
        if(bin[i]=='1') ret = ret*mat;
    }

    return ret;
}




int main()
{
    build();
    int test;
    int n,ans;
    matrix res;
    sf1(test);

    while(test--)
    {
        sf1(n);
        if(n==1) puts("15");
        else if(n==2) puts("69");
        else{
            ans = 0;
            res = power(graph,n-2);
            for(int i = 0;i<69;i++) {for(int j=0;j<69;j++) {
                ans+=res[i][j];
                //pf("%2d",res[i][j]);
                ans%=mod;
            }
           // puts("");
            }
            pf("%d\n",ans);
        }

    }
    return 0;
}
