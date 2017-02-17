
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x;
    double y;
    int bap;
    bool operator== (const point& a) const
    {
        if(a.x==x && a.y==y) return true;
        return false;
    }
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
typedef pair<double,double> dd;
point ara[505];
int  par[505];
int find_par( int r)
{
    if(r == par[r]  ) return r;
    return par[r]=find_par(par[r]);
}
vector<edge> e;
int z;
double mst(int n)
{
    sort(e.begin(),e.end());
    int cnt=0;
    double s = 0;
    for(int i = 0;i<e.size();i++)
    {
        int u = find_par(e[i].u.bap);
        int v = find_par(e[i].v.bap);
       // cout<<e[i].u.bap<<' '<<e[i].v.bap<<endl;
        if(v!=u){
            cnt++;
            par[u]=v;
            if(s<e[i].w){
            s=e[i].w;

            }
            if(cnt== n-z) break;
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
    int f=0;
    int m;
    scanf("%d",&test);
    while(test--)
    {
        cin>>z>>m;
        for(int i = 0; i<m; i++)
        {
            cin>>ara[i].x>>ara[i].y;
           // cout<<ara[i].x<<' '<<ara[i].y<<endl;
            ara[i].bap = i+1;
            par[i+1]=i+1;
           // cout<<ara[i].bap<<endl;
        }
        for(int i = 0; i<m; i++)
        {
            for(int j = i+1; j<m; j++)
            {
                get.u = ara[i];
                get.v = ara[j];
                get.w = sqrt( abs(ara[i].x-ara[j].x)*abs(ara[i].x-ara[j].x) + abs(ara[i].y-ara[j].y)*abs(ara[i].y-ara[j].y));

                e.push_back(get);
            }
        }

        int n = m;


        printf("%0.2lf\n",mst(m));
        memset(par,0,sizeof par);

        e.clear();
    }
    return 0;

}

