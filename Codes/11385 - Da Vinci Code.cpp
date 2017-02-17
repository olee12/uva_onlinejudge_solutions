#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<iterator>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
long long ara[100];
map<long long,int> mp;
bool flag[105];

int main()
{
   // freopen("input.txt","r",stdin);
    ara[1]=1;
    ara[2]=2;
    mp[2]=2;
    mp[1]=1;
    for(int i = 3; i<85; i++)
    {
        ara[i]=ara[i-2]+ara[i-1];
        mp[ara[i]]=i;
    }
    int test;
    int n;
    char str[105];
    char out[105];
    long long inp[100];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        memset(out,0,sizeof out);
        memset(flag,0,sizeof flag);
        for(int i = 1; i<=n; i++) scanf("%lld",inp+i);
        getchar();
        gets(str);
        int len = strlen(str);
        int ind = 1;
        int mx = 0;
        for(int i = 0; i<len && ind<=n; i++)
        {
           // cout<<"i : "<<i<<' '<<len<<endl;
            if((str[i]>='A' && str[i]<='Z'))
            {
                // cout<<str[i]<<' ';
               // cout<<mp[inp[ind]]<<' ' <<inp[ind]<<endl;
                out[mp[inp[ind]]] = str[i];
                flag[mp[inp[ind]]] = true;
                // cout<<ind<<endl;
                if(mp[inp[ind]] > mx) mx = mp[inp[ind]];
                ind++;

            }
        }

        for(int i = 1; i<=mx; i++)
        {
            if(flag[i]==false) out[i]=' ';
        }
        // for(int i = 1;i<=mx;i++) printf("%c",out[i]);
        // puts("");
        puts(&out[1]);
    }
    return 0;

}
