#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int par[10005];
int money[10005];
int find_par(int r)
{
    if(r==par[r]) return r;
    return par[r] = find_par(par[r]);
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int test;
    int m,n;
    int a,b;
    int u,v;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&m);
        for(int i = 0;i<n;i++){
            scanf("%d",&money[i]);
            par[i]=i;
        }
        for(int i = 0;i<m;i++){
            scanf("%d %d",&a,&b);
            u = find_par(a);
            v = find_par(b);
            if(u!=v){
                par[u]=v;
                money[v]+=money[u];
                money[u]=0;
            }

        }
        int flag = 1;
        for(int i = 0;i<n;i++) if(money[i]!=0) {
            flag = 0;
            break;
        }
        if(flag) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;

}
