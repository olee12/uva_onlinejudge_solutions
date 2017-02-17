
#include<cstdio>
#include<string>
#include<bits/stdc++.h>

using namespace std;
#define sz sizeof
struct point
{
    int x,y;
    int bap;

};
struct edge
{
    point u;
    point v;
    double w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
int r;
point ara[1005];
int par[1005];
vector<edge> e;
int state=1;
double road;
double rail;
int find_par( int r)
{
   // cout<<r<<endl;
    if(r == par[r]  ) return r;
    return par[r]=find_par(par[r]);
}
double mst(int n)
{
    sort(e.begin(),e.end());
    double s = 0;int cnt=0;
    for(int i = 0;i<e.size();i++){
        int u = find_par(e[i].u.bap);
        int v = find_par(e[i].v.bap);
    //cout<<e[i].u.bap<<' '<<e[i].v.bap<<endl;
        if(v!=u) {
            if(e[i].w > (double)r){
               par[u]=v;
                rail += e[i].w;
                state++;
            }
            else {
                    par[u]=v;
                    road += e[i].w;

            }
            cnt++;
            if(cnt==n-1) break;
        }
    }
    road+=.5;
    rail+=.5;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n;
    edge get;
    int test;
    scanf("%d",&test);
    int cas=1;
    while(test--){
            int xx=1;
    scanf("%d %d",&n,&r);
        for(int i = 0;i<n;i++){
            scanf("%d %d",&ara[i].x,&ara[i].y);
            ara[i].bap = xx++;
        }
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                get.u=ara[i];
                get.v=ara[j];
                get.w = sqrt( abs(ara[i].x-ara[j].x)*abs(ara[i].x-ara[j].x) + abs(ara[i].y-ara[j].y)*abs(ara[i].y-ara[j].y));
                e.push_back(get);
            }
        }

    for(int i = 1;i<=n;i++){
        par[i]=i;
    }
     // for(int i = 0; i<e.size(); i++)
      //  {
            //e[i].bap=i+1;
       //     cout<<e[i].u.x<<' '<<e[i].u.y<<' '<<e[i].u.bap<<"      "<<e[i].v.x<<' '<<e[i].v.y<<"     "<<e[i].w<<endl;
      //  }
        int m = n;
        //m=m*(m-1)/2;
        double res = mst(n);
        printf("Case #%d: ",cas++);
        cout<<state<<' '<<floor(road)<< ' ' <<int(rail)<<endl;
        e.clear();
        memset(par,0,sz par);
        state=1;road=rail=0;
    }
    return 0;
}
