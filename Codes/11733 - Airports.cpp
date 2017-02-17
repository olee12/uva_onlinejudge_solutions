#include<cstdio>
#include<cstring>
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
int par[10005];
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r] = find_par(par[r]);
}
int a;
vector<edge> e;
int mst(int n);
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int flag[10005]={0};
    edge get;
    int n,m ;
    int test;
    scanf("%d",&test);
    int i,j,k,l;
    int u,v,w;
    int cas=1;
    while(test--){
        scanf("%d %d %d",&n,&m,&a);
        for(i= 0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            get.u=u;
            get.v=v;
            get.w=w;
            e.push_back(get);
        }
        //cout<<e.size()<<endl;
        int xx=0;
        for(int i = 1;i<=n;i++) par[i]=i;
        int cost = mst(n);
        //cout<<cost<<endl;
        for(i=1;i<=n;i++){
            int u = find_par(i);
            if(!flag[u]) {
                flag[u]=1;
                xx++;
            }
        }
        printf("Case #%d: %d %d\n",cas++,cost+(xx*a),xx);
        memset(par,0, sizeof par);
        memset(flag,0, sizeof flag);
        e.clear();
    }
    return 0;

}
int mst(int n)
{
    sort(e.begin(),e.end());
    int s = 0,cnt=0;
    for(int i = 0;i<e.size();i++){
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
       // cout<<u<<' '<<v<<endl;
        if(v!=u) {
            if(e[i].w <a){
            par[u]=v;
            s+=e[i].w;
            cnt++;
            if(cnt==n-1) break;
        }
        }
    }
    return s;
}
