#include<cstring>
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w,pos;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};

int par[110];
int find_par(int r)
{
    return (r==par[r] ? r : (par[r]= find_par(par[r])));
}
vector<edge> e,sec_mst;

int x,y,www,pos;
int mst1(int n)
{

    int s= 0,cnt=0;
    sort(e.begin(),e.end());
    int u,v;
    for(int i = 0; i<e.size(); i++)
    {
        u = find_par(e[i].u);
        v = find_par(e[i].v);

        if(u!=v)
        {
            par[u]=v;
            sec_mst.push_back(e[i]);
            s += e[i].w;
            cnt++;
            if(cnt== n-1) return s;
        }
    }
    return -1;
}


int mst2(int n)
{
    int s = 0,cnt=0;
    int u,v;
    for(int i = 0; i<e.size(); i++)
    {
        if(x==e[i].u && y == e[i].v && www==e[i].w && pos==e[i].pos)
        {
            //  cout<<x<<' '<<y<< ' '<<s<<endl;
            continue;
        }
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {

            cnt++;
            par[u]=v;
            s+=e[i].w;
            if(cnt == n-1) return s;
        }
    }
    return -1;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE

    edge get;
    int test;
    int n,m;
    int u,v,w,res1,res2,cnt;
    scanf("%d",&test);
    int cas=1;
    while(test--)
    {
        e.clear();
        sec_mst.clear();
     //   memset(par,0,sizeof par);
        scanf("%d %d",&n,&m);
        if(n==1 && m==0)
        {
            printf("Case #%d : No second way\n",cas++);
            continue;
        }


        for(int i = 1; i<=n; i++) par[i]=i;


        for(int i = 0; i<m; i++)
        {
            scanf("%d %d %d",&get.u,&get.v,&get.w);
            get.pos=i;
            e.push_back(get);
        }


        res1 = mst1(n);

        if(res1==-1)
        {
            printf("Case #%d : No way\n",cas++);
            continue;
        }
        cnt = 1e8;
        for(int i = 0; i <(int)sec_mst.size(); i++)
        {
            x = sec_mst[i].u;
            y = sec_mst[i].v;
            www = sec_mst[i].w;
            pos=sec_mst[i].pos;
            for(int i = 1; i<=n; i++) par[i]=i;
            res2 = mst2(n);
            if(cnt>res2 && res2!=-1) cnt=res2;
        }
        if(cnt!=1e8)
        {

            printf("Case #%d : %d\n",cas++,cnt);
        }
        else
        {
            printf("Case #%d : No second way\n",cas++);
        }

    }
    return 0;
}

