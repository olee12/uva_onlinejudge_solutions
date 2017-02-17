#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    int bap;
};
point ara[1005];
struct edge
{
    point u;
    point v;
    double w;
    bool operator < (const edge & p) const
    {
        return w<p.w;
    }
};
vector<edge> e;
int par[1005];
int find_par(int r)
{
    return (r==par[r]? r :(par[r]=find_par(par[r])));
}
int mst(int n,int m)
{
    int cnt = 0;
    double s = 0;
    sort(e.begin(),e.end());
    for(int i = 0; i<e.size(); i++)
    {
        int u = find_par(e[i].u.bap);
        int v = find_par(e[i].v.bap);

        if(u!=v)
        {
            par[u]=v;
            s = e[i].w;
            m--;
            if(m== n) return ceil(s);
        }
    }
    return ceil(s);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    edge get;
    int test;
    int n,m;
    double x,y;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        m = 0;
        while(scanf("%lf",&x))
        {
            if(x==-1) break;
            scanf("%lf",&y);
            ara[m].x = x;
            ara[m].y = y;
            ara[m].bap=m;
            par[m]=m;
            m++;
        }
        for(int i = 0; i<m; i++)
        {
            for(int j = i+1; j<m; j++)
            {
                get.u = ara[i];
                get.v = ara[j];
              //  cout<<get.u.x<<' '<<get.u.y<<"       "<<get.v.x<<' '<<get.v.y<<"     ";
                get.w = sqrt( abs(ara[i].x-ara[j].x)*abs(ara[i].x-ara[j].x) + abs(ara[i].y-ara[j].y)*abs(ara[i].y-ara[j].y));
               // cout<<get.w<<endl;
                e.push_back(get);
            }
        }
       // cout<<n<<endl;
       //cout<<m<<endl;
        cout<<mst(n,m)<<endl;
      //  memset(par,0,sizeof par);
        e.clear();
    }
    return 0;

}

/*
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int x[1005], y[1005];
struct E
{
    int x, y;
    long long v;
    E(int a, int b, long long c):
        x(a), y(b), v(c) {}
    E():
        x(0), y(0), v(0) {}
    bool operator<(const E &a) const
    {
        return  v < a.v;
    }
};
E D[1000000];
int p[1005];
int findp(int x)
{
    return p[x] == x ? x : (p[x]=findp(p[x]));
}

int main()
{
    // freopen("input.txt","r",stdin);
    int testcase;
    int i, j;
    scanf("%d", &testcase);
    while(testcase--)
    {
        int n, m, e;
        scanf("%d", &n);
        m = 0, e = 0;
        while(scanf("%d", &x[m]) == 1 && x[m] != -1)
            scanf("%d", &y[m]), m++;
        for(i = 0; i < m; i++)
            for(j = i+1; j < m; j++)
                D[e++] = E(i, j, ((long long)x[i]-x[j])*(x[i]-x[j])+((long long)y[i]-y[j])*(y[i]-y[j]));
        sort(D, D+e);
        for(i = 0; i < m; i++)
            p[i] = i;
        int component = m;
        int xx,yy;
        for(i = 0; i < e; i++)
        {
            xx=findp(D[i].x);
            yy=findp(D[i].y);
            if(xx!=yy)
            {
                component--;
                p[xx]=yy;
            }

            if(component == n)
            {
                printf("%.0lf\n", ceil(sqrt(D[i].v)));
                break;
            }
        }
    }
    return 0;
}
*/
