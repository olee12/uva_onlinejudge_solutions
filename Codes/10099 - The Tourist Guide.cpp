#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w>p.w;
    }
};
int par[105];
vector<edge> e;
int find_par(int r)
{
    if(par[r]==r) return r;
    return par[r] = find_par(par[r]);
}
int a,b;
int mst(int n)
{
    sort(e.begin(),e.end());
    int s=0;
    int zz=1e5;
    int cnt=0;
    for(int i = 0; i<e.size(); i++)
    {
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            zz = e[i].w;
            if(find_par(a)==find_par(b)) return zz;

        }
    }
    // return zz;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n,r,u,v,w;
    int cas=1;
    edge get;
    int pas;
    while(scanf("%d %d",&n,&r),(n|r))
    {
        for(int i = 0; i<r; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            get.u=u;
            get.v=v;
            get.w=w;
            e.push_back(get);
        }
        for(int i = 1; i<=n; i++) par[i]=i;
        scanf("%d %d %d",&a,&b,&pas);
        int res = mst(n);
        //cout<<res<<endl;
        cout<<"Scenario #"<<cas++<<endl;
        cout<<"Minimum Number of Trips = ";
        int num = pas / (res-1);
        if(pas%res) num++;
        cout<<num<<endl<<endl;;
        e.clear();
        memset(par,0,sizeof par);
    }
    return 0;
}
