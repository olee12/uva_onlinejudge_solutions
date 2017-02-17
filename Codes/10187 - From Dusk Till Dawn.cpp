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
#include<sstream>
#include<stack>
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
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define VII vi :: iterator
#define SII si :: iterator
#define MII mii :: iterator
#define fr first
#define sc second
#define M 105
#define sf scanf
#define pf printf
#define INF 2061109567
struct node
{
    int w,u,arrivel;
    node() {}
    node(int _u,int _w, int a): u(_u),w(_w),arrivel(a) {}
    bool operator < (const node& p) const
    {
        if(p.w==w)
        return p.arrivel< arrivel;
        return p.w<w;
    }
};
struct iiii
{
    int v,leave,tem;
    iiii() {}
    iiii(int _v,int _a,int _b) : v(_v), leave(_a),tem(_b) {}
};
vector<iiii> graph[M];
map<string,int> st_in;
int dist[M][2];
bool visited[M];
void init()
{
    for(int i =  0; i<M; i++)
    {
        dist[i][0]=INF;
        dist[i][1]=INF;
        visited[i]=0;
    }
}
void dijkstra(int s,int t)
{
    cout<<s<<' '<<t<<endl;
    init();
    priority_queue<node> Q;
    Q.push(node(s,0,18));
    dist[s][0]=0;
    dist[s][1]=18;
               int u,v,ar,tm,go;
    node tmp;
    int res;
    while(Q.empty()==false)
    {
        tmp = Q.top();
        Q.pop();
        u = tmp.u;
        int zz = sz(graph[u]);
        for(int i = 0; i<zz; i++)
        {
            v = graph[u][i].v;
            int de = graph[u][i].leave;

            res = dist[u][0] + (dist[u][1]>de);
            go = graph[u][i].tem;
            if(res<dist[v][0] || (res==dist[v][0] && go < dist[v][1] ))
            {

                dist[v][0]=res;
                dist[v][1]=go;
                Q.push(node(v,dist[v][0],dist[v][1]));

            }

        }
    }

}
int main()
{
    int test;
    int m;
    char str1[50],str2[50];
    sf("%d",&test);
    int u,v,xx,t,h;
    while(test--)
    {
        xx=1;
        sf("%d ",&m);
        for(int i = 0; i<m; i++)
        {
            sf("%s %s %d %d",str1,str2,&t,&h);
            if(st_in.find(string(str1))==st_in.end()) st_in[str1]=xx++;
            if(st_in.find(string(str2))==st_in.end()) st_in[str2]=xx++;
            u = st_in[str1];
            v = st_in[str2];
            h+=t+=(t<=6)?24:0;
            cout<<u<<' '<<v<<' '<<t<<' '<<h<<endl;
            if(t>=18 && h<=30);
            graph[u].pb(iiii(v,t,h));
        }
        sf("%s %s",str1,str2);
        dijkstra(st_in[str1],st_in[str2]);
        cout<<dist[st_in[str2]][0]<<endl;

    }
}
