#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w > p.w;
    }
};
int par[150];
vector< edge > e;
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r]=find_par(par[r]);
}
int mst(int n)
{
    sort(e.begin(),e.end());
    int s=1e6;
    int cnt = 0;
    for(int i = 0; i<e.size(); i++)
    {
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(v!=u)
        {
            par[u]=v;
            if(s>e[i].w) s=e[i].w;
        }

    }
    return s;

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    edge get;
    int test;
    int n,m;
    scanf("%d",&test);
    int v,u,w;
    int cas=1;
    while(test--){
        scanf("%d %d",&n,&m);
       // printf("%d %d\n",n,m);
        for(int i = 0;i<m;i++){
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            e.push_back(get);
        }
        for(int i = 0;i<=100;i++) par[i]=i;
        printf("Case #%d: %d\n",cas++,mst(n));
        e.clear();
    }
    return 0;
}
