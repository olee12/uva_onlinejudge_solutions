#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define M 1005
#define sz(a) (int)a.size()
#define VII   vector<int> :: iterator
#define SII set<int> :: iterator
#define fr first
#define sc second
#define iter(a,b,u) for(a = b[u].begin();a!=b[u].end();a++)

#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
vector<int >graph[M];
vector<int >g2[M];
int colour[M];
int path[M];
int ind;
int ans;
map<string,int> str_num;
void dfs1(int u)
{
    colour[u]=1;
    VII it;
    for(it = graph[u].begin(); it!=graph[u].end(); it++)
    {
        if(colour[*it]==0) dfs1(*it);
    }
    path[ind++]=u;
}
void dfs2(int u)
{

    colour[u]=1;
    VII it;
    for(it=g2[u].begin(); it!=g2[u].end(); it++)
    {
        if(colour[*it]==0)
        {
            dfs2(*it);
        }
    }
}
/*void display1()
{
   map<int,set<int> > ::iterator it;
   for(it = graph.begin();it!=graph.end();it++){
        cout<<it->fr<<" : ";
        SII i;
        for(i = it->sc.begin();i!=it->sc.end();i++){
            cout<<' '<<*i;
        }
        cout<<endl;
   }
}*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif // ONLINE_JUDGE
    int p,t;
    char s1[100],s2[100],name[100];
    int x = 1;
    while(scanf("%d %d",&p,&t))
    {
        if(p==0 && t==0) return 0;
        for(int i = 1; i<=p; i++)
        {
            graph[i].clear();
            g2[i].clear();
        }
        str_num.clear();
        x = 1;
        getchar();
        for(int i = 0; i<p; i++)
        {
            gets(name);

            if(str_num.find(string(name))==str_num.end())
            {
                str_num[name]=x++;
                //  puts(name);
            }

        }
        // getchar();
        for(int i = 0; i<t; i++)
        {
            gets(s1);
            // puts(s1);
            gets(s2);
            // puts(s2);
            int u = str_num[string(s1)];
            int v = str_num[string(s2)];
            //cout<<u<<' '<<v<<endl;

            graph[u].pb(v);
            g2[v].pb(u);
        }
        //cout<<x<<endl;
        // puts("");
        // display1();
        //puts("");
        mem(colour,0);
        mem(path,0);
        ind=0;
        for(int i = 1; i <=p; i++)
        {
            if(colour[i]==0)
            {
                // cout<<i<<endl;
                dfs1(i);
            }
        }
        mem(colour,0);
        ans = 0;
        //  cout<<ind<<endl;
        for(int i = ind-1; i>=0; i--)
        {

            if(colour[path[i]]==0)
            {
                //cout<<path[i]<<endl;
                ans++;
                dfs2(path[i]);
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
