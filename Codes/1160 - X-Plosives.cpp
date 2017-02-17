#include<bits/stdc++.h>
using namespace std;
int par[100005];
int find_par(int r)
{
    return (r==par[r]? r :(par[r]=find_par(par[r])));
}
int main()
{
    for(int i = 0; i<100005; i++) par[i]=i;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int a,b;
    int cnt = 0;
    int u , v;
    while(scanf("%d",&a)!=EOF)
    {
        // cout<<a<<endl;
        cnt = 0;
        for(int i = 0; i<100005; i++) par[i]=i;
        while(a!=-1)
        {
            scanf("%d",&b);
            // cout<<b<<endl;

            u = find_par(a);
            v = find_par(b);
            if(u!=v)
            {
                par[u]=v;

            }
            else cnt++;
            scanf("%d",&a);
        }
        printf("%d\n",cnt);
    }
    return 0;
}
