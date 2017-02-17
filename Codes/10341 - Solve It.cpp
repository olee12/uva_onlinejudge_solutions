#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 100099
double x,y,c;
const double next = 1e-10;
const double ext_pnt =  1e-12;
const double E = 2.718281828;
int q,p,r,s,t,u;
///   p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u = 0
double f(double x)
{
    return p*pow(E,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
double func(double x)
{
    return (x<0)?-x:x;
}
int main()
{
    double mid;
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6)
    {
        // cout<<p<<q<<r<<s<<t<<u<<endl;
        double hi = 1;
        double lo = 0;
        double res;
        if(f(1)*f(0)>0)
        {
            puts("No solution");
            continue;
        }
        if(f(1) < f(0))
        {
            hi = 0;
            lo = 1;
        }
        while(1)
        {
            mid = (lo+hi)/2.0;
            res = f(mid);
            // cout<<res<<endl;
            if(fabs(res)<ext_pnt) break;
            if(res < 0) lo = mid;
            else hi = mid;
            // cout<<lo<<' ' <<hi<<' '<<func(lo-hi)<<endl;
        }
        printf("%.4lf\n",(hi+lo)/2.00);
    }
    return 0;
}
