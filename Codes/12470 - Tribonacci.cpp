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
typedef vector<ii> vii;
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
#define NL pf("\n")
#define sf1(a) scanf("%d",&a)
/*--------------------------------------------------------------------------------------------------*/
#define MOD 1000007
#define M 100099

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
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

//#include<conio.h>
//#define wait getch()
ll mod = 1000000009;
#define DIM 5
struct matrix
{
    ll mat[DIM][DIM];
    int row, col;

    void clear()
    {
        clr(mat);
    }

    matrix(int r = 0, int c = 0)
    {

        row = r;
        col = c;
        clear();
    }
    ll* operator [](int i)
    {
        return mat[i];
    }

    matrix operator* (const matrix& b)
    {
        matrix res(3, 3);
        ll sum;
        REP(i, 0, res.row)
        REP(j, 0, res.col)
        {
            sum = 0;
            REP(k, 0, col)
            {
                sum += (mat[i][k] * b.mat[k][j]) % mod;
                sum %= mod;
            }
            res[i][j] = sum;
        }

        return res;
    }
};
matrix mat;
string binary(ll p)
{
    string s = "";
    while(p > 0)
    {
        s += (p & 1ll) ? "1" : "0";
        p >>= 1ll;
    }
    reverse(s.begin(), s.end());
    return s;
}


matrix power(ll p)
{
    if(p == 1) return mat;
    matrix res;
    res = mat;
    string bin = binary(p);
    for(int i = 1; i < sz(bin); i++)
    {
        res = res * res;
        if(bin[i] == '1') res = res * mat;
    }
    return res;
}

int main()
{
    ll n;
    while(sf("%lld", &n), n)
    {
        //cout<<n<<endl;
        mat = matrix(3, 3);
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[0][2] = 1;
        mat[1][0] = 1;
        mat[2][1] = 1;
        if(n <= 3)
        {
            if(n==1) pf("0\n");
            if(n==2) pf("1\n");
            if(n==3) pf("2\n");

        }
        else
        {
            matrix res = power(n - 3);
            ll ans = 0;
            ans += (res[0][1]);
            ans += (res[0][0] * 2) % mod;
            ans%=mod;
            pf("%lld\n",ans);
        }
    }
    return 0;
}
