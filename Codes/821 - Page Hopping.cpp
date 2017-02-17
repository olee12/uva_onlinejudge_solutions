#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<iterator>
#include<set>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<sstream>
#include<cctype>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef set<int> si;
typedef map<int,int > mii;
#define mp make_pair
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 120000
#define sf scanf
#define pf printf
set<int> s;
vi graph[110];
int bfs(int s,int t)
{
    int dist[110];
    memset(dist,-1,sizeof dist);
    queue<int> Q;
    Q.push(s);
    dist[s]=0;
    while(Q.empty()==false)
    {
        int u = Q.front();
        Q.pop();
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            int v = graph[u][i];
            if(dist[v]!=-1) continue;
            dist[v]=dist[u]+1;
            Q.push(v);
            if(v==t) return dist[t];
        }
    }
}
int main()
{
    int u,v;
    int cas = 1;
    while(sf("%d %d",&u,&v)==2)
    {

        if(u==0 && v==0) return 0;
        s.insert(u);
        s.insert(v);
        graph[u].push_back(v);
        while(sf("%d %d",&u,&v))
        {
            if(u==0 && v==0) break;
            graph[u].push_back(v);
            s.insert(u);
            s.insert(v);
        }
        int sum=0,cnt=0;
        set<int> :: iterator it = s.begin();
        for(; it!=s.end(); it++)
        {
            set<int> :: iterator it2 = s.begin();
            for(; it2!=s.end(); it2++)
            {
                if(*it==*it2) continue;
                sum+=bfs(*it,*it2);
                cnt++;
            }
        }
        s.clear();
        for(int i = 0;i<=105;i++) graph[i].clear();
     //   cout<<cnt<<endl;
        pf("Case %d: average length between pages = %.3lf clicks\n",cas++,(double)sum/double(cnt));

    }
    return 0;
}
