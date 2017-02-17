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
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

//#include<conio.h>
//#define wait getch()
ll mod =  1000000007;
struct matrix
{
    ll mat[50][50];
    int row,col;
    matrix(int r = 0,int c = 0)
    {
        clr(mat);
        row = r;
        col = c;
    }
    ll* operator[] (int i)
    {
        return mat[i];
    }



};

matrix multiply(matrix &a, matrix &b)
{
    matrix res(a.row, b.col);
    REP(i, 0, res.row)
    REP(j, 0, res.col)
    {
        ll sum = 0;
        REP(k, 0, a.col)
        {
            sum += (a[i][k] * b[k][j]);
            sum %= mod;
        }
        res[i][j] = sum;
    }
    return res;
}
string binary(ll p)
{
    string ret = "";
    while (p > 0)
    {
        ret += (p & 1) ? "1" : "0";
        p >>= 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

matrix power( matrix mat,ll p)
{
    if(p==1) return mat;
    string bin = binary(p);
    matrix r,r2;
    matrix ret = mat;
    for (int i = 1; i < bin.size(); i++)
    {
        ret = multiply(ret, ret);
        if (bin[i] == '1')

            ret =  multiply(ret,mat);


    }
    return ret;
}

struct cell
{
    int ara[4];
    cell()
    {
        clr(ara);
    }
    int& operator [] (int i)
    {
        return ara[i];
    }
};

matrix graph;
vector<cell> valid;
int diagonal[2]= {1,-1};

bool is_ok(int p , int q)
{
    int flag[4];
    clr(flag);
    int ok;
    for(int i = 0;i<4;i++)
    {
          ok = 0;
        for(int j = 0;j<4;j++)
        {
            if( flag[j]==0 && abs(valid[p][i]-valid[q][j]) == 1)
            {
                flag[j]=1;
                ok = 1;
                break;
            }

        }
        if(ok==0) return false;
    }
    return true;

}

void get_graph( )
{
    graph = matrix(35,35);
    cell tmp;
    for(int i = 0; i<7; i++)
        for(int j = i + 1; j<7; j++)
            for(int k = j+1; k<7; k++)
                for(int l = k + 1; l < 7; l++)
                {
                    tmp[0] = i;
                    tmp[1] = j;
                    tmp[2] = k;
                    tmp[3] = l;
                    valid.pb(tmp);
                }
   // deb(sz(valid));

    for(int i = 0;i<sz(valid);i++)
    {
        for(int j = 0;j<sz(valid);j++)
        {
            if(is_ok(i,j))
            {
                graph[i][j]=1;

            }
        }
    }
}
int find_pos(cell &tmp)
{
    for(int i = 0;i<sz(valid);i++)
    {
        int j = 0;
        for(j;j<4;j++)
        {
            if(valid[i][j]!=tmp[j]) break;
        }
        if(j==4) return i;
    }
}
int main()
{
    get_graph();

    int test;
    int a,n;
    int cas = 1;
    sf1(test);
    while(test--)
    {
        cell tmp;
        int cnt = 0;
        sf1(n);
        for(int i = 0;i<7;i++)
        {
            sf1(a);
            if(a) tmp[cnt++]=i;
        }
        int now = find_pos(tmp);
     //   csprnt;
        if(n==1) pf("1\n");
        else
        {
            int ans = 0;
            matrix res = power(graph,n-1);
            for(int  i = 0;i<35;i++) ans = (ans + (res[now][i])) % mod;
            pf("%d\n",ans);
        }



    }
}

