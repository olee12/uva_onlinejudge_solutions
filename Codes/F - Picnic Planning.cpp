#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>

//#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
typedef long long ll;


#define sf scanf
#define pf printf
#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())
#define INF 21474836450
#define X first
#define Y second
#define M 100
struct edge
{
    int u,v,w;
    bool operator < (const edge& p) const
    {
        return w<p.w;
    }
};
int par[M];
vector<edge> e;
edge get;
int mx;
int dop;
int park,c;
int find_par(int r)
{
    return r==par[r] ? r : par[r] = find_par(par[r]);
}
int mst(int n)
{
   // for(int i = 0; i<=n+2; i++) par[i]=i;
    int u,v,s=0,cnt = 1;
    int zz = (int) e.size();
    bool flag = 0;
    for(int i= 0; i<zz; i++)
    {
        if(e[i].u==park || e[i].v==park) flag = 1;
        u = find_par(e[i].u);
        v = find_par(e[i].v);
        if(u!=v)
        {
            if(c>dop && flag)
            {
                flag = 0;
                continue;
            }
            if(flag) c++;
            flag = 0;
            par[u]=v;
            s += e[i].w;
            cnt++;
            if(cnt==n) break;
        }
    }
    return s;
}
map<string,int > name;
int main()
{
    int n;
    char str1[50],str2[50];
    while(sf("%d",&n)==1)
    {
        name.clear();
        e.clear();
        int xx = 1;
        for(int i = 0; i<n; i++)
        {
            sf("%s %s %d",str1,str2,&get.w);
            if(name.find(string(str1))==name.end()) name[str1]=xx++;
            if(name.find(string(str2))==name.end()) name[str2]=xx++;
            get.u = name[str1];
            get.v = name[str2];
            e.push_back(get);
        }
        sf("%d",&dop);
        park = name[string("Park")];
        c = 0;
        for(int i = 0; i<=xx; i++) par[i]=i;
        sort(e.begin(),e.end());
        int res = mst(xx-1);
        pf("Total miles driven: %d\n",res);
    }
    return 0;
}
/*
10
Alphonzo Bernardo 32
Alphonzo Park 57
Alphonzo Eduardo 43
Bernardo Park 19
Bernardo Clemenzi 82
Clemenzi Park 65
Clemenzi Herb 90
Clemenzi Eduardo 109
Park Herb 24
Herb Eduardo 79
3*/
