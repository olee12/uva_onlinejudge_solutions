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
#define NL pf("\n")
/*--------------------------------------------------------------------------------------------------*/
int MOD;
struct matrix
{
    ll v[16][16];

    int row;
    int col;
    matrix()
    {
        clr(v);
    }
};
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
            ll sum = 0;
            for (int k = 0; k < a.col;  k++)
            {
                sum += a.v[i][k] * b.v[k][j];
                sum %= MOD;
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

// returns mat^p
matrix power(matrix mat, int p)
{
    assert(p >= 1);
    if (p == 1) return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}
ll base[16];
int main()
{
    int n,m,d;
    int a,b,c;
    ll ans;
    while(sf("%d %d %d",&d,&n,&m))
    {
        if(d==0 && n==0 && m==0) return 0;
        ans =0;

        MOD = m;
        // cout<<MOD<<endl;
        matrix res;
        res.row = res.col = d;
        REP(i,0,d) sf("%lld",&res.v[0][i]);
        REP(i,0,d) sf("%lld",base+i);
        REP(i,1,d) res.v[i][i-1]=1;

        if(n<=d)
            pf("%lld\n",base[n-1]%MOD);
        else
        {
            res = power(res,n-d);
            int b = d-1;
            for(int i = 0; i<d; i++)
            {
                ans += res.v[0][i]*base[b--];
                ans%=MOD;
            }
            pf("%lld\n",ans);
        }
    }
    return 0;
}
