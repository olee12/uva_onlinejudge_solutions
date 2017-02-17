
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
    bool operator < (const edge& p) const
    {
        return w < p.w;

    }
};
vector<edge> e;
int par[1000001];
int find_par(int r)
{
    if(r == par[r]) return r;
    return par[r] = find_par(par[r]);
}
int mst(int n)
{
    int s = 0, cnt = 0;
    sort(e.begin(), e.end());
    for(int i = 0; i < e.size(); i++)
    {
        int u = find_par(e[i].u);
        int v = find_par(e[i].v);
        if(u != v)
        {
            par[u] = v;
            s += e[i].w;
            cnt++;
            if(cnt == n - 1) return s;
        }
    }
    return s;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int n, m, k;
    int old;
    int pre;
    int u, v, w;
    int f = 0;
    edge get;
    while(scanf("%d", &n) == 1)
    {
        for(int i = 1; i <= n; i++) par[i] = i;
        old = 0;
        for(int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            old += w;
        }
        scanf("%d", &k);
        for(int i = 0; i < k; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
        }
        pre = mst(n);
        if(f) puts("");
        f = 1;
        printf("%d\n%d\n", old, pre);
        memset(par, 0, sizeof par);
        e.clear();
    }

}
