#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    bool operator< (const edge& p) const
    {
        return w>p.w;
    }
};
int a,b;
vector<edge> e;
map<string,int> name;
int par[300];
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r]=find_par(par[r]);
}
int mst(int n)
{
    sort(e.begin(),e.end());
    int s = 1e5;
    for(int i = 0;i<e.size();i++){
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(v!=u){
            par[u]=v;
            if(s>e[i].w) s=e[i].w;
            if(find_par(a)==find_par(b)) return s;
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int m,n;
    int w;
    edge get;
    int cas=1;
    char str1[35],str2[35];
    while(scanf("%d %d",&n,&m),(m|n)){
            //cout<<m<<' '<<n<<"\n";
        int xx=1;
        for(int i = 0;i<m;i++){
            scanf(" %s %s %d",str1,str2,&w);
   // cout<<i<<endl;
            if(name.find(str1)==name.end()) {
                name[str1]=xx++;
            }
            if(name.find(str2)==name.end()) {
                name[str2]=xx++;
            }
            get.u = name[str1];get.v=name[str2];get.w=w;
            e.push_back(get);

        }
        scanf(" %s %s",str1,str2);
        //cout<<str1<<' '<<str2<<endl;
        a=name[str1];b=name[str2];
        for(int i = 1;i<=n;i++) par[i]=i;
       printf("Scenario #%d\n",cas++);

        cout<<mst(n);;printf(" tons\n\n");
        e.clear();
        memset(par,0,sizeof par);
        name.clear();
    }
    return 0;
}
