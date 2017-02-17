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
#define LB  lower_bound
#define UB  upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define sz(a) (int)a.size()
#define sf scanf
#define pf printf
#define NL pf("\n")
/*--------------------------------------------------------------------------------------------------*/

int MOD ;

struct matrix
{
    ll v[27][27];
    int row , col;
    matrix()
    {
        clr(v);
    }
};
ll mod(ll a,ll m)
{
    if(a>0) return a%m;
    if(a==0) return 0;
    a=a*-1;
    ll M=a%m;
    if(M==0) return 0;
    return m-M;
}
matrix multiply(matrix a, matrix b)
{
    assert(a.col == b.row);

    matrix r;
    r.row = a.row;
    r.col = b.col;
    REP(i,0,r.row)
    REP(j,0,r.col)
    {
        ll sum = 0;
        REP(k,0,a.col)
        {
            sum += mod(a.v[i][k],MOD)*mod(b.v[k][j],MOD);
            sum  = mod(sum,MOD);
        }
        r.v[i][j]=sum;
    }
    return r;
}

matrix power(matrix mat,int p)
{
    assert(p>=1);
    if(p==1) return mat;
    if(p&1) return multiply(mat,power(mat,p-1));
    matrix ret = power(mat,p/2);
    return multiply(ret,ret);
}
ll base[27];

ll c;
int main()
{
    int test;
    int k,n,m;
    sf("%d",&test);
    while(test--)
    {
        /// M * A = B
        sf("%d %d %d",&k,&m,&n);
        MOD = m;
        matrix res;
        res.col = res.row = k+1;
        ///first row of M;
        REP(i,0,k) sf("%lld",&res.v[0][i]);
        sf("%lld",&c);
        res.v[0][k]=1;

        REP(i,0,k) sf("%lld",base+i);

        ///rest of row of M
        REP(i,1,k) res.v[i][i-1]=1;
        res.v[k][k]=1;


        ll ans = 0;
        if(n<=k)
        {
            if(n<k) pf("%lld\n", mod(base[n],MOD));
            else
            {
                int a = k-1;
                REP(i,0,k)
                {
                    ans += mod(base[a--],MOD)*mod(res.v[0][i],MOD);
                    ans = mod(ans,MOD);
                }
                ans+= mod(c,MOD);
                ans%=MOD;
                pf("%lld\n",ans);
            }
        }
        else
        {
            res = power(res,n - (k-1));
            int b = k-1;
            REP(i,0,k)
            {
                ans+= (mod(res.v[0][i],MOD) * mod(base[b--],MOD))%MOD;
                ans %= MOD;
            }
            ans += mod(res.v[0][k],MOD)*mod(c,MOD);
            ans%=MOD;
            pf("%lld\n",ans);
        }
        if(test) NL;

    }
    return 0;
}
