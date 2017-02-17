#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int par[50005];

int find_par(int r)
{
    if(par[r]==0) return r;
    if(r==par[r]) return r;
    return par[r] = find_par(par[r]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int cas=1;
    int n,m;
    int a,b;
    int u,v;
    while(scanf("%d %d",&n,&m)==2){
            if(n==0 && m==0) return 0;
            set<int> rig;
        //for(int i = 1;i<=n;i++) par[i]=i;
        for(int i = 0;i<m;i++){

            scanf("%d %d",&a,&b);
            u = find_par(a);
            v = find_par(b);
            if(u!=v){
                par[u]=v;

            }

        }

            for(int i = 1;i<=n;i++){
                    rig.insert(find_par(i));

                //cout<<"find_par("<<i<<")"<<par[i]<<endl;
            }
        printf("Case %d: %d\n",cas++,rig.size());
 memset(par,0,sizeof par);


    }
    return 0;


}
