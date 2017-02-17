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
int MOD;
struct matrix
{
    ll v[5][5];
    int row, col;
};
matrix multiply(matrix a,matrix b)
{

    //assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    REP(i,0,r.row)
    REP(j,0,r.col)
    {
        ll sum = 0;
        REP(k,0,a.col)
        {
            sum+= (a.v[i][k] * b.v[k][j]);
            sum%=MOD;
        }
        r.v[i][j]=sum;
    }
    return r;
}

matrix power(matrix mat,int p)
{
    if(p==1) return mat;
    if(p%2) return multiply(mat,power(mat,p-1));
    matrix ret = power(mat,p/2);
    return multiply(ret,ret);
}

int main()
{
    int n,m;

    while(sf("%d %d",&n,&m)==2)
    {
        matrix res;
        res.row = 2;
        res.col = 2;
        MOD = 1<<m;
        res.v[0][0]=res.v[0][1]=res.v[1][0]=1;
        res.v[1][1]=0;
        if(n<3)
        {
            if(n==0) pf("0\n");
            if(n==1) pf("1\n");
            if(n==2) pf("1\n");
        }
        else
        {
            res = power(res,n-1);
            ll ans = res.v[0][0];
            pf("%lld\n",ans%MOD);
        }
    }
    return 0;
}
