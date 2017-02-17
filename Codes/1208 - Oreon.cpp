#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        if(w!=p.w)
        return w<p.w;
        if(u!=p.u) return u<p.u;
        return v<p.v;
    }
};
vector<edge> e;
int par[1005];
int find_par(int r)
{
    return r==par[r]?r:(par[r]=find_par(par[r]));
}
int mst(int n)
{
    int s=0,cnt=0;
    sort(e.begin(),e.end());
    for(int i = 0;i<e.size();i++){
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(u!=v){
            printf("%c-%c %d\n",e[i].u+'A',e[i].v+'A',e[i].w);
            par[u]=v;
            cnt++;
            if(cnt==n-1) break;

        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int test;
    int n;
    int w;
    edge get;
    int cas=1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                scanf("%d, ",&w);
                if(w)
                {
                    get.u=i;
                    get.v=j;
                    get.w=w;
                    e.push_back(get);
                }
            }
        }
        printf("Case %d:\n",cas++);
        for(int i = 0;i<n;i++) par[i]=i;
        mst(n);
        e.clear();memset(par,0,sizeof par);
    }
    return 0;

}
