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
#include<stack>
#include<sstream>
#include<cctype>
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
#define M 1005
#define sf scanf
#define pf printf
struct point
{
    double x,y;
};
point ara[M];
inline double func(double& x1,double& y1,double& x2,double& y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
    int n;
    double gx,gy,dx,dy;
    while(sf("%d %lf %lf %lf %lf",&n,&gx,&gy,&dx,&dy)==5)
    {
        double dis_g,dis_d;
        bool f = 1;
        for(int i = 0; i<n; i++)
        {
            sf("%lf %lf",&ara[i].x,&ara[i].y);
        }
        for(int i = 0; i<n; i++)
        {
            dis_d = func(dx,dy,ara[i].x,ara[i].y);
            dis_g = func(gx,gy,ara[i].x,ara[i].y);
           // pf("%lf %lf\n",dis_d,dis_g);
            if(dis_d >= dis_g*2)
            {
                pf("The gopher can escape through the hole at (%.03lf,%.03lf).\n",ara[i].x,ara[i].y);
                f = false;
                break;
            }

        }
         if(f) puts("The gopher cannot escape.");

    }
    return 0;
}
