#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<iterator>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define M 30
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
int visited[30];
int dist[30];
double value[30];
template < class T >
void mem(T* a,T n,T val)
{
    for(int i = 0; i<n; i++)
        a[i]=val;
}
void bfs(int start,vi graph[])
{
    queue<int> Q;
    Q.push(start);
    dist[start] = 0;
    while(Q.empty()==false)
    {
        int u = Q.front();
        Q.pop();
        int szz = sz(graph[u]);
        for(int i = 0; i<szz; i++)
        {
            int v = graph[u][i];

            if(dist[v] > -1) continue;
            //cout<<v<<endl;
            dist[v]=dist[u]+5;
            Q.push(v);
        }
    }
    return;
}
int main()
{
    #ifdef OLEE
   // freopen("input.txt","r",stdin);
    #endif // OLEE
    int N;
    char tmp[50];
    char ch;
    while(scanf("%d",&N)==1)
    {
        vi graph[M];

        for(int i = 0; i<N; i++)
        {
            double w;
            scanf(" %c %lf %s",&ch,&w,tmp);
            value[ch-'A'] = w;
            int l = strlen(tmp);
            for(int j = 0; j<l; j++)
            {
                int v = (isalpha(tmp[j])?tmp[j]-'A':26);
              //  cout<<v<<endl;
                graph[ch-'A'].pb(v);
                graph[v].pb(ch-'A');
            }

        }
        mem(dist,M,-1);
        bfs(26,graph);
        double mx=-50.00; int pos;
        double val;
        for(int i = 0; i<26; i++)
        {
            if(dist[i]==-1) continue;
            val = value[i] - (value[i] * ((dist[i]-5.00)/100.00));

            if(val>mx)
            {
               // cout<<val<<endl;
                mx = val;
                pos = i;
            }
        }
       // cout<<dist['F'-'A']<<endl;
        printf("Import from %c\n",pos+'A');
    }
    return 0;
}
