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
int graph[M][M];
int x_axis[]= {1,-1,0,0};
int y_axis[]= {0,0,1,-1};
int cnt = 0;
int n;
inline bool valid(int i,int j)
{
    if(i<=n && i>=1 && j>=1 && j<=n) return 1;
    return 0;
}
int val;
void dfs(int i,int j)
{
    // cout<<i<<' '<<j<<endl;
    int tx,ty;
    cnt++;
    graph[i][j]=-1;
    for(int k = 0; k<4; k++)
    {
        tx = i+x_axis[k];
        ty = j+y_axis[k];
        if(valid(tx,ty))
            if(graph[tx][ty]==val) dfs(tx,ty);
    }
}
int main()
{

    int x,y;

    char str[1000];
    bool f = false;
    while(sf("%d",&n)==1 && n)
    {
        f = true;
        getchar();
        for(int i= 1; i<=n; i++)
            for(int j = 1; j<=n; j++) graph[i][j]=n;
        for(int i = 1; i<n; i++)
        {
            gets(str);
            stringstream ss(str);
            while(ss>>x>>y) graph[x][y]=i;
        }
        for(int i= 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                // cout<<' '<<graph[i][j]<<' ';
                cnt = 0;
                if(graph[i][j]>0)
                {
                    val = graph[i][j];
                    dfs(i,j);
                    if(cnt!=n) f=false;
                }
            }
            // puts("");
        }
        if(f) puts("good");
        else puts("wrong");
    }
    return 0;
}
