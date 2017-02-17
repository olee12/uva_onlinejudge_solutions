#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set<int> si;
#define pb push_back
#define mp make_pair
#define sz(a) (int) a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define M 20010
#define VII vi :: iterator
#define SII si :: iterator
bool taken[M];
vi graph[M];
int bfs(int start)
{
    int colour[M] = {0};
    queue<int> Q;
    Q.push(start);
    colour[start] = 1;
    taken[start] = true;
    vi vamp,lican;
    while(Q.empty()==false)
    {
        int u = Q.front();
        Q.pop();

        for(int i = 0; i<sz(graph[u]); i++)
        {
            int v = graph[u][i];
            if(taken[v]==true) continue;

            taken[v] = true;
            if(colour[u]==1)
            {
                lican.pb(v);
                colour[v]=2;
            }
            else
            {
                vamp.pb(v);
                colour[v]=1;
            }
            Q.push(v);
        }
    }
    return max(sz(lican),sz(vamp));

}
int main()
{
    freopen("input.txt","r",stdin);
    int test;
    int u,v,n;
    scanf("%d",&test);int cas = 1;
    while(test--)
    {

        mem(taken,false);
        si s;
        scanf("%d",&n);
        for(int i = 0; i<n; i++)
        {
            scanf("%d %d",&u,&v);
            cout<<u<<v;
            s.insert(u);
            s.insert(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        SII it ;
        int res = 0;
        for(it = s.begin(); it!=s.end(); it++)
        {
            cout<<*it<<endl;
            if(taken[*it]==false) {cout<<res<<endl;res += bfs(*it);}
        }
        printf("Case %d: %d\n",cas++,res);
        for(int i = 0;i<M;i++) graph[i].clear();
    }
}
