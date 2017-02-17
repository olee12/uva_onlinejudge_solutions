#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u , v,w ;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};
vector<edge> e;
int par[1000];
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r]=find_par(par[r]);
}
vector<int > high;
int mst(int n)
{
    sort(e.begin(),e.end());
    int s=0,cnt=0;
    for(int i = 0; i<e.size(); i++)
    {
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(v!=u)
        {
            par[u]=v;
            cnt++;
            s+=e[i].w;

        }
        else
        {
            //cout<<e[i].w<<endl;
            high.push_back(e[i].w);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int m,n;
    int u,v,w;
    edge get;
    while(scanf("%d %d",&n,&m),(m|n))
    {
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            get.u=u;
            get.v=v;
            get.w=w;
            e.push_back(get);
        }
        for(int i = 0; i<n; i++) par[i]=i;
        int res=mst(n);
        if(high.size())
        {
            for(int i = 0; i<high.size(); i++)
            {
                if(i) cout<<' ';
                cout<<high[i];
            }
            cout<<endl;
        }
        else
        {
            cout<<"forest\n";
        }
        e.clear();
        high.clear();
        memset(par,0,sizeof par);
    }
    return 0;
}
