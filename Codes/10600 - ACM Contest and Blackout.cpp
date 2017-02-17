#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
int x,y;
vector<edge > e,e1;
int par[110];
int find_par(int r)
{
    return (r==par[r] ? r : (par[r] = find_par(par[r])));
}

int mst1(int n)
{
    sort(e.begin(),e.end());
    int s=0,cnt=0;
    int u,v,f=0;
    for(int i= 0; i<e.size(); i++)
    {
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            e1.push_back(e[i]);
            par[u]=v;
            s+=e[i].w;
            cnt++;
        }
    }
    return s;
}
int mst2(int n)
{
    int s = 0;
    int cnt = 0;
    int u,v;
    for(int i = 0; i<e.size(); i++)
    {
        if(x == e[i].u && y == e[i].v)
        {
            continue;
        }
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            s+=e[i].w;
        }
    }
    if(cnt==n-1)
    return s;
    else return 1e6;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int test;
    int n,m;
    int u,v,w;
    edge get;
    scanf("%d",&test);
    while(test--)
    {
        e.clear();
        e1.clear();
        memset(par,0,sizeof par);
        scanf("%d %d",&n,&m);
        for(int i = 1; i<=n; i++) par[i]=i;
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            e.push_back(get);
        }
        int res1 = mst1(n);
        int sec =1e6;
        int res2;

        for(int i = 0; i<e1.size(); i++)
        {
            x = e1[i].u;
            y = e1[i].v;
            for(int i = 1; i<=n; i++) par[i]=i;
            res2 = mst2(n);
            if(sec>res2 ) sec = res2;
        }
        printf("%d %d\n",res1,sec);


    }
    return 0;
}
