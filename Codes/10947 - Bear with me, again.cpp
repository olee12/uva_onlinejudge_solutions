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
#include<sstream>
#include<stack>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 105
#define sf scanf
#define pf printf
#define INF 2061109567
struct point
{
    double x,y,r;

};
point ara[M];
double graph[M][M];
inline double disten(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
    int k,m;
    double mx_dist;
    int n;
    while(sf("%d %d",&k,&m)==2)
    {
        mx_dist=double(k*m);
        sf("%lf %lf %lf",&ara[1].x,&ara[1].y,&ara[1].r);
        sf("%lf %lf %lf",&ara[2].x,&ara[2].y,&ara[2].r);
        sf("%d",&n);
        n+=2;
           for(int i = 3; i<=n; i++) sf("%lf %lf %lf",&ara[i].x,&ara[i].y,&ara[i].r);
        for(int i =1; i<=n; i++)
            for(int j = i+1; j<=n; j++)
            {
                double dis = disten(ara[i].x,ara[i].y,ara[j].x,ara[j].y);
                if(dis<=ara[i].r+ara[j].r) dis=0;
                else dis = dis - ara[i].r-ara[j].r;
                if(dis>mx_dist) dis =(double) INF;
                graph[i][j]=dis;
                graph[j][i]=dis;
            }
            for(int k = 1;k<=n;k++)
                for(int i = 1;i<=n;i++)
                for(int j = 1;j<=n;j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            if(graph[1][2]!=INF) puts("Larry and Ryan will escape!");
            else puts("Larry and Ryan will be eaten to death.");
    }
    return 0;
}
