#include<cstring>
#include<string>
#include<iostream>
#include<cstdio>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;
map<string ,int > name;
int par[5005];
int cnt[5005];
int find_par(int r)
{
    if(par[r]==0) return r;
    if(r==par[r]) return r;
    return par[r]=find_par(par[r]);

}
int Union(int a,int b)
{
    par[find_par(a)]=par[find_par(b)];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int c,r;
    string str1,str2;
    int xx=1;
    while(scanf("%d %d",&c,&r)==2)
    {
        if(c==0 && r==0 ) return 0;
        xx=1;
        for(int i = 0; i<c; i++)
        {
            cin>>str1;
            if(!name[str1])
            {
                name[str1]=xx++;

            }

        }
        for(int i = 0; i<r; i++)
        {
            cin>>str1>>str2;
            int a = find_par(name[str1]);
            int b = find_par(name[str2]);
            if(a!=b)
            {
                par[a]=b;
                cnt[b]=(cnt[a]?cnt[a]:1) + (cnt[b]?cnt[b]:1);

            }


        }
        int m = 1;
        for(int i = 1; i<=xx; i++) m = max(m,cnt[i]);
        printf("%d\n",m);
        memset(par,0,sizeof(par));
        memset(cnt,0,sizeof cnt);
        name.clear();

    }


}

