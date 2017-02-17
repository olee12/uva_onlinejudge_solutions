#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
map<string,int > str_num;
int par[50005];
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r]=find_par(par[r]);
}
vector<edge> e;
int mst(int n)
{
    int u,v;
    int s = 0,cnt = 0;
    sort(e.begin(),e.end());
    for(int i = 0; i<e.size(); i++)
    {
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            s+=e[i].w;
            if(cnt==n-1)return s;
        }
    }
    return s;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int test;
    int m,n,xx;
    edge get;
    char str1[25],str2[25];
    int w;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        xx=1;
        for(int i = 0; i<m; i++)
        {

            scanf("%s %s %d",str1,str2,&get.w);
          //  cout<<str1<<' '<<str2<<endl;
            if(str_num.find(str1)==str_num.end())
            {
                str_num[str1]=xx++;
            }
            if(str_num.find(str2)==str_num.end())
            {
                str_num[str2]=xx++;
            }
            get.u=str_num[str1];
            get.v=str_num[str2];
            e.push_back(get);
        }
        for(int i = 1;i<=n;i++) par[i]=i;

        printf("%d\n",mst(n));
        if(test) puts("");
        e.clear();str_num.clear();
        memset(par,0,sizeof par);
    }
    return 0;
}
