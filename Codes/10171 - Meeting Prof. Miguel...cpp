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
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii,int> iii;
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
#define M 200
#define sf scanf
#define pf printf
#define INF 2147483645
int dist1[M];
int dist2[M];
void bfs(int s,int dist[],viii graph[],int line)
{
    memset(dist,-1,M);
    queue<int> Q;
    Q.push(s);
    int u,v;
    int cst;
    int l;
    dist[s]=0;
    while(Q.empty()==false)
    {
        u = Q.front();
        Q.pop();
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            v = graph[u][i].fr.fr;
            cst = graph[u][i].fr.sc;
            l = graph[u][i].sc;
            //  cout<<cst<<endl;
            if(l!=line) continue;
            if(dist[v]!=-1) continue;
            dist[v]=dist[u]+cst;
            Q.push(v);
        }
    }
    // for(int i = 0;i<=5;i++) cout<<' '<<dist[i];
    //  puts("");
}
int main()
{
   // freopen("input.txt","r",stdin);
    int n;
    char inp1,inp2,inp3,inp4;
    int w;
    char str[50];
    int line;
    int xx;
    int u,v;
    while(scanf("%d",&n)==1 && n)
    {
        xx=1;
        map<char,int> name;
        map<int,char> res;
        viii graph[M];
        for(int i = 0; i<n; i++)
        {
            scanf(" %c %c %c %c %d",&inp1,&inp2,&inp3,&inp4,&w);

            if(inp1=='Y') line = 1;
            else line = 0;
            if(name.find(inp3)==name.end())
            {
                name[inp3]=xx;
                res[xx]=inp3;
                xx++;
            }
            if(name.find(inp4)==name.end())
            {
                name[inp4]=xx;
                res[xx]=inp4;
                xx++;
            }
            u = name[inp3];
            v = name[inp4];
            if(inp2=='U')
                graph[u].pb(mp(mp(v,w),line));
            else
            {
                graph[u].pb(mp(mp(v,w),line));
                graph[v].pb(mp(mp(u,w),line));

            }
        }
        scanf(" %c %c",&inp1,&inp2);
        // cout<<inp1<<' '<<inp2<<endl;
        u = name[inp1];
        v = name[inp2];
        int ara[250];
        bfs(u,ara,graph,1);
        for(int i = 1; i<xx; i++) dist1[i]=ara[i];
        bfs(v,ara,graph,0);
        for(int i = 1; i<xx; i++) dist2[i]=ara[i];
        int mn = INF;
        bool f;
        set<char> pos;
        for(int i = 1; i<xx; i++)
        {
            //  cout<<dist1[i]<<' '<<dist2[i]<<endl;
            if(dist1[i]!=-1 && dist2[i]!=-1)
            {
                if(mn>(dist1[i]+dist2[i]))
                {
                    mn = dist1[i]+dist2[i];

                }
            }
        }
        for(int i = 1;i<xx;i++) if(dist1[i]+dist2[i] == mn) pos.insert(res[i]);
        if(mn!=INF)
        {
            printf("%d ",mn);
            f=false;
           set<char> :: iterator it = pos.begin();
           for(;it!=pos.end();it++)
           {
               if(f) pf(" ");f=true;
               pf("%c",*it);
           }
            puts("");
        }
        else printf("You will never meet.\n");



    }
    return 0;
}
