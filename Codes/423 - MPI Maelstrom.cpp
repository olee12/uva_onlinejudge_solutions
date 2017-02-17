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
#define M 105
#define sf scanf
#define pf printf
int graph[M][M];
//template <class T>
#define INF 1000000000
int main()
{
    int n;
    int xx;
    int w;
    char str[10];
    while(sf("%d",&n)==1)
    {
        xx=1;
        graph[1][1]=0;
        for(int i = 2; i<=n; i++)
        {
            for(int j = 1; j<=xx; j++)
            {
                scanf("%s",&str);
                if(*str=='x') w = INF;
                else
                    w = atoi(str);
                graph[i][j] = w;
                graph[j][i] = w;
            }
            xx++;
            graph[i][xx]=0;
        }

        for(int k = 1; k<=n; k++)
            for(int i = 1; i<=n; i++)
                for(int j = 1; j<=n; j++)
                    graph[i][j] = min(graph[i][j] , graph[i][k]+ graph[k][j]);
        int mn = 0;
        for(int i= 1; i<=n; i++) if( graph[1][i]!=INF && graph[1][i]>mn) mn = graph[1][i];
        pf("%d\n",mn);

    }
    return 0;

}
