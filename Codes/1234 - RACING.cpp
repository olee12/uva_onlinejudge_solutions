#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u,v,w;
    bool operator < (const edge& p) const;
};

bool edge :: operator < (const edge& p) const
{
    return w > p.w;
}
int n,m;
vector<edge> e;
int par[10010];
int find_par(int r)
{
    return ((r==par[r])? r : (par[r]=find_par(par[r])));
}
int mst()
{
    int cnt = 0;
    int s = 0;
    int u ,v;
    sort(e.begin(),e.end());
    for(int i = 0; i <m; i++)
    {
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            s+=e[i].w;
            cnt++;
            if(cnt == n-1) return s;
        }
    }
    return s;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int test;
    int total;
    edge get;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        total = 0;
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            total += get.w;
            e.push_back(get);
        }
        for(int i = 1; i<=n; i++) par[i]=i;
        printf("%d\n",total - mst());
        e.clear();
        // memset(par,0,sizeof par);

    }
    scanf("%d",&test);
    return 0;
}
