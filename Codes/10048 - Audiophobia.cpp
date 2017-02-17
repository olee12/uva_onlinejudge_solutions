#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u ,v , w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};
int a,b;
int par[105];
vector<edge > e;
int find_par(int r)
{
    if(par[r]==r) return r;
    return par[r] = find_par(par[r]);
}
int mst(int n)
{

    int s = 0;
    int cnt=0;
    for(int i = 0 ; i<e.size(); i++)
    {
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            if(s<e[i].w) s= e[i].w;
            if(find_par(a)==find_par(b)) return s;

        }
    }
    return -1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int c,s,q;
    int res;
    edge get;
    int u,v,w;
    int f= 0;
    int cas=1;
    while(scanf("%d %d %d",&c,&s,&q)==3 && (c+s+q))
    {
        for(int i = 1; i<=s; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            e.push_back(get);

        }
         sort(e.begin(),e.end());
        if(f) puts("");f=1;
        printf("Case #%d\n",cas++);
        for(int i = 0; i<q; i++)
        {
            for(int i= 1;i<=c;i++) par[i]=i;
            scanf("%d %d",&a,&b);
            res = mst(c);
                  if(res!=-1) printf("%d\n",res);
            else printf("no path\n");

            //for(int i= 1;i<=c;i++) par[i]=i;
        }
        e.clear();
    }
    return 0;
}

