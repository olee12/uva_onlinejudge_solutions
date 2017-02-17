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
#define M 105
#define sf scanf
#define pf printf
#define INF 2147483645
double graph[M][M];
struct point
{
    int x,y;
};
point ara[105];

inline double Q_dis(int x1,int y1,int x2,int y2)
{
    return sqrt((double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}
int main()
{
    int test;
    int n;
    sf("%d",&test);
    for(int cas = 1; cas<=test; cas++)
    {

        sf("%d",&n);
        for(int i = 1; i<=n; i++)
            sf("%d %d",&ara[i].x,&ara[i].y);
        for(int i = 1; i<=n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                double dis = Q_dis(ara[i].x,ara[i].y,ara[j].x,ara[j].y);
                if(dis>10) dis = INF;
                graph[i][j]= dis;
                graph[j][i]= dis;
            }
            graph[i][i]=0.0;
        }
        pf("Case #%d:\n",cas);
        for(int k = 1; k<=n; k++)
            for(int i = 1; i<=n; i++)
                for(int j = 1; j<=n; j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
        int xx = 1;
        bool f = 0;
        double ans=0;
        for(int i = 2; i<=n; i++)
        {
            for(int j = 1; j<=xx; j++)
            {
                if(graph[i][j]==INF)
                {
                    f = true;
                    break;
                }
                else if(graph[i][j]>ans) ans = graph[i][j];
            }
            if(f) break;
            xx++;
        }
        if(f) puts("Send Kurdy");
        else pf("%.04lf\n",ans);
        puts("");
    }
    return 0;
}
