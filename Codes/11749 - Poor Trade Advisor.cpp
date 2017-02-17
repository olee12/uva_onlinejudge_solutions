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
#define M 510
#define sn scanf
#define pf printf
vii graph[M];
int cnt;
bool visited[M];
int ppt=0;
int dfs(int u)
{
    if(visited[u]) return 0;
    int res = 1;
    visited[u]=1;

    int zz = sz(graph[u]);
    for(int i= 0; i<zz; i++)
    {
        int v = graph[u][i].fr;
        int w = graph[u][i].sc;
        if( w==ppt)
        {
            res+=dfs(v);
        }
    }
    return res;
}
int main()
{

    int n,m;
    while(sn("%d %d",&n,&m))
    {
        ppt=0;
        if(n==0 && m==0) return 0;
        for(int i = 0; i<m; i++)
        {
            int u,v,w;
            sn("%d %d %d",&u,&v,&w);
            graph[u].pb(mp(v,w));
            graph[v].pb(mp(u,w));
            if(ppt<w) ppt = w;
        }
        int mx = 0;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 0; j<=n+2; j++) visited[j]=false;
            cnt=0;
            //if(visited[i]==false)
            //
            cnt = dfs(i);
            if(cnt>mx)  mx = cnt;

            // }
        }
        for(int i= 0; i<M; i++)
        {
            graph[i].clear();
            // visited[i]=0;
        }
        pf("%d\n",mx);
    }
    return 0;
}

/*
using namespace std;

int const MAXN = 550;
int const SMALL_NUM = 1 << 31;

int high = SMALL_NUM;
int matrix[MAXN][MAXN];
bool visited[MAXN];

int solve(int index, int n)
{
    if (visited[index])
        return 0;
    visited[index] = true;
    int count = 1;
    for (int i = 0; i < n; ++i)
        if (matrix[index][i] == high)
            count += solve(i, n);
    return count;
}

int main(int argc, char **args)
{
    for (int n, e, i, a, b, c, result; scanf("%d%d", &n, &e); high = SMALL_NUM)
    {
        if (n == 0 && e == 0)
            break;
        memset(visited, false, sizeof(visited));
        for (i = 0; i < n; ++i)
            fill(matrix[i], matrix[i] + n, SMALL_NUM);
        for (i = 0; i < e; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            high = max(high, c);
            matrix[a - 1][b - 1] = max(matrix[a - 1][b - 1], c);
            matrix[b - 1][a - 1] = matrix[a - 1][b - 1];
        }
        result = solve(0, n);
        for (i = 1; i < n; ++i)
        {
            memset(visited, false, sizeof(visited));
            result = max(result, solve(i, n));
        }
        printf("%d\n", result);
    }
    return 0;
}

*/
