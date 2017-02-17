#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    bool operator< (const edge& p) const
    {
        return w<p.w;
    }
};
int par[200005];
vector<edge> e;
int find_par(int r)
{
    if(par[r]==r) return r;
    return par[r]=find_par(par[r]);
}
int mst(int n)
{
    sort(e.begin(),e.end());
    int s=0;
    for(int i = 0;i<e.size();i++){
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(v!=u){
            par[u]=par[v];
            s+=e[i].w;
        }
    }
    return s;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n,m;
    edge get;
    int u,v,w;
    int total;
    while(scanf("%d %d",&m,&n)&& (m|n)){
            total=0;
        for(int i = 0;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            get.u=u;get.v=v;
            get.w=w;
    total+=w;
            e.push_back(get);
        }
        for(int i = 0;i<m;i++) par[i]=i;
        cout<<total-mst(m)<<endl;
        for(int i = 0;i<m;i++) par[i]=0;
        e.clear();
    }
    return 0;
}
