#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<int> res;
bool taken[20];
string fix="00000000000000000";
int ara[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int n,r;
vector<string> fin;
void call(int start)
{
    if(res.size()==r)
    {
        ///do something
        string s(n,'0');
        for(int i = 0; i<r; i++)
        {

            s[res[i]]='1';
           // cout<<res[i];
        }
       // cout<<s<<endl;
        // for(int i = 0;i<n;i++) printf("%c",s[i]);
        fin.push_back(s);
        //puts("");
    }
    for(int i = start; i<n; i++)
    {
        if(taken[i]==false)
        {
            taken[i]=true;
            res.push_back(ara[i]);
            call(i+1);
            taken[i]=false;
            res.pop_back();
        }
    }
}
int main()
{

    int test;
    bool flag = false;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&r);
        memset(taken,false,sizeof taken);
        res.clear();
        call(0);
        //cout<<fin.size();
        if(flag) puts("");flag = true;
        for(int i = fin.size()-1;i>=0;i--) cout<<fin[i]<<endl;
        fin.clear();
    }
    return 0;

}
