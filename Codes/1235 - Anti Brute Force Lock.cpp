#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
struct point
{
    int u,bap;
};
struct edge
{
    point u,v;
    int w;
    bool operator < (const edge& p) const
    {
        return w < p.w;
    }
};
vector<edge> e;
int par[500];
string str[505];
struct node
{
    string str;
    int bap;
};
node ara[505];
int find_par(int r)
{
    return r==par[r] ? r : (par[r]=find_par(par[r]));
}
map <string,int> mp;
int mst(int n)
{
    sort(e.begin(),e.end());
    int cnt=0,s = 0;
    int u,v;
    for(int i = 0; i<e.size(); i++)
    {
        u = find_par(e[i].u.bap);
        v = find_par(e[i].v.bap);
        if(u!=v)
        {
            par[u]=v;
            s+=(e[i].w);
           // cout<<e[i].w<<endl;
            cnt++;
        }
    }
    return s;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    ara[0].str="0000";
    int n,test;
    int cost;
    edge get;
    int xx = 1;
    scanf("%d",&test);
    char a,b;
    while(test--)
    {
         int min_cst=1e6;
        xx=1;
        scanf("%d",&n);
        for(int i = 1; i<=n; i++)
        {
            cost = 0;
            cin>>ara[i].str;
            ara[i].bap = i;
            if(mp.find(ara[i].str)==mp.end()) mp[ara[i].str]=xx++;
            par[i]=i;
            for(int k = 0;k<4;k++){
                a = ara[0].str[k],b = ara[i].str[k];
                cost += ( abs(a-b)>5 ?(a>b ? (9-(a-48) +1 + (b-48) -0) : (9-(b-48) +1 + (a-48) -0) ): (abs(a-b)));
            }
            if(min_cst>cost) min_cst = cost;
        }

        for(int i = 1; i<=n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                cost = 0;

                a = ara[i].str[0],b = ara[j].str[0];

                cost +=( abs(a-b)>5 ?(a>b ? (9-(a-48) +1 + (b-48) -0) : (9-(b-48) +1 + (a-48) -0) ): (abs(a-b)));
               // cout<<a<<' '<<b<<' '<<cost<<' '<<abs(a-b)<<endl;
                a = ara[i].str[1],b = ara[j].str[1];

                cost +=( abs(a-b)>5 ?(a>b ? (9-(a-48) +1 + (b-48) -0) : (9-(b-48) +1 + (a-48) -0) ): (abs(a-b)));
              // cout<<a<<' '<<b<<' '<<cost<<' '<<abs(a-b)<<endl;
                a = ara[i].str[2],b = ara[j].str[2];

                cost +=( abs(a-b)>5 ?(a>b ? (9-(a-48) +1 + (b-48) -0) : (9-(b-48) +1 + (a-48) -0) ): (abs(a-b)));
               // cout<<a<<' '<<b<<' '<<cost<<' '<<abs(a-b)<<endl;
                a = ara[i].str[3],b = ara[j].str[3];

               cost +=( abs(a-b)>5 ?(a>b ? (9-(a-48) +1 + (b-48) -0) : (9-(b-48) +1 + (a-48) -0) ): (abs(a-b)));
               // cout<<a<<' '<<b<<' '<<cost<<' '<<abs(a-b)<<endl;
               // cout<<ara[i].str<<' '<<ara[j].str<<' '<<cost<<endl;
                get.u.u = mp[ara[i].str];
                get.u.bap= ara[i].bap;
                get.v.u = mp[ara[j].str];
                get.v.bap= ara[j].bap;
                get.w = cost;
                e.push_back(get);
            }
        }
        cout<<mst(n)+ min_cst<<endl;;
        memset(par,0,sizeof par);

        e.clear();
        mp.clear();
    }
    return 0;
}
