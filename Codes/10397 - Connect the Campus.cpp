#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x, y;
    int bap;
};
struct edge
{
    point u;
    point v;
    double w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};
vector<edge> e;
point ara[755];
int par[755];
int m;
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r]=find_par(par[r]);
}
double mst(int n)
{
    double s=0;
    int cnt=0;
    sort(e.begin(),e.end());
    for(int i = 0; i<e.size(); i++)
    {
        int u = find_par(e[i].u.bap);
        int v = find_par(e[i].v.bap);
        if(u!=v)
        {
            par[u]=v;

            s+= e[i].w;
            cnt++;
           // if(cnt==n-m-1) break;
        }
    }
    return s;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE
    int n;
    edge get;
    int x,y,u,v,d;
    while(scanf("%d",&n)==1)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d",&ara[i].x,&ara[i].y);
            ara[i].bap=i;
            par[i]=i;
        }

        for(int i = 1; i<=n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                get.u=ara[i];
                get.v=ara[j];
                get.w = sqrt( abs(ara[i].x-ara[j].x)*abs(ara[i].x-ara[j].x) + abs(ara[i].y-ara[j].y)*abs(ara[i].y-ara[j].y));
                e.push_back(get);
            }
        }
        scanf("%d",&m);
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            int x = find_par(u);
            int y = find_par(v);
            if(x!=y)
            {
                par[x]=y;
            }
        }
        printf("%.2lf\n",mst(n));
        e.clear();
        memset(par,0,sizeof par);
    }
    return 0;
}
