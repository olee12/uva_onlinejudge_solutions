#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<queue>
#include<stack>
#include<iostream>
#include<cstring>
#include<limits.h>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<bool> vb;
#define     MI      610
#define     MF      110
#define     sz(a)   (int)a.size()
#define     all(a)  a.begin(),a.end()
#define     pb      push_back
#define     mp      make_pair
#define     mem(a)  mem(a,0,sizeof(a))
#define     fr      first
#define     sc      second
#define     VII     vi :: iterator
#define     VIII    vii :: iterator
#define     SII     si :: iterator
#define     INF     (1<<31)-1
#define     MIVI    map<int,vi> :: iterator
struct node
{
    int u,w;
    node() {}
    node(int a,int b): u(a),w(b) {}
    bool operator < (const node& p) const
    {
        return w > p.w;
    }
};
int fire[MF];
int main()
{
    //cout<<INF<<endl;
    //freopen("input.txt","r",stdin);
    int test;
    scanf("%d",&test);
    while(test--)
    {
        char ara[200];
        int f,city;
        scanf("%d %d",&f,&city);
        for(int i= 0; i<f; i++) scanf("%d",&fire[i]);
        vii graph[MI];
        vii cost[MI];
        getchar();
        while(gets(ara))
        {

            if(strlen(ara)==0) break;
            int u,v,w;
            sscanf(ara,"%d %d %d",&u,&v,&w);
            // printf("%d %d\n",u,v);
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
        }
        vi tmp_dist(city+5,INF);
        vb visited(city+5,false);
        priority_queue<node> fst;
        for(int i = 0; i<f; i++)
        {
            tmp_dist[fire[i]] = 0;
            fst.push(node(fire[i],0));
        }
        int pos = 1;
        int mn=INF;
        for(int k = 1; k<=city; k++)
        {
            if(tmp_dist[k]==0) continue;
            priority_queue<node> Q;
            Q= fst;
            vi dist(city+5,INF);

            dist = tmp_dist;
            dist[k] = 0;
            Q.push(node(k,0));
            node tmp;
            while(Q.empty()==false)
            {
                tmp = Q.top();
                Q.pop();
                int u = tmp.u;
                //visited[u] = true;
                VIII it;
                for(int i = 0; i<sz(graph[u]); i++)
                {

                    int v = graph[u][i].fr;
                    // if(visited[v]==true) continue;
                    int u_to_v = graph[u][i].second;

                    if(dist[v] > dist[u] + u_to_v)
                    {
                        dist[v] = dist[u] + u_to_v;
                        Q.push(node(v,dist[v]));
                    }
                }
            }
            int mx = 0;
            for(int i = 1; i<=city; i++)
            {

                //  printf(" %d ",dist[i]);
                mx = max(mx,dist[i]);
            }
            //puts("");
            if(mn>mx)
            {
                pos = k;
                mn = mx;
            }
        }
        printf("%d\n",pos);
        if(test) puts("");
    }
    return 0;
}
