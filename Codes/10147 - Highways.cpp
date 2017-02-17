#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
    int bap;
    int city_no;
};
struct edge
{
    point u;
    point v;
    double w;
    int bap;
    bool operator < (const edge& a) const
    {
        return w<a.w;
    }
};
struct rodeline
{
    int u,v;
};
int root=0;
int par[755];
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r] = find_par(par[r]);
}
vector<edge> e,e2;
point ara[755];
int display(int i)
{
    printf("%d %d %d ----- %d %d %d  -- %lf\n",e[i].u.x,e[i].u.y,e[i].u.city_no,e[i].v.x,e[i].v.y,e[i].v.city_no,e[i].w);
}
void mst(int n)
{
    sort(e.begin(),e.end());
    double s=0;
    int cnt = 0;
    for(int i = 0; i < e.size(); i++ )
    {
        int u = find_par(e[i].u.bap);
        int v = find_par(e[i].v.bap);
        if(u!=v)
        {
            par[u]=v;
            printf("%d %d\n",e[i].u.city_no,e[i].v.city_no);
            root=1;

            cnt++;
            if(cnt==n-1) break;
        }
    }

}
int main()
{
#ifndef ONLINE_JUDGE
  //  freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    edge get;
    int n,m,test;
    int x,y,u,v;
    int f=0;
    double w;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i = 1; i<=n; i++)
        {
            scanf("%d %d",&ara[i].x,&ara[i].y);
            ara[i].bap=ara[i].city_no=i;
        }
        scanf("%d",&m);
        for(int i = 1; i<=n; i++) par[i]=i;
        for(int i = 0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            x = find_par(u);
            y = find_par(v);
            if(x!=y) par[x]=y;


        }
        for(int i = 1; i<=n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                get.u = ara[i];
                get.v = ara[j];
                get.w = sqrt( abs(ara[i].x-ara[j].x)*abs(ara[i].x-ara[j].x) + abs(ara[i].y-ara[j].y)*abs(ara[i].y-ara[j].y));
                e.push_back(get);
            }
        }


        if(f) puts("");f=1;
        root=0;
        mst(n);



        if(root==0) printf("No new highways need\n");

        e.clear();
        memset(par,0,sizeof par);


    }
    return 0;

}

