//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
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
#include <bits/stdc++.h>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, ll> ii;
typedef vector<int> vi;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
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
/*--------------------------------------------------------------------------------------------------*/


//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//int x[] = {0,0,-1,1};//4-way
//int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
int MOD;
struct matrix
{
    int v[5][5];
    int row ,  col;
};

matrix multipli(matrix a,matrix b)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;
    // cout<<"hello\n";
    REP(i,0,r.row)
    {
        REP(j,0,r.col)
        {
            int sum = 0;
            REP(k,0,a.col)
            {
                sum+= a.v[i][k] * b.v[k][j];
                sum%=MOD;
            }
            r.v[i][j]=sum;
        }
    }
    return r;

}

matrix multiply(matrix a, matrix b)
{
    assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for (int i = 0; i < r.row; i++)
    {
        for (int j = 0; j < r.col; j++)
        {
            int sum = 0;
            for (int k = 0; k < a.col;  k++)
            {
                sum += a.v[i][k] * b.v[k][j];
                sum %=MOD;
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

matrix power(matrix mat,int p)
{
    // pf("%d\n",p);

    if(p==1) return mat;
    if(p%2) return multipli(mat,power(mat,p-1));
    matrix ret = power(mat,p/2);
    return multipli(ret,ret);
}

int main()
{
    int test;
    int a,b,n,m;
    sf("%d",&test);
    while(test--)
    {
        matrix res;
        res.row = 2;
        res.col = 2;
        res.v[0][0]=res.v[0][1]=res.v[1][0]=1;
        res.v[1][1]=0;
        sf("%d %d %d %d",&a,&b,&n,&m);
        MOD = 1;
        REP(i,0,m) MOD*=10;
        if(n<3)
        {
            if(n==0) pf("%d\n",a);
            if(n==1) pf("%d\n",b);
            if(n==3) pf("%d\n",(a+b)%MOD);
        }
        else
        {
            res = power(res,n-1);
            int ans = res.v[0][0]*b + res.v[0][1]*a;
            ans%=MOD;
            pf("%d\n",ans);
        }

    }
    return 0;
}
