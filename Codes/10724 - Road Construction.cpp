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
#define INF 1e9
int x[M];
int y[M];
double graph[M][M];
inline double disten(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void apsp(int n)
{
    for(int k=1; k<=n; k++)
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
}
void init(int n)
{
    for(int i = 0; i<=n+2; i++)
        for(int j = 0; j<=n+2; j++)
            if(i!=j) graph[i][j]=INF;
            else graph[i][j]=0;
}
int main()
{
    int n,m;
    int u,v;
    int au,av;
    double best,cost,mn,u_dis_v;
    while(sf("%d %d",&n,&m),(n|m))
    {
        best = -1;
        init(n);
        for(int i= 1; i<=n; i++)
        {
            sf("%d %d",x+i,y+i);
        }
        for(int i = 0; i<m; i++)
        {
            sf("%d %d",&u,&v);
            graph[u][v]=graph[v][u]=disten(x[u],y[u],x[v],y[v]);
           // cout<<graph[u][v]<<endl;
        }
        apsp(n);
        for(u = 1; u<=n; u++)
            for(v = u+1; v<=n; v++)
            {
                cost=0;
                u_dis_v = disten(x[u],y[u],x[v],y[v]);
                for(int i = 1; i<=n; i++)
                    for(int j = i+1; j<=n; j++)
                        cost+= graph[i][j] - min(graph[i][j],min(graph[i][v]+u_dis_v+graph[u][j],graph[i][u]+u_dis_v+graph[v][j]));

                if(cost>best)
                {
                   // cout<<cost<<' '<<u<<' '<<v<<endl;
                    best = cost;
                    au = u;
                    av = v;
                    mn = u_dis_v;

                }
                else if(cost==best && u_dis_v<mn)
                {
                    best = cost;
                    au = u;
                    av = v;
                    mn = u_dis_v;
                }
            }
        if(best>1.0) pf("%d %d\n",au,av);
        else pf("No road required\n");
    }
    return 0;
}
