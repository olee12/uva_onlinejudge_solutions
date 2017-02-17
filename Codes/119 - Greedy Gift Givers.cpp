#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    char ara[50];
    bool f = false;
    while(scanf("%d",&n)==1)
    {
        if(f) puts("");f = true;
        vector<string> v;
        map<string,int> mp;
        for(int i = 0; i<n; i++)
        {
            scanf("%s",ara);
            mp[string(ara)];
            v.push_back(string(ara));
        }
        for(int i = 0; i<n; i++)
        {
            int x,money;
            scanf(" %s %d %d",ara,&money,&x);
            if(x==0) continue;
            mp[string(ara)]-=(money);
            mp[string(ara)]+=(money%x);
            money/=x;
            for(int j = 0; j<x; j++)
            {
                scanf(" %s",ara);
                mp[string(ara)]+= money;
            }
        }
        for(int i = 0; i<n; i++) printf("%s %d\n",v[i].c_str(),mp[v[i]]);
    }
    return 0;
}
