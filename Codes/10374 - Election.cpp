#include<cstdio>
#include<cstring>
#include<iterator>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    getchar();
    bool f = 0;
    while(test--)
    {
        if(f) puts(""); f = 1;
        map<string , pair<string,int> > mp;
        char name[100];
        char party[100];
        int n;
        scanf("%d",&n);
        getchar();
        for(int i = 0; i<n; i++)
        {
            gets(name);
            gets(party);
            mp[name] = make_pair(party,0);
        }
        int m;
        scanf("%d",&m);
        gets(name);
        for(int i = 0; i<m; i++)
        {
            gets(name);
            if(mp.find(name)!=mp.end())
            {
                mp[name].second++;
            }
        }
        map<string , pair<string,int> > :: iterator it,it2;
        it = mp.begin();
        string winer = it->second.first;
        int mx = it->second.second;
        it++;

        it2=mp.begin();
        bool flag = true;
       // cout<<mx<<endl;
       // if(it2->second.second != it->second.second) {flag=true;cout<<it->second.second<<' '<<it2->second.second<<endl;}
        for(; it!=mp.end(); it++,it2++)
        {
           // cout<<it->second.second<<endl;
            if(it->second.second >= mx)
            {

                winer = it->second.first;
                if(mx==it->second.second) flag = false;
                mx = it->second.second;
                // cout<<mx<<endl;
            }
           // if(it->second.second != (it2)->second.second) {flag=true;cout<<"ontu\n";}
        }
        if(flag)
        {
            puts(winer.c_str());
        }
        else
        {
            puts("tie");
        }
        gets(name);

    }
    return 0;
}
