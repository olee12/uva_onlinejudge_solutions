#include<iostream>
#include<cstdio>
#include<cstring>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cctype>
using namespace std;
typedef vector<int> vi;
typedef pair<int,double> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
#define M 205
#define pb push_back
#define mp make_pair
#define INF (1<<31)-1
struct point
{
    double x,y;
};
point ara[250];
inline double sqrr(double a)
{
    return a*a;
}
double len(double ax, double ay, double bx, double by)
{
    return sqrt(sqrr(ax-bx) + sqrr(ay-by))*60/10000;
}
bool visited[M];
double dist[M];
struct node
{
    int u;
    double w;
    node() {}
    node(int i,double j): u(i),w(j) {}
    bool operator < (const node& p) const
    {
        return w>p.w;
    }
};
int main()
{
    //freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    char inp[5000];
    getchar();
    getchar();
    bool f = 0;
    while(test--)
    {
        vii graph[M];
        if(f) puts("");
        f=true;
        int cnt = 1;
        double sx,sy,dx,dy;
        scanf("%lf %lf %lf %lf",&sx,&sy,&dx,&dy);
        getchar();
        ara[cnt].x=sx;
        ara[cnt].y=sy;

        cnt++;
        ara[cnt].x=dx;
        ara[cnt].y=dy;
        graph[1].pb(mp(2,len(sx,sy,dx,dy)));
        graph[2].pb(mp(1,len(sx,sy,dx,dy)));
        cnt++;
        int xx=1;
        while(gets(inp))
        {
            int mn = 0;
            if(strlen(inp)==0) break;
            stringstream ss(inp);
            double x,y;
            while(ss>>x && ss>>y)
            {
                if(x==-1&&y==-1) break;
                ara[cnt].x=x;
                ara[cnt].y=y;
                if(mn>0)
                {
                    double dis = len(ara[cnt-1].x, ara[cnt-1].y, ara[cnt].x,ara[cnt].y )/4.00;
                    graph[cnt-1].pb(mp(cnt,dis));
                    graph[cnt].pb(mp(cnt-1,dis));
                }
                for(int i=1; i<=cnt; i++)
                {
                    double dis = len(ara[cnt].x, ara[cnt].y, ara[i].x, ara[i].y)/1.00;
                    graph[i].push_back(mp(cnt, dis));
                    graph[cnt].push_back(mp(i, dis));
                }
                cnt++;
                mn++;
                // cout<<x<<' '<<y<<' '<<mep[make_pair(x,y)]<<endl;

            }
        }


        for(int i = 0; i<M; i++)
        {
            dist[i]=1000000000000.0;
            visited[i]=false;
        }
        priority_queue<node> Q;
        dist[1]=0;
        Q.push(node(1,0));
        while(Q.empty()==false)
        {
            int u = Q.top().u;
            Q.pop();
            //  cout<<u<<endl;
            visited[u]=true;
            if(u==2) break;
            int sz = graph[u].size();
            for(int i = 0; i<sz; i++)
            {
                int v = graph[u][i].first;

                if(visited[v]) continue;
                double cst = graph[u][i].second;
                //  cout<<cst<<endl;
                if(dist[v] > dist[u] + cst)
                {

                    dist[v] = dist[u] + cst;
                    Q.push(node(v,dist[v]));
                }
            }
        }
        printf("%.0lf\n",dist[2]);
    }
    return 0;
}
