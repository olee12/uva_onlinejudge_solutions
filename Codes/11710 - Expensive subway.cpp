#include<bits/stdc++.h>
using namespace std;
#define in(n,m) scanf("%d %d",&n,&m)
struct edge
{
    int u,v,w;
    bool operator< (const edge& p) const
    {
        return w<p.w;
    }
};
vector<edge> e;
int par[405];
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r]=find_par(par[r]);
}
int mst(int n)
{
    sort(e.begin(),e.end());
    int s=0,cnt=0;
    for(int i = 0;i<e.size();i++)
    {
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(v!=u){
            par[u]=v;
            s+=e[i].w;
            cnt++;
            if(cnt==n-1) return s;
        }
    }
    return s;
}
map<string,int > name;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    char str1[25],str2[25];
    int n,m;
    edge get;
    int w;
    while(in(n,m),(m|n)){
            int xx=1;
        for(int i = 0;i<n;i++){
            scanf(" %s",str1);
            name[str1]=xx++;
        }
    for(int i = 0;i<m;i++){
        scanf(" %s %s %d",str1,str2,&w);
    //  printf (" %s %s %d\n",str1,str2,w);
        get.u=name[str1];
        get.v=name[str2];
        get.w=w;
        e.push_back(get);
    }
    scanf(" %s",str1);
    int a=name[str1];
    int impos=0;
    for(int i = 1;i<=n;i++)
        par[i]=i;
        int res = mst(n);
        for(int i = 1;i<=n;i++){
            if(find_par(i)!=find_par(a)) impos=1;
        }
        if(impos) printf("Impossible\n");
        else printf("%d\n",res);
        name.clear();
        e.clear();
        memset(par,0,sizeof par);
    }
    return 0;

}
