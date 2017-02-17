#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define     M               1000015
#define     sz(a)           (int)a.size()
#define     VII             vector<int> :: iterator
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     REP(i,j,k)      for(i=j;i<=(k);i++)
#define     all(a)          a.begin(),a.end()
struct edge
{
    ll u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
ll par[M];
vector<edge> e;
int find_par(int r)
{
    return ( par[r]==r? r : par[r]=find_par(par[r]) );
}
int mst(int n)
{
    int s = 0,cnt = 0;
    sort(all(e));
    for(int i = 0; i<sz(e); i++)
    {
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            s=e[i].w;
            if(cnt==n-1) return s;
        }
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int m,n;
    edge get;
    int i,j,k,u,v,w;
    while(scanf("%d %d",&n,&m),(m|n))
    {
        REP(i,0,n) par[i]=i;
        REP(i,0,m-1)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            e.push_back(get);
        }
        int res = mst(n);
        if(res!=-1) printf("%d\n",res);
        else printf("IMPOSSIBLE\n");
        e.clear();
    }
    return 0;

}
