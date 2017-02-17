#include<cstdio>
#include<iostream>
#include<iterator>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
vector<int> graph[200];
char res[200];
bool colour[200];
int ind;
void dfs(int u)
{
    colour[u]=true;
    for(int i=  0; i<(int)graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(colour[v]==false)
            dfs(v);
    }
    res[ind--] = u+'A';
}
int main()
{
    //freopen("input.txt","r",stdin);
    set<int> input;
    string ara;
    vector<string> lst;
    int cnt=-1;
    while(cin>>ara)
    {
        if(ara=="#") break;
        lst.push_back(string(ara));
        for(int i = 0;i< ara.size(); i++)
            input.insert(ara[i]-'A');
    }
    cnt = (int) lst.size();
    for(int i = 0; i<cnt; i++)
        for(int j = i+1; j<cnt; j++)
        {
            int u = lst[i][0]-'A';
            int v = lst[j][0]-'A';
            if(u!=v)
            {
                graph[u].push_back(v);
            }
        }
    ind = input.size();
    res[ind]='\0';
    ind--;

    for(int i = 0; i<200; i++) colour[i]=false;
    set<int> :: iterator it;
    for(it=input.begin();it!=input.end();it++)
    {
        if(colour[*it]==false) dfs(*it);
    }
    puts(res);
    for(int i = 0;i<200;i++) graph[i].clear();
    return 0;
}
