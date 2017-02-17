#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int indegree[102]= {0};
int take[102][102];
int taken[102]= {0},list[102]= {0};
/* when take[a][b] = 1, that means a must come before b
 indegree[i] = number of items that that must come before i
 when taken[i] = 1, means we already have taken ith item*/
int main()
{
    int n,m;
    int i,j,k,l;
    int a,b;
    while(scanf("%d %d",&n,&m)==2 && (n!=0 || m!=0 ))
    {
        memset(take,0,sizeof(take));
        memset(indegree,0,n+5);
        memset(list,0,n+5);
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            take[a][b]=1;
            indegree[b]++;

        }
        // for(i=1; i<=n; i++) cout<<indegree[i]<<' ';
        //cout<<endl;
        // when take[a][b] = 1, that means a must come before b
// indegree[i] = number of items that that must come before i
// when taken[i] = 1, means we already have taken ith item
        /*int invalid = 0;
        int x=1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++) {
                if( !indegree[j] && !taken[j] )
                {
                    taken[j] = 1;
                    list[x++] = j;
                    cout<<i<<' '<<j<<endl;
                    // in this step we are taking item j
                    // we'd update the indegree[k] of items that depended on j
                    for(k=1; k<=n; k++)
                        if( !taken[k] && take[j][k] )
                        {
                            indegree[k]--;
                            cout<<"in :"<<j<<' '<<k<<endl;
                            //cout<<taken
                        }
                    break;
                }
            }
            if( j == n +2)
            {
                invalid = 1;
                break;
            }
        }

        if( invalid ) printf("There is no solution\n");
         else for(i=1; i<=n; i++) printf("%d\n", list[i] );*/


        int x=0;
        for(i=1; i<=n; i++)
        {
            if(indegree[i]==0)
            {
                list[x++]=i;
                taken[i]=1;
            }
        }
        for(i=0; i<x; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(take[list[i]][j])
                {
                    taken[j]=1;
                    indegree[j]--;
                    if(indegree[j]==0) list[x++]=j;
                }

            }
        }
        printf("%d",list[0]);
        for(i=1; i<x; i++) printf(" %d",list[i]);
        printf("\n");


    }
    return 0;

}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>



#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ size()
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod(a) (a>0?a:-a)

using namespace std;



vector<int> graph[101];
int weight[101];
vector<int> zeroWeighted;


int main()
{
    int n, m;
    int p, q;
    while(scanf("%d %d", &n, &m) == 2 && (n!=0 || m!=0))
    {
        loop(i, 101)
        {
            graph[i].clear();
            weight[i] = 0;
            zeroWeighted.clear();
        }
        loop(i, m)
        {
            getint(p); getint(q);
            graph[p].pb(q);
            weight[q]++;
        }

        for(int i=1; i<=n; i++)
        {
            if(weight[i] == 0)
            {
                zeroWeighted.pb(i);
            }
        }
        loop(i, zeroWeighted.SZ)
        {
            p = zeroWeighted[i];
            loop(j, graph[p].SZ)
            {
                q = graph[p][j];
                weight[q]--;
                if(weight[q] == 0)
                {
                    zeroWeighted.pb(q);
                }
            }
        }

        printf("%d", zeroWeighted[0]);
        FOR(i, 1, zeroWeighted.SZ)
        {
            printf(" %d", zeroWeighted[i]);
        }
        printf("\n");
    }

    return 0;
}
*/
