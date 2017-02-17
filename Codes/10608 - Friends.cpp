#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 30005;
int par[MAX];
int cnt[MAX];
int find_par(int r)
{
    if(par[r]==r) return r;
    return (par[r] = find_par(par[r]));
}

void Union(int a , int b)
{
    int u = find_par(a);
    int v = find_par(b);
     par[u]=v;

}
void makeset(int n)
{
    par[n]=n;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int test;
    int N,M;
    scanf("%d",&test);
    int a,b;
    while(test--)
    {
        scanf("%d %d",&N,&M);
        for(int i = 1; i<=N; i++) cnt[par[i]=i]=0;
        for(int i =0; i<M; i++)
        {
            scanf("%d %d",&a,&b);
            Union(a,b);
        }
        int m=1;
        for(int i = 1; i<=N; i++)
        {
            cnt[find_par(i)]++;
           // m = max(m,cnt[i]);

        }
        for(int i = 1;i<=N;i++){
            m = max(m,cnt[i]);
        }
        printf("%d\n",m);
       // memset(cnt,0,sizeof(cnt));
        //memset(par,0,sizeof par);

    }
    return 0;
}
