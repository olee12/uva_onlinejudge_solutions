#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
char str[200];
int ind = 0;
bool graph[27][27];
bool taken[50];
vector<int> res;
int cnt;
char input[50];
bool cheak(int ch)
{
    for(int i = 0;i<res.size()-1;i++)
        if(graph[ch][res[i]]==true) return false;
    return true;
}
void call(int start)
{
    if(res.size()==cnt){
        ///do something
        for(int i = 0;i<cnt;i++)
        {
            printf("%c",res[i]+'a');

        }
        puts("");
        return;
    }
    for(int i = 0;i<cnt;i++)
    {
        if(taken[i]==false )
        {
            taken[i]=true;
            res.push_back(input[i]-'a');
            if(cheak(input[i]-'a'))
            call(start+1);
            taken[i]=false;
            res.pop_back();
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    char ara[50];
    int u,v;
    char cont[200];
    bool flag = false;
    while(gets(ara))
    {
        if(flag) puts("");flag = true;
        cnt = 0;
        int len = strlen(ara);
        for(int i = 0; i<len; i+=2)
        {
            input[cnt++]=ara[i];
        }
        input[cnt]='\0';
        sort(input,input+cnt);
        gets(cont);
        memset(taken,false,sizeof taken);
        len = strlen(cont);
        for(int i = 0; i<len; i+=4)
        {
            u = cont[i]-'a';
            ///v y x v
            v = cont[i+2]-'a';
            graph[u][v] = true;
        }
        res.clear();
        call(0);
        for(int i = 0;i<27;i++) memset(graph[i],0,sizeof(graph[i]));



    }
    return 0;
}

