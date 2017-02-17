/*
 * 11149 - Power of Matrix.cpp
 *
 *  Created on: Jun 24, 2014
 *      Author: Tahmid
 */

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
#define gcd(a,b) __gcd(a,b)l
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
/*--------------------------------------------------------------------------------------------------*/

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
ll bigmod(ll a, ll b, ll m)
{
    if (b == 0)
        return 1 % m;
    ll x = bigmod(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2 == 1)
        x = (x * a) % m;
    return x;
}
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
#define DIM 55
int mod = 10;
struct matrix
{
    int mat[DIM][DIM];
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
    int* operator [] (int i)
    {
        return mat[i];
    }
    matrix operator* (const matrix &b)
    {
        matrix res(row, b.col);
        REP(i, 0, res.row)
        REP(j, 0, res.col)
        {
            res[i][j] = 0;
            REP(k, 0, col)
            {
                res[i][j] = (res[i][j] + (mat[i][k] * b.mat[k][j])) % mod;
            }
        }
        return res;
    }

    matrix operator+(const matrix &b)
    {
        matrix res(row, col);
        REP(i, 0, row)
        REP(j, 0, col)
        res[i][j] = (mat[i][j] + b.mat[i][j]) % mod;
        return res;
    }
};
matrix mat[2][2];
matrix ret[2][2];
matrix unit;
matrix zero;
void setunit(int n)
{
    unit = matrix(n, n);
    REP(i, 0, n) unit[i][i] = 1;
}

void COPY(matrix A[2][2])
{
    REP(i, 0, 2)
    REP(j, 0, 2) ret[i][j] = A[i][j];
}

void multiply(matrix A[2][2], matrix B[2][2])
{
    matrix tmp[2][2];
    REP(i, 0, 2)
    REP(j, 0, 2)
    {
        tmp[i][j] = zero;
        REP(k, 0, 2) tmp[i][j] = tmp[i][j] + (A[i][k] * B[k][j]);
    }
    COPY(tmp);
}
string binary(ll p)
{
    string s = "";
    while(p > 0)
    {
        s += (p & 1) ? "1" : "0";
        p >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

void power(ll p)
{
    if(p == 0)
    {
        REP(i, 0, 2) REP(j, 0, 2) ret[i][j] = unit;
    }
    string bin = binary(p);
    COPY(mat);

    for(int i = 1; i < sz(bin); i++)
    {
        multiply(ret, ret);
        if(bin[i] == '1') multiply(ret, mat);
    }

}

int main()
{
    int n, k;
    while(sf("%d %d", &n, &k) == 2)
    {
        if(n == 0 ) return 0;
        matrix A(n, n);
        setunit(n);
        zero = matrix(n, n);

        REP(i, 0, n)
        REP(j, 0, n)
        {
            sf("%d", &A[i][j]);
            A[i][j] %= 10;
        }

        mat[0][0] = A;
        mat[0][1] = unit;
        mat[1][1] = unit;
        mat[1][0] = zero;
        power(k);
        matrix ans = (ret[0][1] * A);
        REP(i, 0, n)
        {
            REP(j, 0, n - 1) pf("%d ", ans[i][j] % 10);
            pf("%d", ans[i][n - 1] % 10);
            NL;
        }
        NL;
    }
    return 0;
}
